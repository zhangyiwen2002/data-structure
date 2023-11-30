/********************************************************************************
** Form generated from reading UI file 'expenseshow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPENSESHOW_H
#define UI_EXPENSESHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_expenseShow
{
public:
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *widget_3;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget_4;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *widget_5;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *widget_6;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_12;

    void setupUi(QDialog *expenseShow)
    {
        if (expenseShow->objectName().isEmpty())
            expenseShow->setObjectName(QStringLiteral("expenseShow"));
        expenseShow->resize(400, 342);
        widget = new QWidget(expenseShow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 60, 371, 41));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 91, 21));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 10, 291, 21));
        widget_2 = new QWidget(expenseShow);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 110, 371, 41));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 91, 21));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 10, 271, 21));
        widget_3 = new QWidget(expenseShow);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(10, 160, 371, 41));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 91, 21));
        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 10, 271, 21));
        widget_4 = new QWidget(expenseShow);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(10, 210, 371, 41));
        label_7 = new QLabel(widget_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 91, 21));
        label_8 = new QLabel(widget_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 10, 301, 21));
        widget_5 = new QWidget(expenseShow);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(10, 270, 371, 41));
        label_9 = new QLabel(widget_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 10, 91, 21));
        label_10 = new QLabel(widget_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(70, 10, 291, 31));
        widget_6 = new QWidget(expenseShow);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(10, 10, 371, 41));
        label_11 = new QLabel(widget_6);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 10, 91, 21));
        label_13 = new QLabel(widget_6);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(150, 10, 261, 31));
        label_12 = new QLabel(widget_6);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(100, 10, 261, 21));

        retranslateUi(expenseShow);

        QMetaObject::connectSlotsByName(expenseShow);
    } // setupUi

    void retranslateUi(QDialog *expenseShow)
    {
        expenseShow->setWindowTitle(QApplication::translate("expenseShow", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("expenseShow", "\346\217\220\345\215\225\344\272\272:", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("expenseShow", "\346\217\220\345\215\225\351\207\221\351\242\235:", Q_NULLPTR));
        label_4->setText(QString());
        label_5->setText(QApplication::translate("expenseShow", "\346\217\220\345\215\225\346\227\245\346\234\237:", Q_NULLPTR));
        label_6->setText(QString());
        label_7->setText(QApplication::translate("expenseShow", "\347\212\266\346\200\201:", Q_NULLPTR));
        label_8->setText(QString());
        label_9->setText(QApplication::translate("expenseShow", "\345\244\204\347\220\206\344\272\272:", Q_NULLPTR));
        label_10->setText(QString());
        label_11->setText(QApplication::translate("expenseShow", "\346\212\245\351\224\200\345\215\225\347\274\226\345\217\267:", Q_NULLPTR));
        label_13->setText(QString());
        label_12->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class expenseShow: public Ui_expenseShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPENSESHOW_H
