#ifndef QZBAR_H
#define QZBAR_H

#include <QObject>
#include <QImage>
#include <QtQuick>


enum BarCodeTypes {
    BCTP_NONE,
    BCTP_PARTIAL,
    BCTP_EAN_8,
    BCTP_EAN_13,
    BCTP_UPC_A,
    BCTP_UPC_E,
    BCTP_ISBN10,
    BCTP_UPCA,
    BCTP_ISBN13,
    BCTP_I25,
    BCTP_CODE_39,
    BCTP_CODE_128,
    BCTP_PDF417,
    BCTP_QRCODE,
    BCTP_SYMBOL,
    BCTP_ADDON,
    BCTP_ADDON_2,
    BCTP_ADDON_5,
    BCTP_AZTEC,
    BCTP_DATA_MATRIX
};

class QZBar : public QObject
{
    Q_OBJECT
public:
    QZBar(QObject *obj=0);
    QString decodeImage(QImage image, int *type = 0);
};



#endif // QZBAR_H
