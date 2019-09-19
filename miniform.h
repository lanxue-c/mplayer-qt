#ifndef MINIFORM_H
#define MINIFORM_H

#include <QWidget>
#include <QPoint>
namespace Ui {
class MiniForm;
}

struct MyState{
   int state;
   int voice_num;
   char *song_name;
   void *widget_P;
   int value_num;
};

class MiniForm : public QWidget
{
    Q_OBJECT

public:
    explicit MiniForm(void *widget_P,QWidget *parent = 0);
    ~MiniForm();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_verticalSlider_valueChanged(int value);

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::MiniForm *ui;
    int state;
    QPoint dPos;
    MyState this_state;

    void mouseMoveEvent(QMouseEvent *ev); //鼠标移动事件，用于移动窗口
    void mousePressEvent(QMouseEvent *event);
signals:
    void suspend();
    void last_song();
    void next_song();
    void quitout();
    void mute();
    void shoutt();
    void minimize();
    void value_num(int num);
    void lrc_control();
};

#endif // MINIFORM_H
