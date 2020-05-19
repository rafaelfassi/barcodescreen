SRC_ROOT = $$PWD/..
OUT_PATH = $$OUT_PWD/..
LIB_PATH = $$OUT_PATH/bin/lib
LIB_ZBAR = $$SRC_ROOT/qzbar/zbar/lib/

QT += core widgets quick

DESTDIR = $$OUT_PATH/bin

TARGET = BarcodeScreen
TEMPLATE = app


SOURCES += \
    main.cpp\
    mainwindow.cpp \
    rubberband.cpp \
    capturescreen.cpp \
    utils.cpp \
    test.cpp

HEADERS  += \
    mainwindow.h \
    rubberband.h \
    capturescreen.h \
    utils.h \
    test.h

INCLUDEPATH += \
    $$SRC_ROOT \
    $$SRC_ROOT/qzxing \
    $$SRC_ROOT/qzbar

DEPENDPATH += \
    $$SRC_ROOT \
    $$SRC_ROOT/qzxing \
    $$SRC_ROOT/qzbar

win32:CONFIG(release, debug|release): LIBS += -L$$LIB_PATH/release/ -lqzxing -lqzbar
 else:win32:CONFIG(debug, debug|release): LIBS += -L$$LIB_PATH/debug/ -lqzxing -lqzbar
 else:unix: LIBS += -L$$LIB_PATH/ -lqzxing -lqzbar

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$LIB_PATH/release/libqzxing.a $$LIB_PATH/release/libqzbar.a
 else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$LIB_PATH/debug/libqzxing.a $$LIB_PATH/debug/libqzbar.a
 else:unix: PRE_TARGETDEPS += $$LIB_PATH/libqzxing.a $$LIB_PATH/libqzbar.a

win32: LIBS += -liconv
