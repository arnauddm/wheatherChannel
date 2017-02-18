#include "line.hpp"

Line::Line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int width, QColor color)
{
    QBrush brush(color);
    QPen pen(brush, width);
    setPen(pen);
    setLine(x1, y1, x2, y2);
}

Line::~Line() {
    delete this;
}
