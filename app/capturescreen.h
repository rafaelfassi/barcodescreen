#ifndef CAPTURESCREEN_H
#define CAPTURESCREEN_H

#include <QWidget>

class QImage;
class QLabel;
class RubberBand;

class CaptureScreen : public QWidget
{
    Q_OBJECT
public:
    explicit CaptureScreen(QImage &image, QWidget *parent = 0);
    ~CaptureScreen();

    void capture();

signals:
    void imageCaptured();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QImage &m_image;
    QLabel *m_labScreen;
    RubberBand *m_rubberBand;
    QPoint m_origin;
};

#endif // CAPTURESCREEN_H
