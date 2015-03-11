#include "capturescreen.h"
#include "rubberband.h"
#include <QGuiApplication>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QScreen>
#include <QLabel>
#include <QImage>
//#include <QTimer>


CaptureScreen::CaptureScreen(QImage &image, QWidget *parent)
    : QWidget(parent), m_image(image), m_rubberBand(0)
{
    m_labScreen = new QLabel(this);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(m_labScreen);
    setLayout(layout);
    setCursor(Qt::CrossCursor);
}

CaptureScreen::~CaptureScreen()
{
}

void CaptureScreen::capture()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen)
    {
        m_labScreen->setPixmap(screen->grabWindow(0));
    }

    //QTimer::singleShot(1000, this, SLOT(showFullScreen()));
    showFullScreen();
}

void CaptureScreen::mousePressEvent(QMouseEvent *event)
{
    m_origin = event->pos();
    if (!m_rubberBand)
    {
        m_rubberBand = new RubberBand(QRubberBand::Rectangle, this);
    }
    m_rubberBand->setGeometry(QRect(m_origin, m_origin));
    m_rubberBand->show();
}

void CaptureScreen::mouseMoveEvent(QMouseEvent *event)
{
    m_rubberBand->setGeometry(QRect(m_origin, event->pos()).normalized());
}

void CaptureScreen::mouseReleaseEvent(QMouseEvent *)
{
    m_rubberBand->hide();

    QRect rec = m_rubberBand->geometry();
    m_image = m_labScreen->pixmap()->copy(rec).toImage();
    emit imageCaptured();
    this->close();
}
