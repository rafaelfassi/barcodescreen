#include "qzbar.h"
#include "iostream"

#include <zbar.h>

QZBar::QZBar(QObject *obj) : QObject(obj)
{
}

QString QZBar::decodeImage(QImage image, int *type)
{
    QString res;

    unsigned char* raw = (unsigned char*)malloc(image.width()*image.height()*sizeof(unsigned char));

    int cnt = 0;
    for(int l=0; l<image.height(); ++l)
    {
        for(int c=0; c<image.width(); ++c)
        {
            raw[cnt++] = qGray(image.pixel(c,l));
        }
    }

    zbar::Image zbImage(image.width(), image.height(), "Y800", raw, image.width() * image.height());

    zbar::ImageScanner scanner;

    scanner.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);

    int n = scanner.scan(zbImage);


    for(zbar::Image::SymbolIterator symbol = zbImage.symbol_begin();
        symbol != zbImage.symbol_end();
        ++symbol)
    {
        QString simbData(symbol->get_data().c_str());
        if(simbData.size() > res.size()) // Caso seja encontrado mais de um barcode, sera usado o maior
        {
            res = simbData;
            if(type)
                *type = symbol->get_type();
        }

//        std::cout  << "decoded " << symbol->get_type_name() << " - "
//                   << symbol->get_data() << std::endl;
    }

    delete []raw;
    zbImage.set_data(0, 0);

    return res;
}
