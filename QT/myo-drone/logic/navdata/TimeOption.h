#ifndef TIMEOPTION_H
#define TIMEOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class TimeOption : public CuteNavdataOption
        {
        public:
            TimeOption(QByteArray& rawData);
            TimeOption();
            ~TimeOption();
            uint32_t getTime();
        private:
            uint32_t time;
        };
    }
}

#endif // TIMEOPTION_H
