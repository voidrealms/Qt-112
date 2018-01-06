#-------------------------------------------------
#
# Project created by QtCreator 2014-01-19T12:13:53
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = myzip1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

#Set variables
QUAZIPCODEDIR = "/home/rootshell/ZipVids/quazip-0.5.1/quazip"
ZLIBCODEDIR = "/home/rootshell/ZipVids/Libs"

#include the compiled code
unix {
    LIBS += -L$${ZLIBCODEDIR} -lz
}

win32 {
    LIBS += -L$${ZLIBCODEDIR} -lzdll
}

#include files
INCLUDEPATH += $${QUAZIPCODEDIR}
HEADERS += $${QUAZIPCODEDIR}/*.h
SOURCES += main.cpp
