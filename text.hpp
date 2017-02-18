#ifndef TEXT_HPP
#define TEXT_HPP

#include <QGraphicsTextItem>

class Text : public QGraphicsTextItem
{
public:
    Text(QString value, unsigned int x, unsigned int y);
    ~Text();

signals:

public slots:
};

#endif // TEXT_HPP
