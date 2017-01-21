
#include <QApplication>
#include <CVDrone.h>
#include <QFile>
#include <QDebug>
#include <MainWindow.h>
//#include <ObjectDetector.h>
#include <provision.cpp>
#include "threadhandler.h"

using namespace Drone;
//using namespace ObjectDetection;

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
    //ObjectDetector  detector(drone.getVideoService());
    //MainWindow      window(&drone, &detector);



    MainWindow      window(&drone);

    //ThreadHandler* handler = new ThreadHandler();
    //handler->StartThread();

    /* Enter the event loop */
    window.show();
    return a.exec();
}
