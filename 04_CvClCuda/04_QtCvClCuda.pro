# Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
# MIT License - https://github.com/ayaromenok/test/blob/master/LICENSE
QT += core gui widgets
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS
include(qt/opencv.pri)

HEADERS += \ 
    qtestobject.h \
    cvtestobject.h

SOURCES += \
	    mainQt.cpp \ 
    qtestobject.cpp \
    cvtestobject.cpp

RESOURCES += \
    qt/resources.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

