#include "bluetooth.h"
#include <qbluetoothdevicediscoveryagent.h>
#include <QBluetoothLocalDevice>
#include <qbluetoothdeviceinfo.h>
#include <QDebug>
#include <QBluetoothAddress>

    Bluetooth::Bluetooth()
    {


    }

    void Bluetooth::connectBT()
    {

    QBluetoothLocalDevice localeDev;
    //QString localeDevName;
    QBluetoothAddress addr("cb:a6:04:ac:5f:c3");

    if (localeDev.isValid())
    {


    localeDev.powerOn();


    localeDev.requestPairing(addr,QBluetoothLocalDevice::Paired);

    qDebug()<<localeDev.pairingStatus(addr)<<"Verbundene Devices";

    //  localeDevName = localeDev.name();

    //     qDebug()<<localeDevName<< "Test";

    while (1)
    {

    if (localeDev.pairingStatus(addr)==QBluetoothLocalDevice::Paired)
        {
     qDebug()<<"Paired!";
     break;

        }
    }

   }
 }
