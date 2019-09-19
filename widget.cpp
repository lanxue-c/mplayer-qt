#include "widget.h"
#include "ui_widget.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>
#include <QString>
#include <string.h>
#include <time.h>
#include <QPixmap>
#include "fun.h"
#include "form.h"
#include <qnamespace.h>
#include <QMouseEvent>
#include <QDebug>
#include <deque>

extern struct MyTyep{
   int fifo_fd;
   int fd[2];
}Mytype;

int Widget::speed = 0;
int Widget::this_time = 0;
int Widget::length_time = 0;

bool state = false;
bool state_bar = true;
bool only_song = false;
bool state_time_close = true;
int time_close_old =  0;
int song_numb = 0;
int song_new = 0;
int pattern = 2;
int lrc_num = 0;
int mun_t = 0;
LRC *lrc_hand = NULL;
Widget *this_p = NULL;
vector<char *> song_list;
deque<int> song_list_old;
vector<int> arr_t;

void *deal_fun1(void *);
void *deal_fun2(void *);
void player_mode(Ui::Widget *ui);
void lrc_handle(Ui::Widget *ui);

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->move(500,130);
    ui->widget->hide();
    QTimer::singleShot(2300,NULL,[=](){
        ui->label_13->hide();
    });
    this_p = this;
    voic_old2 = vol = 60;
    voic_old1 = voice_num = 0;
    play_state = true;
    song_new = 0;
    time_close = -1;
    ui->pushButton_10->setVisible(false);
    ui->pushButton_11->setVisible(false);
    ui->pushButton_18->setVisible(false);
    ui->pushButton_19->setVisible(false);
    ui->pushButton_20->setVisible(false);
    ui->label_17->setVisible(false);
    ui->label_18->setVisible(false);
    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1,NULL,deal_fun1,(void *)ui);
    pthread_create(&tid2,NULL,deal_fun2,NULL);
    pthread_detach(tid1);
    pthread_detach(tid2);
    char buf[64] = "";
    sprintf(buf,"%s %d 1","volume",vol);
    printf("%s",buf);
    write(Mytype.fifo_fd,buf,strlen(buf));
    Widget::mydir();
    write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
    Widget::lrcform = new LrcForm(this);
    Widget::lrcform->hide();
    timer_close = new QTimer(this);
    miniform = new MiniForm(this);
    connect(miniform,&MiniForm::suspend,[=](){
        Widget::on_pushButton_2_clicked();
    });
    connect(miniform,&MiniForm::last_song,[=](){
       Widget::on_pushButton_clicked();
    });
    connect(miniform,&MiniForm::next_song,[=](){
       Widget::on_pushButton_3_clicked();
    });
    connect(miniform,&MiniForm::quitout,[=](){
        this->show();
        miniform->hide();
    });
    connect(miniform,&MiniForm::mute,[=](){
        Widget::on_pushButton_5_clicked();
    });
    connect(miniform,&MiniForm::shoutt,[=](){
        Widget::on_pushButton_9_clicked();
    });
    connect(miniform,&MiniForm::minimize,[=](){
        miniform->showMinimized();
    });
    connect(miniform,&MiniForm::value_num,[=](int num){
        vol = num+5;
        Widget::on_pushButton_6_clicked();
    });
    connect(miniform,&MiniForm::lrc_control,[=](){
        Widget::on_pushButton_15_clicked();
    });

    connect(timer_close,&QTimer::timeout,[=](){
        if(time_close == 0)
            Widget::on_pushButton_9_clicked();
        time_close--;
        ui->label_18->setText(QString::number(time_close)+QString("s"));
    });
}

Widget::~Widget()
{
    delete ui;
}

