#-------------------------------------------------
#
# Project created by QtCreator 2017-02-18T22:04:26
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wheatherChannel
TEMPLATE = app


SOURCES += main.cpp\
        wheatherchannel.cpp \
    line.cpp \
    serial.cpp \
    text.cpp \
    visualization.cpp

HEADERS  += wheatherchannel.hpp \
    line.hpp \
    serial.hpp \
    text.hpp \
    visualization.hpp

FORMS    += wheatherchannel.ui
