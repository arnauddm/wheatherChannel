#include "wheatherchannel.hpp"
#include "ui_wheatherchannel.h"

WheatherChannel::WheatherChannel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WheatherChannel)
{
    ui->setupUi(this);

        foreach (
                 const QSerialPortInfo &info, QSerialPortInfo::availablePorts()
                 ) {

            QString plain;
            plain += "Name : " + info.portName() + "\n";
            plain += "Description : " + info.description() + "\n";
            plain += "Manufacturer : " + info.manufacturer() + "\n";
            ui->outputText->appendPlainText(plain);
        }

        arduino = new Serial("cu.usbmodem1411");
        ui->outputText->appendPlainText("Connecté avec succès à : " + this->arduino->portName() + "\n");

        timer = new QTimer();

        //init vector and add first value
        temperature = new QVector<float>();
        temperature->push_back(0.0);

        connect(ui->getTemperature, SIGNAL(clicked(bool)), this, SLOT(getTemperature()));

        connect(arduino, SIGNAL(readyRead()), this, SLOT(readArduino()));

        connect(timer, SIGNAL(timeout()), this, SLOT(getTemperature()));

        connect(this, SIGNAL(newTemperature()), this, SLOT(setVisualization()));

        connect(ui->autoTemp, SIGNAL(toggled(bool)), this, SLOT(setAutoTemperature()));

        connect(ui->updateFreqAutoTemperature, SIGNAL(clicked(bool)), this, SLOT(setAutoTemperature()));
}

WheatherChannel::~WheatherChannel()
{
    delete ui;
}

void WheatherChannel::getTemperature() {
    if(!arduino->sendCmd("getTemp")) {
        ui->outputText->appendPlainText("Echec de l'envoie de la commande\n");
    } else {
        ui->outputText->appendPlainText("Commande envoyée avec succès\n");
    }
}

void WheatherChannel::readArduino() {
    QByteArray data(arduino->readAll());
    QString message(data);

    QStringList sMessage(message.split(":"));

    if(sMessage.at(0) == "temp") {
        QString value(sMessage.at(1));
        temperature->push_back(value.toFloat());
        emit newTemperature();
    }

    ui->outputText->appendPlainText("Donnée reçu : " + message + "\n");
}

void WheatherChannel::setVisualization()
{
    qDebug() << ui->visualizer->height() << ui->visualizer->width();
    Visualization *visu = new Visualization(*temperature, ui->visualizer->height(), ui->visualizer->width());
    ui->visualizer->setScene(visu);
}

void WheatherChannel::setAutoTemperature() {
    if(ui->autoTemp->isChecked()) {
        unsigned int time(ui->freqAutoTemperature->value() * 1000);
        timer->start(time);
        ui->outputText->appendPlainText("Mode d'auto mesures activé\n");
    } else {
        timer->stop();
        ui->outputText->appendPlainText("Mode d'auto mesure désactivé\n");
    }
}