void *deal_fun1(void *arg)//接收消息
{
    Ui::Widget *ui = (Ui::Widget *)arg;
    while(1)
    {
        char buf[128] = "";
        read(Mytype.fd[0],buf,sizeof(buf));
        //printf("buf = %s\n",buf);
        char cmd[128] = "";
        float num = 0.0f;
        sscanf(buf,"%[^=]=%f",cmd,&num);
        if(strcmp(cmd,"ANS_PERCENT_POSITION") == 0)
        {
            Widget::speed =  (int)(num+0.5);
           //printf("\r已播放%05.2f%%\t",num);this->setWindowFlags(Qt::FramelessWindowHint);
            if(state_bar)
                   ui->horizontalSlider->setValue(Widget::speed);
        }
        else if(strcmp(cmd,"ANS_TIME_POSITION") == 0)
        {
            Widget::this_time = (int)(num*10);
            char buf[64] = "";
            sprintf(buf,"%02d:%02d.%d",Widget::this_time/10/60,Widget::this_time/10%60,Widget::this_time%10);
            ui->label_2->setText(QString(buf));
            if(Widget::this_time >= Widget::length_time*10-10 && Widget::this_time > 10)
            {
                state = false;
                ui->pushButton_2->setIcon(QIcon(":/img/1.png"));
                player_mode(ui);
            }
            if(lrc_hand != NULL)
            {
                lrc_num = 0;
                while(myprint(lrc_hand,lrc_num)->next != NULL)
                {
                    int lrc_time1 = myprint(lrc_hand,lrc_num)->time_min*600+myprint(lrc_hand,lrc_num)->time_sec*10+myprint(lrc_hand,lrc_num)->time_ms/10;
                    int lrc_time2 = myprint(lrc_hand,lrc_num+1)->time_min*600+myprint(lrc_hand,lrc_num+1)->time_sec*10+myprint(lrc_hand,lrc_num+1)->time_ms/10;
                    if(Widget::this_time >= lrc_time1 && Widget::this_time <= lrc_time2)
                    {
                        ui->label_4->setText(QString(myprint(lrc_hand,lrc_num)->buf));
                        ui->widget->lrc_vice(lrc_hand,lrc_num);
                        emit this_p->song_lrc(myprint(lrc_hand,lrc_num)->buf,myprint(lrc_hand,lrc_num+1)->buf);
                        break;
                    }
                    lrc_num++;
                }
                if(myprint(lrc_hand,lrc_num) != NULL && myprint(lrc_hand,lrc_num)->next == NULL)
                {
                    ui->label_4->setText(QString(myprint(lrc_hand,lrc_num)->buf));
                    ui->widget->lrc_vice(lrc_hand,lrc_num);
                    emit this_p->song_lrc(myprint(lrc_hand,lrc_num)->buf,(char *)"");
                }
            }
            //else
                //printf("已播放%d\t",Widget::this_time);
        }
        else if(strcmp(cmd,"ANS_LENGTH") == 0)
        {
            Widget::length_time = (int)(num+0.5);
            //printf("播放总时间 %d", Widget::length_time);
            char buf[64] = "";
            sprintf(buf,"%02d:%02d",Widget::length_time/60,Widget::length_time%60);
            ui->label_3->setText(QString(buf));
        }
        fflush(stdout);
    }
}

void *deal_fun2(void *)//发送信息
{
    while(1)
    {
        while(state)
        {
            usleep(5*1000);
            write(Mytype.fifo_fd,"get_percent_pos\n",strlen("get_percent_pos\n"));//获得百分比
            usleep(5*1000);
            write(Mytype.fifo_fd,"get_time_pos\n",strlen("get_time_pos\n"));//获得时间
            usleep(5*1000);
            write(Mytype.fifo_fd,"get_time_length\n",strlen("get_time_length\n"));
         }
        usleep(100);
    }
}

