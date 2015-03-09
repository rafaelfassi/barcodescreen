!equals(QT_MAJOR_VERSION, 5)|lessThan(QT_MINOR_VERSION, 1) {
        error('BarcodeScreen requires Qt version 5.1 or greater')
}

TEMPLATE  = subdirs
CONFIG   += ordered

SUBDIRS += \
    qzxing \
    app
