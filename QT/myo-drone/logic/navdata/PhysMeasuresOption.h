#ifndef PHYSMEASURESOPTION_H
#define PHYSMEASURESOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class PhysMeasuresOption : public CuteNavdataOption
        {
        public:
            PhysMeasuresOption(QByteArray& rawData);
            PhysMeasuresOption();
            ~PhysMeasuresOption();
            float getAccsTemp();
            uint16_t getGyroTemp();
            vector<float> getPhysAccs();
            vector<float> getPhysGyros();
            uint32_t getAlim3v3();
            uint32_t getVrefEpson();
            uint32_t getVrefIdg();
        private:
            float accsTemp;
            uint16_t gyroTemp;
            vector<float> physAccs;
            vector<float> physGyros;
            uint32_t alim3v3;
            uint32_t vrefEpson;
            uint32_t vrefIdg;
        };
    }
}

#endif // PHYSMEASURESOPTION_H
