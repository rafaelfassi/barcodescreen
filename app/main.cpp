#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


//#include "test.h"
//int main()
//{
//    Test::testBoletoBanc();
//    Test::testTributo();

//    return 0;
//}
