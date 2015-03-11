#include "utils.h"

QString Utils::getLinhaDigitavel(const QString &codigo)
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
