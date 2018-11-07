TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    transferfunction.cpp \
    cascade_filter.cpp

HEADERS += \
    transferfunction.h \
    cascade_filter.h \
    section.h