void Widget::on_pushButton_2_clicked()//播放暂停
{
    if(state)
    {
        state = false;
        usleep(1000*50);
        ui->pushButton_2->setIcon(QIcon(":/img/1.png"));
        write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
        voic_old1 = Widget::voice_num;
        voic_old2 = Widget::vol;
    }
    else if(!state)
    {
        write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
        ui->pushButton_2->setIcon(QIcon(":/img/4.png"));
        state = true;
        if(play_state)
        {
            char buf[256] = "";
            sprintf(buf,"%s \"../mplayer/song/%s\"\n","loadfile",song_list[0]);
            printf("%s---\n",buf);
            write(Mytype.fifo_fd,buf,strlen(buf));
            play_state = false;
            song_list_old.push_front(song_new);
            usleep(1000);
            lrc_handle(ui);
        }
        if(only_song)
        {
            char buf[256] = "";
            sprintf(buf,"%s \"../mplayer/song/%s\"\n","loadfile",song_list[song_new]);
            write(Mytype.fifo_fd,buf,strlen(buf));
            usleep(1000);
            song_list_old.push_front(song_new);
            only_song = false;
            lrc_handle(ui);
        }
        if(voic_old1 != Widget::voice_num)
        {
            char buf[256] = "";
            sprintf(buf,"%s %d\n","mute",Widget::voice_num);
            write(Mytype.fifo_fd,buf,strlen(buf));
            voic_old1 = Widget::voice_num;
        }
        if(voic_old2 != Widget::vol)
        {
            char buf[64] = "";
            sprintf(buf,"%s %d 1\n","volume",vol);
            printf("%s",buf);
            write(Mytype.fifo_fd,buf,strlen(buf));
            voic_old2 = Widget::vol;
        }
    }
    //usleep(1000*100);
    //time->start(500);
}

void Widget::on_pushButton_clicked()//上一首
{
    if(pattern != 3)
    {
        if(song_new <= 0)
            song_new = song_numb-1;
        else
            song_new--;
    }
    else
    {
        if(mun_t <= 0)
            mun_t = song_list.size() -1;
        else
            mun_t--;
        song_new = arr_t[mun_t];
    }
    if(voic_old1 != Widget::voice_num)
    {
        char buf[256] = "";
        sprintf(buf,"%s %d\n","mute",Widget::voice_num);
        write(Mytype.fifo_fd,buf,strlen(buf));
        voic_old1 = Widget::voice_num;
    }
    if(voic_old2 != Widget::vol)
    {
        char buf[64] = "";
        sprintf(buf,"%s %d 1\n","volume",vol);
        printf("%s",buf);
        write(Mytype.fifo_fd,buf,strlen(buf));
        voic_old2 = Widget::vol;
    }
    ui->pushButton_2->setIcon(QIcon(":/img/4.png"));
    state = true;
    play_state = false;
    char buf[256] = "";
    sprintf(buf,"%s \"../mplayer/song/%s\"\n","loadfile",song_list[song_new]);
    qDebug()<<buf;
    write(Mytype.fifo_fd,buf,strlen(buf));
    usleep(1000);
    song_list_old.push_front(song_new);
    ui->label_4->setText(QString("暂无歌词"));
    ui->widget->lrc_vice(NULL,lrc_num);
    lrc_handle(ui);
    emit this->song_name(song_list[song_new]);
}

void Widget::on_pushButton_3_clicked()//下一首
{
    if(pattern != 3)
    {
        if(song_new >= song_numb-1)
            song_new = 0;
        else
            song_new++;
    }
    else
    {
        mun_t++;
        if(mun_t >= song_list.size())
            mun_t = 0;
        song_new = arr_t[mun_t];
    }
    if(voic_old1 != Widget::voice_num)
    {
        char buf[256] = "";
        sprintf(buf,"%s %d\n","mute",Widget::voice_num);
        write(Mytype.fifo_fd,buf,strlen(buf));
        voic_old1 = Widget::voice_num;
    }
    if(voic_old2 != Widget::vol)
    {
        char buf[64] = "";
        sprintf(buf,"%s %d 1\n","volume",vol);
        printf("%s",buf);
        write(Mytype.fifo_fd,buf,strlen(buf));
        voic_old2 = Widget::vol;
    }
    ui->pushButton_2->setIcon(QIcon(":/img/4.png"));
    state = true;
    play_state = false;
    char buf[256] = "";
    sprintf(buf,"%s \"../mplayer/song/%s\"\n","loadfile",song_list[song_new]);
    qDebug()<<buf;
    write(Mytype.fifo_fd,buf,strlen(buf));
    usleep(1000);
    song_list_old.push_front(song_new);
    lrc_handle(ui);
    emit this->song_name(song_list[song_new]);
}

