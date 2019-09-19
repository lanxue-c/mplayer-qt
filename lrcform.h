#ifndef LRCFORM_H
#define LRCFORM_H

#include <QWidget>
#include <QPoint>
#include <QEvent>
namespace Ui {
class LrcForm;
}

class LrcForm : public QWidget
{
    Q_OBJECT

public:
    explicit LrcForm(void *widget_P, QWidget *parent = 0);
    ~LrcForm();

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private slots:
    void on_pushButton_9_clicked();

private:
    Ui::LrcForm *ui;
    QPoint dPos;

    void mouseMoveEvent(QMouseEvent *ev); //鼠标移动事件，用于移动窗口
    void mousePressEvent(QMouseEvent *event);
signals:
    void closet();
};

#endif // LRCFORM_H
