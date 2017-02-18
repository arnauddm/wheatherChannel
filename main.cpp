#include "wheatherchannel.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WheatherChannel w;
    w.show();

    return a.exec();
}