void Widget::on_pushButton_5_clicked()//静音
{
    if(Widget::voice_num == 0)
    {
         Widget::voice_num = 1;
         ui->pushButton_5->setIcon(QIcon(":/img/6.png"));
         ui->label_10->setText("静音");
         QTimer::singleShot(1000,NULL,[=](){
             ui->label_10->setText("");
         });
    }
    else
    {
         Widget::voice_num = 0;
         ui->pushButton_5->setIcon(QIcon(":/img/9.png"));
         ui->label_10->setText("有声");
         QTimer::singleShot(2000,NULL,[=](){
             ui->label_10->setText("");
         });
    }
    if(state)
    {
        char buf[64] = "";
        sprintf(buf,"%s %d\n","mute",Widget::voice_num);
        write(Mytype.fifo_fd,buf,strlen(buf));
    }
}

void Widget::on_pushButton_6_clicked()//减小音量
{
    if(vol <= 4)
        vol = 0;
    else
        vol -= 5;
    if(Widget::voice_num != 0)
    {
        Widget::voice_num = 0;
        ui->pushButton_5->setIcon(QIcon(":/img/9.png"));
    }
    if(state)
    {
        char buf[64] = "";
        sprintf(buf,"%s %d 1\n","volume",vol);
        printf("%s",buf);
        write(Mytype.fifo_fd,buf,strlen(buf));
    }
    ui->label_11->setText(QString("音量:")+QString::number(vol));
    QTimer::singleShot(1000,NULL,[=](){
        ui->label_11->setText("");
    });
}

void Widget::on_pushButton_7_clicked()//增大音量
{
    if(vol >= 95)
        vol = 100;
    else
        vol += 5;
    if(Widget::voice_num != 0)
    {
        Widget::voice_num = 0;
        ui->pushButton_5->setIcon(QIcon(":/img/9.png"));
    }
    if(state)
    {
        char buf[64] = "";
        sprintf(buf,"%s %d 1\n","volume",vol);
        printf("%s",buf);
        write(Mytype.fifo_fd,buf,strlen(buf));
    }
    ui->label_12->setText(QString("音量:")+QString::number(vol));
    QTimer::singleShot(1000,NULL,[=](){
        ui->label_12->setText("");
    });
}

void Widget::mydir()//歌单列表
{
    int counter =ui->listWidget->count();
    for(int index=0;index<counter;index++)
    {
          QListWidgetItem *item = ui->listWidget->takeItem(0);
          delete item;
    }
    DIR *dir = opendir("../mplayer/song");
    while(1)
    {
        struct dirent *ent =readdir(dir);
        if(ent == NULL)
            break;
        else if(ent->d_type == DT_REG)
        {
            char buf[128] = "";
            sscanf(ent->d_name,"%*[^.].%s",buf);
            if(strcmp("mp3",buf) == 0)
            {
                ui->listWidget->addItem(QString(ent->d_name));
                char *str = new char[strlen(ent->d_name)+1];
                strcpy(str,ent->d_name);
                song_list.push_back(str);
                //printf("----%s\n",ent->d_name);
            }
        }
    }
    song_numb = song_list.size();
}

