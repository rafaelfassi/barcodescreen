SRC_ROOT = $$PWD/..
OUT_PATH = $$OUT_PWD/..
LIB_PATH = $$OUT_PATH/bin/lib

VERSION = 1.2

QT += core gui widgets quick

TARGET = qzbar
TEMPLATE = lib

win32:CONFIG(release, debug|release): DESTDIR += $$LIB_PATH/release
 else:win32:CONFIG(debug, debug|release): DESTDIR += $$LIB_PATH/debug
 else:unix:!symbian: DESTDIR = $$LIB_PATH

CONFIG += staticlib

INCLUDEPATH  += \
    zbar \
    zbar/include \
    zbar/include/zbar

DEPENDPATH += \
    zbar \
    zbar/include \
    zbar/include/zbar

HEADERS += \
    qzbar.h \
    zbar/config.h \
    zbar/debug.h \
    zbar/error.h \
    zbar/symbol.h \
    zbar/processor.h \
    zbar/refcnt.h \
    zbar/timer.h \
    zbar/mutex.h \
    zbar/event.h \
    zbar/thread.h \
    zbar/window.h \
    zbar/video.h \
    zbar/img_scanner.h \
    zbar/decoder.h \
    zbar/image.h \
    zbar/decoder/ean.h \
    zbar/decoder/code128.h \
    zbar/decoder/code39.h \
    zbar/decoder/i25.h \
    zbar/qrcode.h \
    zbar/decoder/qr_finder.h \
    zbar/qrcode/qrdec.h \
    zbar/qrcode/rs.h \
    zbar/qrcode/isaac.h \
    zbar/qrcode/bch15_5.h \
    zbar/qrcode/binarize.h \
    zbar/qrcode/util.h \


SOURCES += \
    qzbar.cpp \
    zbar/config.c \
    zbar/error.c \
    zbar/symbol.c \
    zbar/convert.c \
    zbar/processor.c \
    zbar/processor/lock.c \
    zbar/refcnt.c \
    zbar/window.c \
    zbar/video.c \
    zbar/img_scanner.c \
    zbar/scanner.c \
    zbar/decoder.c \
    zbar/image.c \
    zbar/decoder/ean.c \
    zbar/decoder/code128.c \
    zbar/decoder/code39.c \
    zbar/decoder/i25.c \
    zbar/decoder/qr_finder.c \
    zbar/qrcode/qrdec.c \
    zbar/qrcode/qrdectxt.c \
    zbar/qrcode/rs.c \
    zbar/qrcode/isaac.c \
    zbar/qrcode/bch15_5.c \
    zbar/qrcode/binarize.c \
    zbar/qrcode/util.c \
    zbar/video/null.c \
    zbar/jpeg.c


win32:{

    HEADERS += \
        zbar/window/win.h

    SOURCES += \
        zbar/window/win.c \
        zbar/processor/win.c \
        zbar/window/dib.c

} else:unix:{

    HEADERS += \
        zbar/window/x.h \
        zbar/processor/posix.h

    SOURCES += \
        zbar/processor/posix.c \
        zbar/processor/xp.c \
        zbar/window/x.c \
        zbar/window/ximage.c

} else{

    SOURCES += \
        zbar/processor/null.c \
        zbar/window/null.c

}

defined(ENABLE_PDF417): {
    HEADERS += \
        zbar/decoder/pdf417.h \
        zbar/decoder/pdf417_hash.h

    SOURCES += \
        zbar/decoder/pdf417.c
}

defined(WITH_VFW): {
    SOURCES += \
        zbar/video/vfw.c
}

defined(HAVE_V4L1): {
    SOURCES += \
        zbar/video/v4l1.c
}

defined(HAVE_V4L2): {
    SOURCES += \
        zbar/video/v4l2.c
}

defined(HAVE_XV): {
    SOURCES += \
        zbar/window/xv.c
}

