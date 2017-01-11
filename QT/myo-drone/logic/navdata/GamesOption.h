#ifndef GAMESOPTION_H
#define GAMESOPTION_H

#include <QByteArray>

#include <CuteNavdataOption.h>

namespace Drone
{
    namespace Navdata
    {
        class GamesOption : public CuteNavdataOption
        {
        public:
            GamesOption(QByteArray& rawData);
            GamesOption();
            ~GamesOption();
            uint32_t getDoubleTapCounter();
            uint32_t getFinishLineCounter();
        private:
            uint32_t doubleTapCounter;
            uint32_t finishLineCounter;
        };
    }
}

#endif // GAMESOPTION_H
