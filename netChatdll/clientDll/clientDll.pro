#-------------------------------------------------
#
# Project created by QtCreator 2013-03-08T23:28:48
#
#-------------------------------------------------

QT       -= core gui

TARGET = clientDll
TEMPLATE = lib

DEFINES += CLIENTDLL_LIBRARY

SOURCES += \
    CBasicClient.cpp

HEADERS +=\
        clientDll_global.h \
    CBasicClient.h
LIBS+=-lWs2_32
symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE5F97427
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = clientDll.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}




