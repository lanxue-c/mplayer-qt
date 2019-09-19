#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QListWidgetItem>
#include <vector>
#include <iostream>
#include <QPoint>
#include <QTimer>
#include "miniform.h"
#include "lrcform.h"

using namespace std;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    static int speed;
    static int this_time;
    static int length_time;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_4_clicked();

    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderReleased();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_listWidget_2_itemClicked(QListWidgetItem *item);

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

public slots:

private:
    Ui::Widget *ui;
    int voic_old1;
    int voic_old2;
    bool play_state;
    LrcForm *lrcform;
    int vol;
    int voice_num;
    QPoint dPos;
    int time_close;
    QTimer *timer_close;
    MiniForm *miniform;

    void mydir();
    void mouseMoveEvent(QMouseEvent *ev); //鼠标移动事件，用于移动窗口
    void mousePressEvent(QMouseEvent *event);

signals:
    void song_name(char *song_name);
    void song_lrc(char *lrc1,char *lrc2);
    void song_mini_mystate(MyState mystate);
};

#endif // WIDGET_H
