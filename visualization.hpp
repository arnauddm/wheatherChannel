#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include "line.hpp"
#include "text.hpp"

#include <QVector>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QColor>
#include <QString>

class Visualization : public QGraphicsScene
{
public:
    Visualization(const QVector<float> &temperature, const unsigned int height, const unsigned int width);

    int getScale(const QVector<float> &temperature, const unsigned int height);
    void drawScale(unsigned int height, unsigned int width, unsigned int scale);
};

#endif // VISUALIZATION_HPP
