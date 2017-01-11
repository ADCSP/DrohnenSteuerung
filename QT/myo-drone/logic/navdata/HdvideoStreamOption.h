#ifndef HDVIDEOSTREAMOPTION_H
#define HDVIDEOSTREAMOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class HdvideoStreamOption : public CuteNavdataOption
        {
        public:
            HdvideoStreamOption(QByteArray& rawData);
            HdvideoStreamOption();
            ~HdvideoStreamOption();
            enum class HdvideoState : uint32_t {
                STORAGE_FIFO_IS_FULL    =   0,
                USBKEY_IS_PRESENT       =   8,
                USBKEY_IS_RECORDING     =   9,
                USBKEY_IS_FULL          =   10,
                NOT_DEFINED             =   1337    // self defined
            };

            static uint32_t decodeHdvideoState(HdvideoState state);
            static HdvideoState decodeHdvideoState(uint32_t state);

            HdvideoState getHdvideoState();
            uint32_t getStorageFifoNbPackets();
            uint32_t getStorageFifoSize();
            uint32_t getUsbkeySize();
            uint32_t getUsbkeyFreespace();
            uint32_t getFrameNumber();
            uint32_t getUsbkeyRemainingTime();
        private:
            HdvideoState hdvideoState;
            uint32_t storageFifoNbPackets;
            uint32_t storageFifoSize;
            uint32_t usbkeySize;
            uint32_t usbkeyFreespace;
            uint32_t frameNumber;
            uint32_t usbkeyRemainingTime;
        };
    }
}

#endif // HDVIDEOSTREAMOPTION_H
