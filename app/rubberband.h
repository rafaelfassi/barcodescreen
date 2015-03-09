#ifndef RUBBERBAND_H
#define RUBBERBAND_H

#include <QRubberBand>

class RubberBand : public QRubberBand
{
public:
    RubberBand(Shape s, QWidget *p = 0);

protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // RUBBERBAND_H