void Widget::on_listWidget_itemClicked(QListWidgetItem *item)//歌单点击播放
{
    //printf("%s\n",item->text().toUtf8().data());
    char buf[256] = "";
    sprintf(buf,"%s \"../mplayer/song/%s\"\n","loadfile",item->text().toUtf8().data());
    for(int i = 0;i < song_numb;i++)
    {
        if(strcmp(song_list[i],item->text().toUtf8().data()) == 0)
        {
            song_new = i;
            break;
        }
    }
    printf("%s",buf);
    write(Mytype.fifo_fd,buf,strlen(buf));
    ui->pushButton_2->setIcon(QIcon(":/img/4.png"));
    state = true;
    play_state = false;
    usleep(1000);
    song_list_old.push_front(song_new);
    lrc_handle(ui);
    if(voic_old1 != Widget::voice_num)
    {
        char buf[64] = "";
        sprintf(buf,"%s %d\n","mute",Widget::voice_num);
        write(Mytype.fifo_fd,buf,strlen(buf));
        voic_old1 = Widget::voice_num;
    }
    if(voic_old2 != Widget::vol)
    {
        char buf[64] = "";
        sprintf(buf,"%s %d 1\n","volume",vol);
        printf("%s",buf);
        write(Mytype.fifo_fd,buf,strlen(buf));
        voic_old2 = Widget::vol;
    }
    //item->setTextColor(QColor(Qt::red));
}

void player_mode(Ui::Widget * ui)//歌曲播放模式
{
    if(pattern == 0)
    {//播放一首
        only_song = true;
        return;
    }
    else if(pattern == 1)
    {//单曲循环
    }
    else if(pattern == 2)
    {//列表循环
        if(song_new >= song_numb-1)
            song_new = 0;
        else
            song_new++;
    }
    else if(pattern == 3)
    {//随机播放
        mun_t++;
        if(mun_t >= song_list.size())
            mun_t = 0;
        song_new = arr_t[mun_t];
    }
    else
        return;
    state = true;
    ui->pushButton_2->setIcon(QIcon(":/img/4.png"));
    char buf[128] = "";
    sprintf(buf,"%s \"../mplayer/song/%s\"\n","loadfile",song_list[song_new]);
    write(Mytype.fifo_fd,buf,strlen(buf));
    printf("%s",buf);
    song_list_old.push_front(song_new);
    usleep(1000);
    lrc_handle(ui);
    emit this_p->song_name(song_list[song_new]);
}

void Widget::on_pushButton_4_clicked()//播放模式选择
{
    static bool state_t = true;
    if(pattern == 0)
    {
        pattern = 1;//单曲循环
        ui->pushButton_4->setIcon(QIcon(":/img/12.png"));
        state_t = true;
    }
    else if(pattern == 1)
    {
        pattern = 2;//列表循环
        ui->pushButton_4->setIcon(QIcon(":/img/16.png"));
        state_t = true;
    }
    else if(pattern == 2)
    {
        pattern = 3;//随机播放
        ui->pushButton_4->setIcon(QIcon(":/img/17.png"));
        if(state_t)
        {
            for(int i = 0;i < song_list.size();i++)
                arr_t.push_back(i);
            srand(time(NULL));
            random_shuffle(arr_t.begin(),arr_t.end());
            state_t = false;
            mun_t = 0;
        }
    }
    else if(pattern == 3)
    {
        pattern = 0;//播放一首
        ui->pushButton_4->setIcon(QIcon(":/img/18.png"));
        state_t = true;
    }
}

void Widget::on_pushButton_16_clicked()//快退
{
    char buf[128] = "";
    sprintf(buf,"%s %d\n","seek",-5);
    printf("%s",buf);
    write(Mytype.fifo_fd,buf,strlen(buf));
    if(!state)
        write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
    ui->label_14->setText("-5s");
    QTimer::singleShot(1000,NULL,[=](){
        ui->label_14->setText("");
    });
}

void Widget::on_pushButton_17_clicked()//快进
{
    if(Widget::this_time > (Widget::length_time*10-80))
        return;
    char buf[128] = "";
    sprintf(buf,"%s %d\n","seek",5);
    printf("%s",buf);
    write(Mytype.fifo_fd,buf,strlen(buf));
    if(!state)
        write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
    ui->label_15->setText("+5s");
    QTimer::singleShot(1000,NULL,[=](){
        ui->label_15->setText("");
    });
}

