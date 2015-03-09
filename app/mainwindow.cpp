#include "mainwindow.h"
#include "rubberband.h"
#include <QMouseEvent>
#include <QLabel>
#include <QGuiApplication>
#include <QApplication>
#include <QScreen>
#include <QClipboard>
#include <QMessageBox>
#include <QDebug>

//QSystemTrayIcon

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_rubberBand(0)
{
    //setWindowFlags( Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Tool);
    //setAttribute(Qt::WA_TranslucentBackground);

    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

MainWindow::~MainWindow()
{

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_origin = event->pos();
    if (!m_rubberBand)
    {
        m_rubberBand = new RubberBand(QRubberBand::Rectangle, this);
    }
    m_rubberBand->setGeometry(QRect(m_origin, QSize()));
    m_rubberBand->show();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    m_rubberBand->setGeometry(QRect(m_origin, event->pos()).normalized());
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

    m_rubberBand->hide();
    update();

    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen)
    {
        QRect rec = m_rubberBand->geometry();
        QImage image = screen->grabWindow(0, rec.x(), rec.y(), rec.width(), rec.height()).toImage();

        if(!image.isNull())
        {
            QString strCode = m_zXing.decodeImage(image);

            if(!strCode.isEmpty())
            {
                QClipboard *clipboard = QApplication::clipboard();
                clipboard->setText(strCode);
                QMessageBox::information(this, "Ok", "O código foi copiado para a área de transferência\n" + strCode);
                this->close();
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


//        QLabel *myLabel = new QLabel(0);
//        QRect rec = m_rubberBand->geometry();
//        rec.moveTopLeft(mapToGlobal(rec.topLeft()));
//        myLabel->setPixmap(screen->grabWindow(0, rec.x(), rec.y(), rec.width(), rec.height()));
//        myLabel->show();
    }
    else
    {
        QMessageBox::critical(this, "Erro", "Não foi possível obter a imagem da tela");
    }




    // determine selection, for example using QRect::intersects()
    // and QRect::contains().
}
