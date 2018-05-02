#-------------------------------------------------
#
# Project created by QtCreator 2018-01-23T13:04:05
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NextRAD_DatabaseGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qdynamicbutton.cpp \
    qdynamiclineedit.cpp

HEADERS  += mainwindow.h \
    qdynamicbutton.h \
    qdynamiclineedit.h

FORMS    += mainwindow.ui