void Widget::on_horizontalSlider_sliderPressed()//进度条按下
{
    state_bar = false;
}

void Widget::on_horizontalSlider_sliderReleased()//进度条释放
{
    //printf("%d\n",action);
    //printf("%d\n",ui->horizontalSlider->value());
    if(ui->horizontalSlider->value() != Widget::speed)
    {
        //usleep(1000*100);
        int i = ((ui->horizontalSlider->value()-Widget::speed)*(Widget::length_time)/100);
        if(i == 0)
            return;
        char buf[128] = "";
        sprintf(buf,"%s %d\n","seek",i);
        printf("%s",buf);
        write(Mytype.fifo_fd,buf,strlen(buf));
        if(!state)
            write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
         state_bar = true;
    }
}

void Widget::on_pushButton_8_clicked()//多功能键
{
    static bool state = true;
    if(state)
    {
        ui->pushButton_10->setVisible(true);
        ui->pushButton_11->setVisible(true);
        ui->pushButton_18->setVisible(true);
        ui->pushButton_18->setEnabled(true);
        state = false;
    }
    else
    {
        ui->pushButton_10->setVisible(false);
        ui->pushButton_11->setVisible(false);
        ui->pushButton_19->setVisible(false);
        ui->pushButton_20->setVisible(false);
        ui->label_17->setVisible(false);
        state = true;
        if(time_close < 0 || time_close_old == 0 || time_close_old == -1)
        {
            ui->pushButton_18->setVisible(false);
            ui->pushButton_18->setIcon(QIcon(":/img/35.png"));
            time_close = -1;
        }
        if(time_close_old > 0 && !state_time_close)
        {
            if(time_close_old > 0)
                time_close = time_close_old;
            timer_close->start(1000);
            time_close_old = -3;
            ui->pushButton_18->setIcon(QIcon(":/img/32.png"));
            ui->label_18->setVisible(true);
        }
        ui->pushButton_18->setEnabled(false);
        state_time_close = true;
    }
}

void Widget::on_pushButton_11_clicked()//刷新歌单
{
    printf("刷新歌单\n");
    for(int i = 0;i < song_numb;i++)
        delete []song_list[i];
    song_list.clear();
    Widget::mydir();
    for(int row = 0;row < ui->listWidget->count();row++)
    {
        if(strcmp(ui->listWidget->item(row)->text().toUtf8().data(),song_list[song_new]) == 0)
        {
            ui->listWidget->item(row)->setTextColor(QColor(118,19,239));
            break;
        }
    }
}

void Widget::on_pushButton_10_clicked()//更换背景
{
    static int num = 119;
    printf("更换背景\n");
    char buf[64] = "";
    //num++;
    sprintf(buf,":/img/%d.jpg",num >= 119 ? (num = 110):++num);
    //printf("%s\n",buf);
    QPixmap pix;
    pix.load(buf);
    pix = pix.scaled(1024,600);
    ui->label->setPixmap(pix);
}

