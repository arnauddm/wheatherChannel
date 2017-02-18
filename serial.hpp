#ifndef SERIAL_HPP
#define SERIAL_HPP

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class Serial : public QSerialPort
{
    Q_OBJECT
public:
    Serial(const QString &portName);
    ~Serial();
    void init(const QString &portName);
    bool sendCmd(const QString &command);
    bool sendCmdLn(QString &command);
};

#endif // SERIAL_HPP
