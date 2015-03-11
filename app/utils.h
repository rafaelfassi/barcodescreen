#ifndef UTILS_H
#define UTILS_H

#include <QString>

class Utils
{
public:
    static QString getLinhaDigitavel(const QString &codigo);
    static QString getModulo10(QString bloco);
};

#endif // UTILS_H