void lrc_handle(Ui::Widget *ui)//获取歌词//刷新列表
{
    free_link(&lrc_hand);
    lrc_num = 0;
    ui->label_4->setText(QString("暂无歌词"));
    ui->widget->lrc_vice(NULL,lrc_num);
    emit this_p->song_lrc((char *)"暂无歌词",NULL);
    ui->label_5->setText(QString("正在播放：")+QString(song_list[song_new]));
    char buf[128] = "";
    char str[128] = "";
    sscanf(song_list[song_new],"%[^.]",buf);
    strcat(buf,".lrc");
    sprintf(str,"../mplayer/song/%s",buf);
    //printf("%s\n",str);
    filelrc(&lrc_hand,str);
    if(lrc_hand != NULL)
    {
        ui->label_6->setText(QString("歌名：")+QString(QString(myprint(lrc_hand,0)->buf)));
        ui->label_7->setText(QString("歌手：")+QString(QString(myprint(lrc_hand,1)->buf)));
        ui->label_8->setText(QString("专题：")+QString(QString(myprint(lrc_hand,2)->buf)));
        ui->label_9->setText(QString("制作：")+QString(QString(myprint(lrc_hand,3)->buf)));
    }
    else
    {
        ui->label_6->setText(QString("歌名：")+QString(QString(song_list[song_new])));
        ui->label_7->setText(QString("歌手：")+QString("未知"));
        ui->label_8->setText(QString("专题：")+QString("未知"));
        ui->label_9->setText(QString("制作：")+QString("未知"));
    }
    int counter =ui->listWidget->count();
    for(int index=0;index<counter;index++)
    {
          ui->listWidget->item(index)->setFlags(Qt::ItemIsEditable);
          ui->listWidget->item(index)->setTextColor(QColor(0,0,0));
    }
    counter =ui->listWidget_2->count();
    for(int index=0;index < counter;index++)
    {
          QListWidgetItem *item = ui->listWidget_2->takeItem(0);
          delete item;
    }
    for(int row = 0;row < ui->listWidget->count();row++)
    {
        if(strcmp(ui->listWidget->item(row)->text().toUtf8().data(),song_list[song_new]) == 0)
        {
            ui->listWidget->item(row)->setTextColor(QColor(118,19,239));
            break;
        }
    }
    if(song_list_old.size() > 20)
        song_list_old.pop_back();
    for(int row = 0;row < song_list_old.size();row++)
    {
        ui->listWidget_2->addItem(QString(song_list[song_list_old[row]]));
        //ui->listWidget_2->addItem(QString::number(ui->listWidget_2->count()));
    }
}

void Widget::on_pushButton_12_clicked()//歌词界面
{
    static bool state = true;
    if(state)
    {
        ui->widget->show();
        ui->pushButton_12->setIcon(QIcon(":/img/22.png"));
        ui->label_4->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->label_9->hide();
        ui->label_16->hide();
        ui->listWidget->hide();
        ui->listWidget_2->hide();
        state = false;
    }
    else
    {
        ui->widget->hide();
        ui->pushButton_12->setIcon(QIcon(":/img/21.png"));
        ui->label_4->show();
        ui->label_6->show();
        ui->label_7->show();
        ui->label_8->show();
        ui->label_9->show();
        ui->label_16->show();
        ui->listWidget->show();
        ui->listWidget_2->show();
        state = true;
    }
}

void Widget::on_pushButton_13_clicked()//小窗口播放器
{
    MyState mystate;
    mystate.state = state;
    mystate.voice_num = voice_num;
    mystate.song_name = song_list[song_new];
    mystate.value_num = vol;
    mystate.widget_P = this;
    emit this->song_mini_mystate(mystate);
    miniform->show();
    this->hide();
}

void Widget::on_pushButton_15_clicked()//桌面歌词
{
    static bool state = true;
    if (state)
    {
        Widget::lrcform->show();
        state = false;
        connect(Widget::lrcform,&LrcForm::closet,[&](){
            Widget::on_pushButton_15_clicked();
        });
    }
    else
    {
       Widget::lrcform->hide();
        state = true;
    }
}

void Widget::mouseMoveEvent(QMouseEvent *ev)//鼠标移动重写
{
    if(this->dPos != QPoint(-1,-1))
    if( ev->buttons() & Qt::LeftButton)
    {
        move(ev->globalPos() - this->dPos);
    }
}

void Widget::mousePressEvent(QMouseEvent *event)//鼠标点击重写
{
    if(event->y() < 450)
        this->dPos = event->globalPos() - this->pos();// 移动后部件所在的位置
    else
        this->dPos = QPoint(-1,-1);
}

