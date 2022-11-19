/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#ifndef GREENHOUSE_HIH8120_H
#define GREENHOUSE_HIH8120_H

#include "../settings.h"
#include "../I2CDevice.h"

namespace greenhouse {

    //Inherit from i2c helper class
    class hih8120: protected exploringBB::I2CDevice {

    public:
        unsigned int i2xc;
        float temperature;
        float humidity;

    private:
        unsigned int I2CBus, I2CAddress;

        float map14bitValueHumidity(unsigned int value);
        float map14bitValueTemperature(unsigned int value);

    public:
        hih8120(unsigned int I2CBus, unsigned int I2CAddress=HIH8120_ADDRESS);
        void readCurrentTemperatureHumidity();

    };

}

#endif