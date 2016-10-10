#ifndef UTILS_H
#define UTILS_H

#include <QString>

class Utils
{
public:
    static QString getLinhaDigitavel(const QString &codigo);
    static QString formatBoletoBanc(const QString &codigo);
    static QString formatTributo(const QString &codigo, int modulo);
    static bool validateTributo(const QString &codigo, int &modulo);
    static bool validateBoletoBanc(const QString &codigo);
    static QString getModulo10(QString bloco);
    static QString getModulo11(QString bloco, bool subtract = true);
};

#endif // UTILS_H
