QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include( ./communication/communication.pri )

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common.cpp \
    main.cpp \
    mainwindow.cpp \
    scan_code.cpp \
    up_load.cpp

HEADERS += \
    common.h \
    mainwindow.h \
    scan_code.h \
    up_load.h

FORMS += \
    mainwindow.ui \
    scan_code.ui \
    up_load.ui
    RC_ICONS = 1.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#程序版本
VERSION = 0.1.0.1

#程序名称
QMAKE_TARGET_PRODUCT = "monitor_mi_info"

DISTFILES +=
