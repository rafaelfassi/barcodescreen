SRC_ROOT = $$PWD/..
OUT_PATH = $$OUT_PWD/..
LIB_PATH = $$OUT_PATH/bin/lib

VERSION = 1.2

QT += core gui widgets quick

TARGET = qzbar
TEMPLATE = lib

win32:CONFIG(release, debug|release): DESTDIR += $$LIB_PATH/release
 else:win32:CONFIG(debug, debug|release): DESTDIR += $$LIB_PATH/debug
 else:unix: DESTDIR = $$LIB_PATH

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
    zbar/refcnt.h \
    zbar/timer.h \
    zbar/mutex.h \
    zbar/event.h \
    zbar/thread.h \
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
    zbar/qrcode/util.h


SOURCES += \
    qzbar.cpp \
    zbar/config.c \
    zbar/error.c \
    zbar/symbol.c \
    zbar/refcnt.c \
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
    zbar/qrcode/util.c


