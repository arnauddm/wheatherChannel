#include "visualization.hpp"

Visualization::Visualization(const QVector<float> &temperature, const unsigned int height, const unsigned int width)
{
    setSceneRect(0, 0, width - 10, height - 10);

    unsigned int intervalH(getScale(temperature, height));
    unsigned int intervalW((width - 10) / temperature.size());

    drawScale(height, width, intervalH);

    for(unsigned int i(1) ; i < temperature.size() ; i++) {
        //addLine(intervalW * i, height - (temperature.at(i - 1) * intervalH), intervalW * (i + 1), height - (temperature.at(i) * intervalH));

        Line *line = new Line(intervalW * i, height - (temperature.at(i - 1) * intervalH), intervalW * (i + 1), height - (temperature.at(i) * intervalH), 3, Qt::red);
        addItem(line);
    }
}

int Visualization::getScale(const QVector<float> &temperature, const unsigned int height) {
    float max;
    for(unsigned int i(0) ; i < temperature.size() ; i++) {
        if(i == 0 || temperature.at(i) > max)
            max = temperature.at(i);
    }

    return height / (max + 3);
}

void Visualization::drawScale(unsigned int height, unsigned int width, unsigned int scale) {
    unsigned int nb(height / scale);

    for(unsigned int i(0) ; i < height / scale ; i++) {
        //line graduation
        Line *line = new Line(0, (nb - i) * scale, width, (nb - i) * scale, 1, Qt::gray);
        addItem(line);

        //text
        Text *text = new Text(QString::number(i), 10, ((nb - i) * scale) - 20);
        addItem(text);
    }

    //legend for temperature
    Line *line = new Line(100, 10, 140, 10, 3, Qt::red);
    Text *text = new Text("Température", 150, 1);
    addItem(line);
    addItem(text);
}
