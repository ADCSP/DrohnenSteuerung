
#include <QApplication>
#include <CVDrone.h>
#include <QFile>
#include <QDebug>
#include <MainWindow.h>
#include <provision.cpp>

using namespace Drone;

int main(int argc, char *argv[])
{
    /* Initialize the QT Framework*/
    QApplication a(argc, argv);
    Provision::initQMetaTypes();

    /* Load (or if not existing) create the config file*/
    ConfigFile& config = ConfigFile::getInstance();
    config.readFromFile();

    /* Initialize the nessesary objects */
    CVDrone&        drone = CVDrone::getInstance();
    MainWindow      window(&drone);

    /* Enter the event loop */
    window.show();
    return a.exec();
}
