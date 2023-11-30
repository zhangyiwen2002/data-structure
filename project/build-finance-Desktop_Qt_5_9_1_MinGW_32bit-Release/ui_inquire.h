/********************************************************************************
** Form generated from reading UI file 'inquire.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INQUIRE_H
#define UI_INQUIRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inquire
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Inquire)
    {
        if (Inquire->objectName().isEmpty())
            Inquire->setObjectName(QStringLiteral("Inquire"));
        Inquire->resize(400, 157);
        buttonBox = new QDialogButtonBox(Inquire);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(40, 100, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(Inquire);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 381, 71));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(Inquire);
        QObject::connect(buttonBox, SIGNAL(accepted()), Inquire, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Inquire, SLOT(reject()));

        QMetaObject::connectSlotsByName(Inquire);
    } // setupUi

    void retranslateUi(QDialog *Inquire)
    {
        Inquire->setWindowTitle(QApplication::translate("Inquire", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Inquire", "\350\257\267\350\276\223\345\205\245\345\272\217\345\217\267:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Inquire: public Ui_Inquire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INQUIRE_H
