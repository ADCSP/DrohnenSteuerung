#include "myodevicelistener.h"

#include <QDebug>



MyoDeviceListener::MyoDeviceListener()
{

}

void MyoDeviceListener:: onArmSync(myo::Myo *myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection, float rotation, myo::WarmupState warmupState)
{

qDebug()<<"synced";
}

void MyoDeviceListener::onArmUnsync(myo::Myo *myo, uint64_t timestamp)
{
qDebug()<<"unsynced";
}

void MyoDeviceListener::onBatteryLevelReceived(myo::Myo *myo, uint64_t timestamp, uint8_t level)
{
qDebug()<<"battery"<<level;
}

void MyoDeviceListener::onPair(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion)
{
qDebug()<<"Paired";
}

void MyoDeviceListener::onUnpair(myo::Myo *myo, uint64_t timestamp)
{
qDebug()<<"unpaired";
}
void MyoDeviceListener::onLock(myo::Myo *myo, uint64_t timestamp)
{
qDebug()<<"locked";
}

void MyoDeviceListener:: onUnlock(myo::Myo *myo, uint64_t timestamp)
{
qDebug()<<"unlocked";
}

void MyoDeviceListener::onPose(myo::Myo *myo, uint64_t timestamp, myo::Pose pose)
{

        switch(pose.type())
        {
        case 1: qDebug()<<"Fist";
            myo->notifyUserAction();
            break;
        case 2: qDebug()<<"Wave in";
            myo->notifyUserAction();
            break;
        case 3: qDebug()<<"Wave out";
            myo->notifyUserAction();
            break;
        case 4: qDebug()<<"Spread Fingers";
            myo->notifyUserAction();
            break;
        }
        myo->unlock(myo->unlockHold);

        if (pose.type()==5)
        {
            qDebug()<<"double tapped";
            qDebug()<<"Lock.";
         myo->lock();
        }
}


