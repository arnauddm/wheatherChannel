#include "text.hpp"

Text::Text(QString value, unsigned int x, unsigned int y)
{
    setPlainText(value);
    setPos(x, y);
}

Text::~Text() {
    delete this;
}
