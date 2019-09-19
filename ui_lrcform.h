/********************************************************************************
** Form generated from reading UI file 'lrcform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LRCFORM_H
#define UI_LRCFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LrcForm
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_9;
    QLabel *label_4;

    void setupUi(QWidget *LrcForm)
    {
        if (LrcForm->objectName().isEmpty())
            LrcForm->setObjectName(QStringLiteral("LrcForm"));
        LrcForm->resize(900, 73);
        LrcForm->setStyleSheet(QStringLiteral(""));
        label = new QLabel(LrcForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(5, -2, 850, 38));
        QFont font;
        font.setFamily(QStringLiteral("Noto Sans Mono CJK TC"));
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        label->setFont(font);
        label->setCursor(QCursor(Qt::ArrowCursor));
        label->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(LrcForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(15, 33, 850, 38));
        QFont font1;
        font1.setFamily(QStringLiteral("Noto Sans CJK TC"));
        font1.setPointSize(15);
        font1.setItalic(true);
        label_2->setFont(font1);
        label_2->setCursor(QCursor(Qt::ArrowCursor));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(LrcForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 900, 73));
        label_3->setStyleSheet(QStringLiteral(""));
        pushButton_9 = new QPushButton(LrcForm);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(873, 2, 25, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/26.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon);
        pushButton_9->setIconSize(QSize(25, 25));
        pushButton_9->setFlat(true);
        label_4 = new QLabel(LrcForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 10, 131, 38));
        label_4->setFont(font1);
        label_4->setCursor(QCursor(Qt::ArrowCursor));
        label_4->setAlignment(Qt::AlignCenter);
        label_3->raise();
        label->raise();
        label_2->raise();
        pushButton_9->raise();
        label_4->raise();

        retranslateUi(LrcForm);

        QMetaObject::connectSlotsByName(LrcForm);
    } // setupUi

    void retranslateUi(QWidget *LrcForm)
    {
        LrcForm->setWindowTitle(QApplication::translate("LrcForm", "Form", nullptr));
        label->setText(QApplication::translate("LrcForm", " \346\232\202\346\227\240\346\255\214\350\257\215", nullptr));
        label_2->setText(QApplication::translate("LrcForm", "\346\232\202\346\227\240\346\255\214\350\257\215  ", nullptr));
        label_3->setText(QString());
        pushButton_9->setText(QString());
        label_4->setText(QApplication::translate("LrcForm", "\346\232\202\346\227\240\346\255\214\350\257\215  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LrcForm: public Ui_LrcForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LRCFORM_H
