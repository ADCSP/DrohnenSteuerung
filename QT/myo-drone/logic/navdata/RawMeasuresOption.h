#ifndef RAWMEASURESOPTION_H
#define RAWMEASURESOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class RawMeasuresOption : public CuteNavdataOption
        {
        public:
            RawMeasuresOption(QByteArray& rawData);
            RawMeasuresOption();
            ~RawMeasuresOption();
            vector<uint16_t> getRawAccs();
            vector<int16_t> getRawGyros();
            vector<int16_t> getRawGyros110();
            uint16_t getVbatRaw();
            uint16_t getUsDebutEcho();
            uint16_t getUsFinEcho();
            uint16_t getUsAssociationEcho();
            uint16_t getUsDistanceEcho();
            uint16_t getUsCourbeTemps();
            uint16_t getUsCourbeValeur();
            uint16_t getUsCourbeRef();
            uint16_t getFlagEchoIni();
            uint16_t getNbEcho();
            uint32_t getSumEcho();
            int32_t getAltTempRaw();
            int16_t getGradient();
        private:
            vector<uint16_t> rawAccs;
            vector<int16_t> rawGyros;
            vector<int16_t> rawGyros110;
            uint16_t vbatRaw;
            uint16_t usDebutEcho;
            uint16_t usFinEcho;
            uint16_t usAssociationEcho;
            uint16_t usDistanceEcho;
            uint16_t usCourbeTemps;
            uint16_t usCourbeValeur;
            uint16_t usCourbeRef;
            uint16_t flagEchoIni;
            uint16_t nbEcho;
            uint32_t sumEcho;
            int32_t altTempRaw;
            int16_t gradient;
        };
    }
}

#endif // RAWMEASURESOPTION_H
