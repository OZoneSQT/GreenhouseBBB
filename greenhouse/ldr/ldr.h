/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#ifndef GREENHOUSE_LDR_H
#define GREENHOUSE_LDR_H

namespace greenhouse {

#include "../settings.h"

    class ldr {

    public:
        float lightLevel;

    private:
        float mapVoltsToPercentage(unsigned int value);
        void readAnalog();

    public:
        ldr();
        void readCurrentLightLevel();

    };

}

#endif