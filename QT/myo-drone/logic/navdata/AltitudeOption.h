#ifndef ALTITUDEOPTION_H
#define ALTITUDEOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class AltitudeOption : public CuteNavdataOption
        {
        public:
            AltitudeOption(QByteArray& rawData);
            AltitudeOption();
            ~AltitudeOption();
            int32_t getAltitudeVision();
            float getAltitudeVz();
            int32_t getAltitudeRef();
            int32_t getAltitudeRaw();
            float getObsAccZ();
            float getObsAlt();
            vector<float> getObsX();
            uint32_t getObsState();
            vector<float> getEstVb();
            uint32_t getEstState();

        private:
            int32_t altitudeVersion;
            float altitudeVz;
            int32_t altitudeRef;
            int32_t altitudeRaw;
            float obsAccZ;
            float obsAlt;
            vector<float> obsX;
            uint32_t obsState;
            vector<float> estVb;
            uint32_t estState;
        };
    }
}

#endif // ALTITUDEOPTION_H
