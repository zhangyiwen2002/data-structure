#-------------------------------------------------
#
# Project created by QtCreator 2022-02-20T15:41:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = finance
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    assessing.cpp \
    reimbursement.cpp \
    authorization.cpp \
    add.cpp \
    delete.cpp \
    change.cpp \
    inquire.cpp \
    inquireshow.cpp \
    submited.cpp \
    file.cpp \
    create.cpp \
    audit.cpp \
    expenseshow.cpp

HEADERS += \
        mainwindow.h \
    assessing.h \
    reimbursement.h \
    authorization.h \
    add.h \
    delete.h \
    change.h \
    inquire.h \
    inquireshow.h \
    submited.h \
    file.h \
    create.h \
    audit.h \
    expenseshow.h

FORMS += \
        mainwindow.ui \
    add.ui \
    add.ui \
    delete.ui \
    change.ui \
    inquire.ui \
    inquireshow.ui \
    create.ui \
    expenseshow.ui

RESOURCES += \
    res.qrc
