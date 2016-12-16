#-------------------------------------------------
#
# Project created by QtCreator 2016-12-13T13:57:11
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zzVerkefni_3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computers.cpp \
    dataaccess.cpp \
    performer.cpp \
    performerservice.cpp \
    relations.cpp \
    relationsid.cpp \
    relationstable.cpp \
    addscientistsdialog.cpp \
    addcomputer.cpp \
    editscientist.cpp \
    introdialog.cpp \
    editcomputer.cpp \
    addconnectiondialog.cpp \
    creditsdialog.cpp


HEADERS  += mainwindow.h \
    computers.h \
    dataaccess.h \
    performer.h \
    performerservice.h \
    relations.h \
    relationsid.h \
    relationstable.h \
    addscientistsdialog.h \
    addcomputer.h \
    editscientist.h \
    introdialog.h \
    editcomputer.h \
    addconnectiondialog.h \
    creditsdialog.h


FORMS    += mainwindow.ui \
    addscientistsdialog.ui \
    addcomputer.ui \
    editscientist.ui \
    addconnectiondialog.ui \
    introdialog.ui \
    editcomputer.ui \
    creditsdialog.ui

RESOURCES += \
    myresources.qrc
