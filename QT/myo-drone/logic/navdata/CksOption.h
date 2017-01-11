#ifndef CKSOPTION_H
#define CKSOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class CksOption : public CuteNavdataOption
        {
        public:
            CksOption(QByteArray& rawData);
            CksOption();
            ~CksOption();
            uint32_t getCks();
        private:
            uint32_t cks;
        };
    }
}

#endif // CKSOPTION_H