void Widget::on_listWidget_2_itemClicked(QListWidgetItem *item)//历史记录播放
{
    char buf[256] = "";
    sprintf(buf,"%s \"../mplayer/song/%s\"\n","loadfile",item->text().toUtf8().data());
    for(int i = 0;i < song_numb;i++)
    {
        if(strcmp(song_list[i],item->text().toUtf8().data()) == 0)
        {
            song_new = i;
            break;
        }
    }
    printf("%s",buf);
    write(Mytype.fifo_fd,buf,strlen(buf));
    ui->pushButton_2->setIcon(QIcon(":/img/4.png"));
    state = true;
    play_state = false;
    usleep(1000);
    //song_list_old.push_front(song_new);
    lrc_handle(ui);
    if(voic_old1 != Widget::voice_num)
    {
        char buf[64] = "";
        sprintf(buf,"%s %d\n","mute",Widget::voice_num);
        write(Mytype.fifo_fd,buf,strlen(buf));
        voic_old1 = Widget::voice_num;
    }
    if(voic_old2 != Widget::vol)
    {
        char buf[64] = "";
        sprintf(buf,"%s %d 1\n","volume",vol);
        printf("%s",buf);
        write(Mytype.fifo_fd,buf,strlen(buf));
        voic_old2 = Widget::vol;
    }
    //item->setTextColor(QColor(Qt::red));
}

void Widget::on_pushButton_18_clicked()//定时退出
{
    if(state_time_close)
    {
        timer_close->stop();
        time_close_old = time_close;
        ui->pushButton_19->setVisible(true);
        ui->pushButton_20->setVisible(true);
        ui->label_17->setVisible(true);
        ui->label_18->setVisible(false);
        state_time_close = false;
        ui->pushButton_18->setIcon(QIcon(":/img/31.png"));
        if(time_close <= 0)
        {
            time_close = -1;
            ui->label_17->setText(QString("定时关闭"));
        }
        else
            ui->label_17->setText(QString::number(time_close)+QString("s"));
    }
    else
    {
        ui->pushButton_19->setVisible(false);
        ui->pushButton_20->setVisible(false);
        ui->label_17->setVisible(false);
        state_time_close = true;
        time_close_old = -3;
        if(time_close > 0)
        {
            timer_close->start(1000);
            ui->pushButton_18->setIcon(QIcon(":/img/32.png"));
            ui->label_18->setVisible(true);
            ui->label_18->setText(QString::number(time_close)+QString("s"));
        }
        else
        {
            timer_close->stop();
            time_close = 0;
            ui->label_18->setVisible(false);
            ui->pushButton_18->setIcon(QIcon(":/img/35.png"));
        }
    }
}

void Widget::on_pushButton_19_clicked()//上调定时时间
{
    if(time_close < 0)
        time_close = 0;
    time_close += 30;
    if(time_close > 60*60)
        time_close = 60*60;
    ui->label_17->setText(QString::number(time_close)+QString("s"));
}

void Widget::on_pushButton_20_clicked()//下调定时时间
{
    time_close -= 10;
    if(time_close < 0)
        time_close = 0;
    if(time_close == 0)
    {
        time_close = 0;
        ui->label_17->setText(QString("定时关闭"));
    }
    else
        ui->label_17->setText(QString::number(time_close)+QString("s"));
}

void Widget::on_pushButton_14_clicked()//最小化
{
    this->showMinimized();
}

void Widget::on_pushButton_9_clicked()//退出
{
    //int i = 0;
    write(Mytype.fifo_fd,"quit\n",strlen("quit\n"));
    usleep(1000*10);
    //write(Mytype.fifo_fd,"quit\n",strlen("quit\n"));
    //close(Mytype.fifo_fd);
    free_link(&lrc_hand);
    for(int i = 0;i < song_numb;i++)
        delete []song_list[i];
    song_list.clear();
    delete Widget::lrcform;
    miniform->close();
    this->close();
}

