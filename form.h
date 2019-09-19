#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "fun.h"
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

    void lrc_vice(LRC *lrc_hand, int lrc_num);

private slots:


private:
    Ui::Form *ui;

signals:

};

#endif // FORM_H
