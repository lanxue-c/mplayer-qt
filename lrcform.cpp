#include "lrcform.h"
#include "ui_lrcform.h"
#include <QMouseEvent>
#include "widget.h"
#include <QFont>
#include <string.h>
#include <QPalette>
LrcForm::LrcForm(void *widget_P, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LrcForm)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->move(450,850);
    ui->pushButton_9->hide();
    ui->label_4->hide();
    QFont font1("Noto Sans CJK TC", 25, 63,true);
    QFont font2("Noto Sans CJK TC", 15, 50,true);
    QPalette pa1;
    pa1.setColor(QPalette::WindowText,Qt::blue);
    QPalette pa2;
    pa2.setColor(QPalette::WindowText,Qt::black);
    connect((Widget *)widget_P,&Widget::song_lrc,[=](char *lrc1,char *lrc2){
       static char *str = lrc1;
       static bool state = true;
       if(lrc2 == NULL)
       {
           state = true;
           ui->label->setText(QString(" "));
           ui->label_2->setText(QString(" "));
           ui->label_4->show();
           ui->label_4->setText(QString(lrc1));
       }
       else
       {
           if(strcmp(str,lrc1) != 0)
           {
               state = !state;
               str = lrc1;
           }
           ui->label_4->hide();
           if(state)
           {
               ui->label->setFont(font1);
               ui->label->setPalette(pa1);
               ui->label_2->setFont(font2);
               ui->label_2->setPalette(pa2);
               if(strcmp(lrc1,"") == 0)
                   ui->label->setText(QString(" 。。。 "));
               else
                   ui->label->setText(QString(" ")+QString(lrc1));
               if(strcmp(lrc2,"") == 0)
                   ui->label_2->setText(QString(" 。。。 "));
               else
                   ui->label_2->setText(QString(lrc2)+QString("  "));
           }
           else
           {
               ui->label->setFont(font2);
               ui->label->setPalette(pa2);
               ui->label_2->setFont(font1);
               ui->label_2->setPalette(pa1);
               if(strcmp(lrc2,"") == 0)
                   ui->label->setText(QString(" 。。。 "));
               else
                   ui->label->setText(QString(" ")+QString(lrc2));
               if(strcmp(lrc1,"") == 0)
                   ui->label_2->setText(QString(" 。。。 "));
               else
                   ui->label_2->setText(QString(lrc1)+QString("  "));
           }
       }
    });
}

LrcForm::~LrcForm()
{
    delete ui;
}

void LrcForm::enterEvent(QEvent *)//鼠标进入事件
{
    ui->label_3->setStyleSheet("background-color: rgba(182, 233, 253, 195);");
    ui->pushButton_9->show();
}

void LrcForm::leaveEvent(QEvent *)//鼠标离开事件
{
    ui->label_3->setStyleSheet("background-color: rgba(182, 233, 253, 0);");
    ui->pushButton_9->hide();
}

void LrcForm::mouseMoveEvent(QMouseEvent *ev)//鼠标移动重写
{
    if( ev->buttons() & Qt::LeftButton)
    {
        move(ev->globalPos() - this->dPos);
    }
}

void LrcForm::mousePressEvent(QMouseEvent *event)//鼠标点击重写
{
    this->dPos = event->globalPos() - this->pos();// 移动后部件所在的位置
}

void LrcForm::on_pushButton_9_clicked()//关闭桌面歌词
{
    emit this->closet();
}
