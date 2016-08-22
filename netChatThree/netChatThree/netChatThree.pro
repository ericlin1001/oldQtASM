#-------------------------------------------------
#
# Project created by QtCreator 2013-03-08T20:33:24
#
#-------------------------------------------------

QT       += core gui

TARGET = netChatThree
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loginpanel.cpp

HEADERS  += mainwindow.h\
CBasicClient.h \
    loginpanel.h

FORMS    += mainwindow.ui \
    loginpanel.ui
LIBS += -L$$PWD\ -lclientdll



