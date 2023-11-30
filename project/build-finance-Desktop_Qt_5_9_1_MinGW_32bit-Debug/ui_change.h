/********************************************************************************
** Form generated from reading UI file 'change.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_H
#define UI_CHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Change
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBox;

    void setupUi(QDialog *Change)
    {
        if (Change->objectName().isEmpty())
            Change->setObjectName(QStringLiteral("Change"));
        Change->resize(400, 232);
        buttonBox = new QDialogButtonBox(Change);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 190, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(Change);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 10, 381, 171));
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(10, 10, 361, 43));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget_4);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(10, 60, 361, 43));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(widget_5);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(10, 110, 361, 43));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        comboBox = new QComboBox(widget_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_4->addWidget(comboBox);


        retranslateUi(Change);
        QObject::connect(buttonBox, SIGNAL(accepted()), Change, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Change, SLOT(reject()));

        QMetaObject::connectSlotsByName(Change);
    } // setupUi

    void retranslateUi(QDialog *Change)
    {
        Change->setWindowTitle(QApplication::translate("Change", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("Change", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Change", "\350\257\267\350\276\223\345\205\245\347\224\265\350\257\235\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Change", "\350\257\267\350\276\223\345\205\245\350\247\222\350\211\262\357\274\232", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Change", "\351\203\250\351\227\250\344\270\273\347\256\241", Q_NULLPTR)
         << QApplication::translate("Change", "\351\203\250\351\227\250\345\211\257\344\270\273\347\256\241", Q_NULLPTR)
         << QApplication::translate("Change", "\350\264\242\345\212\241\344\270\273\347\256\241", Q_NULLPTR)
         << QApplication::translate("Change", "\350\264\242\345\212\241\345\211\257\344\270\273\347\256\241", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class Change: public Ui_Change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_H
