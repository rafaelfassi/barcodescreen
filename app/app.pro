SRC_ROOT = $$PWD/..
OUT_PATH = $$OUT_PWD/..
LIB_PATH = $$OUT_PATH/bin/lib

QT       += core widgets quick

DESTDIR = $$OUT_PATH/bin

TARGET = BarcodeScreen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rubberband.cpp \
    capturescreen.cpp \
    utils.cpp

HEADERS  += mainwindow.h \
    rubberband.h \
    capturescreen.h \
    utils.h

INCLUDEPATH += \
    $$SRC_ROOT \
    $$SRC_ROOT/qzxing

DEPENDPATH += \
    $$SRC_ROOT \
    $$SRC_ROOT/qzxing

win32:CONFIG(release, debug|release): LIBS += -L$$LIB_PATH/release/ -lqzxing
 else:win32:CONFIG(debug, debug|release): LIBS += -L$$LIB_PATH/debug/ -lqzxing
 else:unix: LIBS += -L$$LIB_PATH/ -lqzxing

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$LIB_PATH/release/libqzxing.a
 else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$LIB_PATH/debug/libqzxing.a
 else:win32-msvc*:CONFIG(release, debug|release): PRE_TARGETDEPS += $$LIB_PATH/release/qzxing.lib
 else:win32-msvc*:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$LIB_PATH/debug/qzxing.lib
 else:unix:!symbian: PRE_TARGETDEPS += $$LIB_PATH/libqzxing.a
