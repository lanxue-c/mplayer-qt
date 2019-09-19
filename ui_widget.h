/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <form.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QListWidget *listWidget;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QLabel *label_4;
    QPushButton *pushButton_12;
    Form *widget;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QLabel *label_13;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QLabel *label_14;
    QLabel *label_15;
    QListWidget *listWidget_2;
    QLabel *label_16;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QLabel *label_17;
    QLabel *label_18;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1024, 600);
        Widget->setAutoFillBackground(false);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1024, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/119.jpg")));
        label->setScaledContents(true);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 520, 60, 60));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/14.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(60, 60));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 520, 60, 60));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(60, 60));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 520, 60, 60));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/10.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(60, 60));
        pushButton_3->setFlat(true);
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(697, 520, 60, 60));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/9.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon3);
        pushButton_5->setIconSize(QSize(60, 60));
        pushButton_5->setFlat(true);
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(780, 520, 60, 60));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/15.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon4);
        pushButton_6->setIconSize(QSize(60, 60));
        pushButton_6->setFlat(true);
        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(860, 520, 60, 60));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/7.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon5);
        pushButton_7->setIconSize(QSize(60, 60));
        pushButton_7->setFlat(true);
        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(940, 520, 60, 60));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/5.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon6);
        pushButton_8->setIconSize(QSize(60, 60));
        pushButton_8->setFlat(true);
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 520, 60, 60));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/16.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon7);
        pushButton_4->setIconSize(QSize(60, 60));
        pushButton_4->setFlat(true);
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(730, 40, 221, 388));
        listWidget->setTabletTracking(false);
        listWidget->setAcceptDrops(false);
        listWidget->setLayoutDirection(Qt::LeftToRight);
        listWidget->setAutoFillBackground(false);
        listWidget->setStyleSheet(QStringLiteral("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setFrameShadow(QFrame::Raised);
        listWidget->setLineWidth(7);
        listWidget->setMidLineWidth(2);
        listWidget->setGridSize(QSize(20, 20));
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setSortingEnabled(false);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(40, 480, 611, 31));
        horizontalSlider->setCursor(QCursor(Qt::OpenHandCursor));
        horizontalSlider->setMouseTracking(false);
        horizontalSlider->setMaximum(99);
        horizontalSlider->setValue(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(35, 459, 67, 17));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(660, 486, 67, 17));
        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(992, 2, 30, 30));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/11.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon8);
        pushButton_9->setIconSize(QSize(30, 30));
        pushButton_9->setFlat(true);
        pushButton_10 = new QPushButton(Widget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setEnabled(true);
        pushButton_10->setGeometry(QRect(945, 460, 50, 50));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/33.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon9);
        pushButton_10->setIconSize(QSize(50, 50));
        pushButton_10->setFlat(true);
        pushButton_11 = new QPushButton(Widget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setEnabled(true);
        pushButton_11->setGeometry(QRect(944, 398, 50, 50));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/img/34.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon10);
        pushButton_11->setIconSize(QSize(50, 50));
        pushButton_11->setFlat(true);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 410, 491, 51));
        QFont font;
        font.setPointSize(13);
        label_4->setFont(font);
        pushButton_12 = new QPushButton(Widget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(620, 520, 60, 60));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/img/21.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon11);
        pushButton_12->setIconSize(QSize(60, 60));
        pushButton_12->setFlat(true);
        widget = new Form(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 920, 450));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 20, 531, 41));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(300, 66, 430, 41));
        QFont font1;
        font1.setPointSize(15);
        label_6->setFont(font1);
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(300, 120, 430, 41));
        label_7->setFont(font1);
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(300, 170, 430, 41));
        label_8->setFont(font1);
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(300, 220, 430, 41));
        label_9->setFont(font1);
        label_10 = new QLabel(Widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(703, 500, 51, 16));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(Widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(787, 500, 51, 16));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(Widget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(862, 500, 57, 16));
        label_12->setAlignment(Qt::AlignCenter);
        pushButton_13 = new QPushButton(Widget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(959, 2, 30, 30));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/img/24.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon12);
        pushButton_13->setIconSize(QSize(30, 30));
        pushButton_13->setFlat(true);
        pushButton_14 = new QPushButton(Widget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(925, 2, 30, 30));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/img/23.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon13);
        pushButton_14->setIconSize(QSize(30, 30));
        pushButton_14->setFlat(true);
        pushButton_15 = new QPushButton(Widget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(540, 520, 60, 60));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/img/25.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon14);
        pushButton_15->setIconSize(QSize(60, 60));
        pushButton_15->setFlat(true);
        label_13 = new QLabel(Widget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(0, 0, 1024, 600));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/img/120.jpg")));
        label_13->setScaledContents(true);
        pushButton_16 = new QPushButton(Widget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(120, 520, 60, 60));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/img/27.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon15);
        pushButton_16->setIconSize(QSize(60, 60));
        pushButton_16->setFlat(true);
        pushButton_17 = new QPushButton(Widget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(450, 520, 60, 60));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/img/2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon16);
        pushButton_17->setIconSize(QSize(60, 60));
        pushButton_17->setFlat(true);
        label_14 = new QLabel(Widget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(126, 503, 51, 16));
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(Widget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(456, 504, 51, 16));
        label_15->setAlignment(Qt::AlignCenter);
        listWidget_2 = new QListWidget(Widget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(70, 67, 225, 321));
        listWidget_2->setTabletTracking(false);
        listWidget_2->setAcceptDrops(false);
        listWidget_2->setLayoutDirection(Qt::LeftToRight);
        listWidget_2->setAutoFillBackground(false);
        listWidget_2->setStyleSheet(QStringLiteral("background-color: rgba(191, 64, 64, 0);"));
        listWidget_2->setFrameShape(QFrame::NoFrame);
        listWidget_2->setFrameShadow(QFrame::Raised);
        listWidget_2->setLineWidth(7);
        listWidget_2->setMidLineWidth(2);
        listWidget_2->setGridSize(QSize(20, 20));
        listWidget_2->setViewMode(QListView::ListMode);
        listWidget_2->setSortingEnabled(false);
        label_16 = new QLabel(Widget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(5, 60, 81, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("KacstScreen"));
        font2.setPointSize(11);
        font2.setItalic(false);
        label_16->setFont(font2);
        pushButton_18 = new QPushButton(Widget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setEnabled(true);
        pushButton_18->setGeometry(QRect(944, 336, 50, 50));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/img/35.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon17);
        pushButton_18->setIconSize(QSize(50, 50));
        pushButton_18->setFlat(true);
        pushButton_19 = new QPushButton(Widget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setEnabled(true);
        pushButton_19->setGeometry(QRect(910, 335, 25, 20));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/img/30.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon18);
        pushButton_19->setIconSize(QSize(25, 25));
        pushButton_19->setFlat(true);
        pushButton_20 = new QPushButton(Widget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setEnabled(true);
        pushButton_20->setGeometry(QRect(910, 359, 25, 20));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/img/29.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_20->setIcon(icon19);
        pushButton_20->setIconSize(QSize(25, 25));
        pushButton_20->setFlat(true);
        label_17 = new QLabel(Widget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(857, 347, 51, 20));
        QFont font3;
        font3.setPointSize(9);
        label_17->setFont(font3);
        label_17->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_18 = new QLabel(Widget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(955, 351, 31, 20));
        label_18->setFont(font3);
        label_18->setAlignment(Qt::AlignCenter);
        label->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        pushButton_8->raise();
        pushButton_4->raise();
        listWidget->raise();
        horizontalSlider->raise();
        label_2->raise();
        label_3->raise();
        pushButton_9->raise();
        pushButton_10->raise();
        pushButton_11->raise();
        label_4->raise();
        pushButton_12->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        pushButton_13->raise();
        pushButton_14->raise();
        pushButton_15->raise();
        pushButton_16->raise();
        pushButton_17->raise();
        label_14->raise();
        label_15->raise();
        listWidget_2->raise();
        label_16->raise();
        pushButton_19->raise();
        pushButton_20->raise();
        widget->raise();
        label_17->raise();
        label_18->raise();
        pushButton_18->raise();
        label_13->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_4->setText(QString());
        label_2->setText(QApplication::translate("Widget", "00:00.0", nullptr));
        label_3->setText(QApplication::translate("Widget", "00:00", nullptr));
        pushButton_9->setText(QString());
        pushButton_10->setText(QString());
        pushButton_11->setText(QString());
        label_4->setText(QApplication::translate("Widget", "\346\232\202\346\227\240\346\255\214\350\257\215", nullptr));
        pushButton_12->setText(QString());
        label_5->setText(QApplication::translate("Widget", "\346\255\243\345\234\250\346\222\255\346\224\276\357\274\232", nullptr));
        label_6->setText(QApplication::translate("Widget", "\346\255\214\345\220\215\357\274\232", nullptr));
        label_7->setText(QApplication::translate("Widget", "\346\255\214\346\211\213\357\274\232", nullptr));
        label_8->setText(QApplication::translate("Widget", "\344\270\223\351\242\230\357\274\232", nullptr));
        label_9->setText(QApplication::translate("Widget", "\345\210\266\344\275\234\357\274\232", nullptr));
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        pushButton_15->setText(QString());
        label_13->setText(QString());
        pushButton_16->setText(QString());
        pushButton_17->setText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QApplication::translate("Widget", "\345\216\206\345\217\262\350\256\260\345\275\225:", nullptr));
        pushButton_18->setText(QString());
        pushButton_19->setText(QString());
        pushButton_20->setText(QString());
        label_17->setText(QApplication::translate("Widget", "\345\256\232\346\227\266\345\205\263\351\227\255", nullptr));
        label_18->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
