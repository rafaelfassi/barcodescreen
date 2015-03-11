#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include "qzxing.h"

class CaptureScreen;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void capture();
    void imageCaptured();

private:
    CaptureScreen *m_capScreen;
    QImage m_image;
    QZXing m_zXing;
};

#endif // MAINWINDOW_H
