#ifndef VIDEOSTREAMOPTION_H
#define VIDEOSTREAMOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class VideoStreamOption : public CuteNavdataOption
        {
        public:
            VideoStreamOption(QByteArray& rawData);
            VideoStreamOption();
            ~VideoStreamOption();
            uint8_t getQuant();
            uint32_t getFrameSize();
            uint32_t getFrameNumber();
            uint32_t getAtcmdRefSeq();
            uint32_t getAtcmdMeanRefGap();
            float getAtcmdVarRefGap();
            uint32_t getAtcmdRefQuality();
            uint32_t getOutBitrate();
            uint32_t getDesiredBitrate();
            int32_t getData1();
            int32_t getData2();
            int32_t getData3();
            int32_t getData4();
            int32_t getData5();
            uint32_t getTcpQueueLevel();
            uint32_t getFifoQueueLevel();
        private:
            uint8_t quant;
            uint32_t frameSize;
            uint32_t frameNumber;
            uint32_t atcmdRefSeq;
            uint32_t atcmdMeanRefGap;
            float atcmdVarRefGap;
            uint32_t atcmdRefQuality;
            uint32_t outBitrate;
            uint32_t desiredBitrate;
            int32_t data1;
            int32_t data2;
            int32_t data3;
            int32_t data4;
            int32_t data5;
            uint32_t tcpQueueLevel;
            uint32_t fifoQueueLevel;
        };
    }
}

#endif // VIDEOSTREAMOPTION_H
