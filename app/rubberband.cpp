#include "rubberband.h"
#include <QPainter>
#include <QDebug>

RubberBand::RubberBand(Shape s, QWidget *p)
    : QRubberBand(s, p)
{
}

void RubberBand::paintEvent(QPaintEvent *)
{
    QRect rec = rect();
    QMargins(0,0,-1,-1);

    rec =  rec + QMargins(0,0,-1,-1);

    QPainter painter(this);

    painter.setPen(QPen(Qt::lightGray, 1, Qt::DotLine));
    painter.drawRect(0, 0, rec.width(), rec.height());

    //QRubberBand::paintEvent(event);
}
