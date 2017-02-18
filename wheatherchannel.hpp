#ifndef WHEATHERCHANNEL_HPP
#define WHEATHERCHANNEL_HPP

#include "serial.hpp"
#include "visualization.hpp"

#include <QMainWindow>
#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QVector>
#include <QString>
#include <QStringList>

namespace Ui {
class WheatherChannel;
}

class WheatherChannel : public QMainWindow
{
    Q_OBJECT

public:
    explicit WheatherChannel(QWidget *parent = 0);
    ~WheatherChannel();

private:
    Ui::WheatherChannel *ui;
    Serial *arduino;
    QTimer *timer;
    QVector<float> *temperature;

private slots:
    void getTemperature();
    void readArduino();
    void setVisualization();
    void setAutoTemperature();

signals:
    void newTemperature();
};

#endif // WHEATHERCHANNEL_HPP
