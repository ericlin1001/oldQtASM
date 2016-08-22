#-------------------------------------------------
#
# Project created by QtCreator 2013-03-08T19:57:00
#
#-------------------------------------------------

QT       += core gui

TARGET = netChat2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    CBasicClient.h

FORMS    += mainwindow.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/
else:symbian: LIBS +=
else:unix: LIBS += -L$$PWD/

INCLUDEPATH += $$PWD/

DEPENDPATH += $$PWD/

win32: LIBS += -L$$PWD/../lib/ -lClientdll

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib

OTHER_FILES += \
    Clientdll.lib

