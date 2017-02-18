#include "serial.hpp"

Serial::Serial(const QString &portName)
{
    init(portName);
}

Serial::~Serial() {
    if(this->isOpen()) {
        this->close();
        delete this;
    }
}

void Serial::init(const QString &portName) {
    this->setBaudRate(QSerialPort::Baud115200);
    this->setDataBits(QSerialPort::Data8);
    this->setFlowControl(QSerialPort::NoFlowControl);
    this->setParity(QSerialPort::NoParity);
    this->setStopBits(QSerialPort::OneStop);
    this->setPortName(portName);
    this->open(QSerialPort::ReadWrite);
}

bool Serial::sendCmd(const QString &command) {
    if(!this->isWritable())
        return false;
    else {
        this->write(command.toStdString().c_str());
        return true;
    }
}

bool Serial::sendCmdLn(QString &command) {
    command += "\n";
    this->sendCmd(command);
}
