#-------------------------------------------------
#
# Project created by QtCreator 2020-09-08T19:58:27
#
#-------------------------------------------------

QT       -= core gui

greaterThan(QT_MAJOR_VERSION, 4): QT -= widgets

TARGET = perfection
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
INCLUDEPATH += /usr/local/include \
               /usr/include/rapidxml

LIBS += -L/usr/lib/x86_64-linux-gnu/ \
        -lpqxx \
        -lpq

SOURCES += \
    dbmanager.cpp \
    main.cpp \
    xmlparser.cpp

HEADERS += \
    dbmanager.h \
    xmlparser.h

BUILDDIR = build/
unix:BUILDDIR = $$join(BUILDDIR,,,unix)
UI_DIR = $${BUILDDIR}/ui
UIC_DIR = $${BUILDDIR}/uic
MOC_DIR = $${BUILDDIR}/moc
RCC_DIR = $${BUILDDIR}/rcc
OBJECTS_DIR = $${BUILDDIR}/obj
