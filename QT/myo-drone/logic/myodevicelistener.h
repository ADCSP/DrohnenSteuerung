#ifndef MYODEVICELISTENER_H
#define MYODEVICELISTENER_H
#include <MyoLibrary/include/myo/myo.hpp>


class MyoDeviceListener: public myo::DeviceListener
{

public:



   MyoDeviceListener();
   virtual void onArmSync(myo::Myo *myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection, float rotation, myo::WarmupState warmupState) override;
   virtual void onArmUnsync(myo::Myo *myo, uint64_t timestamp) override;
   virtual void onBatteryLevelReceived(myo::Myo *myo, uint64_t timestamp, uint8_t level) override;
   virtual void onPair(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion) override;
   virtual void onUnpair(myo::Myo *myo, uint64_t timestamp)override;
   virtual void onLock(myo::Myo *myo, uint64_t timestamp) override;
   virtual void onUnlock(myo::Myo *myo, uint64_t timestamp) override;
   virtual void onPose(myo::Myo *myo, uint64_t timestamp, myo::Pose pose)override;


};

#endif // MYODEVICELISTENER_H