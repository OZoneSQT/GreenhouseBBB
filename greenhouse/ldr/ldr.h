/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#ifndef GREENHOUSE_LDR_H
#define GREENHOUSE_LDR_H

namespace greenhouse {

#define LDR_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#define ADC_PIN 0 // P9_39 / AIN0

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