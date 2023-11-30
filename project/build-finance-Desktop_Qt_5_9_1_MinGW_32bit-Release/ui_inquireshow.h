/********************************************************************************
** Form generated from reading UI file 'inquireshow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INQUIRESHOW_H
#define UI_INQUIRESHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inquireShow
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;

    void setupUi(QDialog *inquireShow)
    {
        if (inquireShow->objectName().isEmpty())
            inquireShow->setObjectName(QStringLiteral("inquireShow"));
        inquireShow->resize(406, 285);
        widget = new QWidget(inquireShow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 381, 81));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        widget_2 = new QWidget(inquireShow);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 90, 381, 81));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        widget_3 = new QWidget(inquireShow);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(10, 170, 381, 81));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);


        retranslateUi(inquireShow);

        QMetaObject::connectSlotsByName(inquireShow);
    } // setupUi

    void retranslateUi(QDialog *inquireShow)
    {
        inquireShow->setWindowTitle(QApplication::translate("inquireShow", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("inquireShow", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("inquireShow", "\350\201\224\347\263\273\347\224\265\350\257\235\357\274\232", Q_NULLPTR));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class inquireShow: public Ui_inquireShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INQUIRESHOW_H
