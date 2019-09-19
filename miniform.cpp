#include "miniform.h"
#include "widget.h"
#include "ui_miniform.h"
#include <QMouseEvent>
#include <QTimer>
MiniForm::MiniForm(void *widget_P,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MiniForm)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->move(1500,50);
    connect((Widget *)widget_P,&Widget::song_mini_mystate,[&](MyState mystate){
        if(mystate.state == 1)
            ui->pushButton_2->setIcon(QIcon(":/img/4.png"));
        if(mystate.voice_num == 1)
            ui->pushButton_5->setIcon(QIcon(":/img/6.png"));
        if(mystate.song_name != NULL)
            ui->label_2->setText(QString(mystate.song_name));
        ui->verticalSlider->setValue(mystate.value_num);
        this_state = mystate;
    });
    connect((Widget *)widget_P,&Widget::song_name,[=](char *song_name){
        ui->label_2->setText(QString(song_name));
    });
}

MiniForm::~MiniForm()
{
    delete ui;
}

void MiniForm::on_pushButton_2_clicked()//播放暂停
{
    if(this_state.state == 1)
    {
        this_state.state = 0;
        ui->pushButton_2->setIcon(QIcon(":/img/1.png"));
    }
    else if(this_state.state == 0)
    {
        ui->pushButton_2->setIcon(QIcon(":/img/4.png"));
        this_state.state = 1;
    }
    emit this->suspend();
}

void MiniForm::on_pushButton_clicked()//上一首
{
    emit this->last_song();
    if(this_state.state == 0)
    {
        ui->pushButton_2->setIcon(QIcon(":/img/4.png"));
        this_state.state = 1;
    }
}

void MiniForm::on_pushButton_3_clicked()//下一首
{
    emit this->next_song();
    if(this_state.state == 0)
    {
        ui->pushButton_2->setIcon(QIcon(":/img/4.png"));
        this_state.state = 1;
    }
}

void MiniForm::on_pushButton_5_clicked()//静音
{
    if(this_state.voice_num == 1)
    {
         this_state.voice_num = 0;
         ui->pushButton_5->setIcon(QIcon(":/img/9.png"));
         ui->label_3->setText("有声");
         QTimer::singleShot(1000,NULL,[=](){
             ui->label_3->setText("");
         });
    }
    else if(this_state.voice_num == 0)
    {
        this_state.voice_num = 1;
         ui->pushButton_5->setIcon(QIcon(":/img/6.png"));
         ui->label_3->setText("静音");
         QTimer::singleShot(1500,NULL,[=](){
             ui->label_3->setText("");
         });
    }
    emit this->mute();
}

void MiniForm::on_verticalSlider_valueChanged(int value)//音量调节
{
    ui->label_4->setText(QString::number(value));
    QTimer::singleShot(2000,NULL,[=](){
        ui->label_4->setText("");
    });
    static int num = 0;
    if((num > value+1) || (num < value-1))
    {
        emit this->value_num(value);
        num = value;
    }
}

void MiniForm::mouseMoveEvent(QMouseEvent *ev)//鼠标移动重写
{
    if( ev->buttons() & Qt::LeftButton){
        move(ev->globalPos() - this->dPos);
    }
}

void MiniForm::mousePressEvent(QMouseEvent *event)//鼠标点击重写
{
    this->dPos = event->globalPos() - this->pos();// 移动后部件所在的位置
}

void MiniForm::on_pushButton_13_clicked()//大窗口
{
    emit this->quitout();
}

void MiniForm::on_pushButton_14_clicked()//最小化
{
    emit this->minimize();
}

void MiniForm::on_pushButton_15_clicked()//歌词界面
{
    emit this->lrc_control();
}

void MiniForm::on_pushButton_9_clicked()//退出
{
    emit this->shoutt();
}
