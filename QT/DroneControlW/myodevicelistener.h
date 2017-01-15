#ifndef MYODEVICELISTENER_H
#define MYODEVICELISTENER_H
#include "myo/myo.hpp"

class MyoDeviceListener: public myo::DeviceListener
{

public:



    MyoDeviceListener();
    void onArmSync();
    void onArmUnsync();
    void onBatteryLevelReceived();
    void onPair();
    void onUnpair();

    void onLock();
    void onUnlock();
    void onPose();


};

#endif // MYODEVICELISTENER_H
