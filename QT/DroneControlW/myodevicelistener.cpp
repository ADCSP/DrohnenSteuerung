#include "myodevicelistener.h"

#include <QDebug>



MyoDeviceListener::MyoDeviceListener()
{

}

void  onArmSync(myo::Myo *myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection, float rotation, myo::WarmupState warmupState)
{
qDebug()<<"synced";
}

void onArmUnsync(myo::Myo *myo, uint64_t timestamp)
{
qDebug()<<"unsynced";
}

void onBatteryLevelReceived(myo::Myo *myo, uint64_t timestamp, uint8_t level)
{
qDebug()<<"battery"<<level;
}

void onPair(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion)
{
qDebug()<<"Paired";
}

void onUnpair(myo::Myo *myo, uint64_t timestamp)
{
qDebug()<<"unpaired";
}
void onLock(myo::Myo *myo, uint64_t timestamp)
{
qDebug()<<"locked";
}

void onUnlock(myo::Myo *myo, uint64_t timestamp)
{
qDebug()<<"unlocked";
}

void onPose(myo::Myo *myo, uint64_t timestamp, myo::Pose pose)
{
qDebug()<<"Pose";
}


