#ifndef LINE_HPP
#define LINE_HPP

#include <QGraphicsLineItem>
#include <QPen>
#include <QBrush>
#include <QColor>

class Line : public QGraphicsLineItem
{
public:
    Line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int width, QColor color);
    ~Line();
};

#endif // LINE_HPP
