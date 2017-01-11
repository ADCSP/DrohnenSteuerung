#ifndef VISIONDETECTOPTION_H
#define VISIONDETECTOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class VisionDetectOption : public CuteNavdataOption
        {
        public:
            VisionDetectOption(QByteArray& rawData);
            VisionDetectOption();
            ~VisionDetectOption();
            uint32_t getNbDetected() const;
            vector<uint32_t> getType() const;
            vector<uint32_t> getXc() const;
            vector<uint32_t> getYc() const;
            vector<uint32_t> getWidth() const;
            vector<uint32_t> getHeight() const;
            vector<uint32_t> getDistance() const;
            vector<float> getOrientationAngle() const;
            vector<vector<vector<float> > > getRotation() const;
            vector<vector<float> > getTranslation() const;
            vector<uint32_t> getCameraSource() const;

        private:
            uint32_t                       nbDetected;
            vector<uint32_t>               type;
            vector<uint32_t>               xc;
            vector<uint32_t>               yc;
            vector<uint32_t>               width;
            vector<uint32_t>               height;
            vector<uint32_t>               distance;
            vector<float>                   orientationAngle;
            vector<vector<vector<float>>>   rotation;
            vector<vector<float>>           translation;
            vector<uint32_t>               cameraSource;
        };
    }
}

#endif // VISIONDETECTOPTION_H
