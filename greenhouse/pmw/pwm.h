/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#ifndef GREENHOUSE_PWM_H
#define GREENHOUSE_PWM_H

#include "../I2CDevice.h"

namespace greenhouse {

//Inherit from the i2c helper class
    class hih8120: protected exploringBB::I2CDevice {

    public:
        // class variables
        unsigned int i2xc;
        float temperature;
        float humidity;

    private:
        //Private functions and variables
        unsigned int I2CBus, I2CAddress;

        float map14bitValueHumidity(unsigned int value);
        float map14bitValueTemperature(unsigned int value);

    public:
        //Functions for the user
        hih8120(unsigned int I2CBus, unsigned int I2CAddress=0x53);
        void readCurrentTemperatureHumidity();

    }; // class

} // Namespace

#endif //GREENHOUSE_PWM_H
