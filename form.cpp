#include "form.h"
#include "ui_form.h"
#include <QPushButton>
#include <QMovie>
//#include "ui_widget.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QMovie *movie1 = new QMovie("./img/221.gif");
    QMovie *movie2 = new QMovie("./img/222.gif");
    movie1->setScaledSize(QSize(300,120));
    movie2->setScaledSize(QSize(150,150));
    ui->label_9->setMovie(movie1);
    ui->label->setMovie(movie2);
    movie1->start();
    movie2->start();
}

Form::~Form()
{
    delete ui;
}

void Form::lrc_vice(LRC *lrc_hand, int lrc_num)//歌词界面
{
    if(lrc_hand != NULL)
    {
        if(lrc_num > 3)
            ui->label_0->setText(QString(myprint(lrc_hand,lrc_num-4)->buf));
        if(lrc_num > 2)
            ui->label_1->setText(QString(myprint(lrc_hand,lrc_num-3)->buf));
        if(lrc_num > 1)
            ui->label_2->setText(QString(myprint(lrc_hand,lrc_num-2)->buf));
        if(lrc_num > 0)
            ui->label_3->setText(QString(myprint(lrc_hand,lrc_num-1)->buf));
        ui->label_4->setText(QString(myprint(lrc_hand,lrc_num)->buf));
        if(myprint(lrc_hand,lrc_num+1) != NULL)
            ui->label_5->setText(QString(myprint(lrc_hand,lrc_num+1)->buf));
        else
            ui->label_5->setText(QString(""));
        if(myprint(lrc_hand,lrc_num+2) != NULL)
            ui->label_6->setText(QString(myprint(lrc_hand,lrc_num+2)->buf));
        else
            ui->label_6->setText(QString(""));
        if(myprint(lrc_hand,lrc_num+3) != NULL)
            ui->label_7->setText(QString(myprint(lrc_hand,lrc_num+3)->buf));
        else
            ui->label_7->setText(QString(""));
        if(myprint(lrc_hand,lrc_num+4) != NULL)
            ui->label_8->setText(QString(myprint(lrc_hand,lrc_num+4)->buf));
        else
            ui->label_8->setText(QString(""));
    }
    else
    {

        ui->label_0->setText(QString(""));
        ui->label_1->setText(QString(""));
        ui->label_2->setText(QString(""));
        ui->label_3->setText(QString(""));
        ui->label_4->setText(QString("暂无歌词"));
        ui->label_5->setText(QString(""));
        ui->label_6->setText(QString(""));
        ui->label_7->setText(QString(""));
        ui->label_8->setText(QString(""));
    }

}

