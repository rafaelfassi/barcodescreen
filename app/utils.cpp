#include "utils.h"

QString Utils::getLinhaDigitavel(const QString &codigo)
{
    if(codigo.size() == 44)
    {
        if(codigo.at(0) == '8')
        {
            if(validateTributo(codigo))
                return formatTributo(codigo);
        }
        else
        {
            if(validateBoletoBanc(codigo))
                return formatBoletoBanc(codigo);
        }
    }

    return QString();
}

QString Utils::formatBoletoBanc(const QString &codigo)
{
    QString cmp1;
    cmp1 = codigo.mid(0, 4);
    cmp1 += codigo.mid(19, 5);
    cmp1 += getModulo10(cmp1);

    QString cmp2;
    cmp2 += codigo.mid(24, 10);
    cmp2 += getModulo10(cmp2);

    QString cmp3;
    cmp3 += codigo.mid(34, 10);
    cmp3 += getModulo10(cmp3);

    QString cmp4;
    cmp4 += codigo.mid(4, 1);

    QString cmp5;
    cmp5 += codigo.mid(5, 4);
    cmp5 += codigo.mid(9, 10);

    cmp1.insert(5, ".");
    cmp2.insert(5, ".");
    cmp3.insert(5, ".");


    return cmp1 + " " + cmp2 + " " + cmp3 + " " + cmp4 + " " + cmp5;
}

QString Utils::formatTributo(const QString &codigo)
{
    QString res;
    const int blockSize(11);
    for(int from = 0; from < 4*blockSize; from += blockSize)
    {
        QString block;
        block = codigo.mid(from, blockSize);
        res += (res.size() ? " " : "") + block + getModulo10(block);
    }

    return res;
}

bool Utils::validateTributo(const QString &codigo)
{
    QString dac = codigo.mid(3, 1);
    QString indicator = codigo.mid(2, 1);
    QString digits = codigo.mid(0, 3) + codigo.mid(4);
    if(indicator == "6" || indicator == "7")
        return dac == getModulo10(digits);
    else
        return dac == getModulo11(digits, false);
}

bool Utils::validateBoletoBanc(const QString &codigo)
{
    QString dac = codigo.mid(4, 1);
    QString digits = codigo.mid(0, 4) + codigo.mid(5);
    return dac == getModulo11(digits);
}

QString Utils::getModulo10(QString bloco)
{
    int fator = 2;
    int dig(0);

    for(int i = bloco.size()-1; i >= 0; --i)
    {
        bool ok;
        int n = bloco.mid(i, 1).toInt(&ok);
        if(ok)
            n *= fator;
        else
            return QString();

        dig += n/10 + n%10;

        if(fator == 2)
            fator = 1;
        else
            fator = 2;
    }

    dig = 10 - ( dig % 10 );
    if(dig == 10)
        dig = 0;

    return QString::number(dig);
}

QString Utils::getModulo11(QString bloco, bool subtract)
{
    int fator = 2;
    int dig(0);

    for(int i = bloco.size()-1; i >= 0; --i)
    {
        bool ok;
        int n = bloco.mid(i, 1).toInt(&ok);
        if(ok)
            n *= fator;
        else
            return QString();

        dig += n;

        if(++fator > 9)
            fator = 2;
    }

    if(subtract)
    {
        dig = 11 - (dig % 11);
        if(dig < 1 || dig > 9 )
            dig = 1;
    }
    else
    {
        dig = dig % 11;
    }

    return QString::number(dig);
}
