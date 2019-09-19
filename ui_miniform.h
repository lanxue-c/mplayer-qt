/********************************************************************************
** Form generated from reading UI file 'miniform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIFORM_H
#define UI_MINIFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MiniForm
{
public:
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_13;
    QPushButton *pushButton_9;
    QPushButton *pushButton_14;
    QSlider *verticalSlider;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_15;

    void setupUi(QWidget *MiniForm)
    {
        if (MiniForm->objectName().isEmpty())
            MiniForm->setObjectName(QStringLiteral("MiniForm"));
        MiniForm->resize(287, 120);
        pushButton_2 = new QPushButton(MiniForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(71, 62, 55, 55));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(55, 55));
        pushButton_2->setFlat(true);
        label = new QLabel(MiniForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 287, 120));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/111.jpg")));
        label->setWordWrap(false);
        pushButton = new QPushButton(MiniForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(3, 69, 48, 48));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/14.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(48, 48));
        pushButton->setFlat(true);
        pushButton_3 = new QPushButton(MiniForm);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(143, 69, 48, 48));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/10.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(48, 48));
        pushButton_3->setFlat(true);
        pushButton_5 = new QPushButton(MiniForm);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(213, 76, 40, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/9.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon3);
        pushButton_5->setIconSize(QSize(40, 40));
        pushButton_5->setFlat(true);
        pushButton_13 = new QPushButton(MiniForm);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(230, 2, 25, 25));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/24.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon4);
        pushButton_13->setIconSize(QSize(25, 25));
        pushButton_13->setFlat(true);
        pushButton_9 = new QPushButton(MiniForm);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(260, 2, 25, 25));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/11.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon5);
        pushButton_9->setIconSize(QSize(25, 25));
        pushButton_9->setFlat(true);
        pushButton_14 = new QPushButton(MiniForm);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(200, 2, 25, 25));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/23.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon6);
        pushButton_14->setIconSize(QSize(25, 25));
        pushButton_14->setFlat(true);
        verticalSlider = new QSlider(MiniForm);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(260, 30, 20, 84));
        verticalSlider->setOrientation(Qt::Vertical);
        label_2 = new QLabel(MiniForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 30, 248, 31));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(MiniForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(218, 60, 31, 17));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(MiniForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(243, 40, 21, 17));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_15 = new QPushButton(MiniForm);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(155, 2, 25, 25));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/25.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon7);
        pushButton_15->setIconSize(QSize(25, 25));
        pushButton_15->setFlat(true);
        label->raise();
        pushButton_2->raise();
        pushButton->raise();
        pushButton_3->raise();
        pushButton_5->raise();
        pushButton_13->raise();
        pushButton_9->raise();
        pushButton_14->raise();
        verticalSlider->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        pushButton_15->raise();

        retranslateUi(MiniForm);

        QMetaObject::connectSlotsByName(MiniForm);
    } // setupUi

    void retranslateUi(QWidget *MiniForm)
    {
        MiniForm->setWindowTitle(QApplication::translate("MiniForm", "Form", nullptr));
        pushButton_2->setText(QString());
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_3->setText(QString());
        pushButton_5->setText(QString());
        pushButton_13->setText(QString());
        pushButton_9->setText(QString());
        pushButton_14->setText(QString());
        label_2->setText(QApplication::translate("MiniForm", "unknown", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        pushButton_15->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MiniForm: public Ui_MiniForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIFORM_H
