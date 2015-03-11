#include "mainwindow.h"
#include "capturescreen.h"
#include <QClipboard>
#include <QMessageBox>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QDebug>

//QSystemTrayIcon

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *button = new QPushButton("Capturar", this);
    m_capScreen = new CaptureScreen(m_image);
    setCentralWidget(button);

    connect(button, SIGNAL(clicked()), this, SLOT(capture()));
    connect(m_capScreen, SIGNAL(imageCaptured()), this, SLOT(imageCaptured()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::capture()
{
    showMinimized();
    m_capScreen->capture();
}

void MainWindow::imageCaptured()
{
    showNormal();

    if(!m_image.isNull())
    {
//        QLabel *myLabel = new QLabel(0);
//        myLabel->setPixmap(QPixmap::fromImage(m_image));
//        myLabel->show();

        QString strCode = m_zXing.decodeImage(m_image);

        if(!strCode.isEmpty())
        {
            QClipboard *clipboard = QApplication::clipboard();
            clipboard->setText(strCode);
            QMessageBox::information(this, "Ok", "O código foi copiado para a área de transferência\n" + strCode);
        }
        else
        {
            QMessageBox::warning(this, "Erro", "Não foi possível detectar o código da imagem");
        }

    }
    else
    {
        QMessageBox::warning(this, "Erro", "Imagem inválida");
    }
}
