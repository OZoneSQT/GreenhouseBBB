/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#include "hih8120.h"

#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <iomanip>

using namespace std;

namespace greenhouse {

    //Constructor
    hih8120::hih8120(unsigned int I2CBus, unsigned int I2CAddress):

    // initialisation calls parent constructor
    I2CDevice(I2CBus, I2CAddress)
    {
        // Set i2c device settings
        this->I2CAddress = I2CAddress;
        this->I2CBus = I2CBus;

        // Initialize basic variables
        this->temperature = -100;
        this->humidity = -100;
    }

    void hih8120::readCurrentTemperatureHumidity()
    {
        // Send signal to the temp/hum sensor and ask it to report back the readings
        // Ask for 4 bytes
        // Bytes are stored in char array and are unicode characters if printed which just represent a integer
        unsigned char* response = this->readDevice(4);

        // Check that the value is not bigger than 0b01111111
        if (response[0] > 127)
        {
            //Means the bits are set
            cout << "Bad status" << std::endl;
        }

        int adjustedRes0 = response[0];

        // if status 0b01... adjust it
        if (response[0] > 63)
        {
            adjustedRes0 = response[0] & ~(0x01 << 6);
        }

        //Concatenate most significant and least significant byte of humidity
        unsigned int humidity = adjustedRes0 << 8 | response[1];

        //Concatenate the first as most significant byte with the least significant byte.
        //Shift the least significant byte to right by two because last two bits do are not important.
        unsigned int temperature = response[2] << 6 | response[3] >> 2;

        //Map the values to human-readable form and set them in the object
        this->humidity = this->map14bitValueHumidity(humidity);
        this->temperature = this->map14bitValueTemperature(temperature);
    }

    // Map values by dividing them by max possible value and multiplying by possible range
    // for user readable one. Multiply by 10 and divide by 10 to specify decimal numbers after '.'
    float hih8120::map14bitValueHumidity(unsigned int value)
    {
        // Rounds the value to single decimal
        return floor((value/16383.0 * 100.0) * 10) / 10;
    }

    float hih8120::map14bitValueTemperature(unsigned int value)
    {
        return floor((value/16383.0 * 165.0 - 40.0) * 10) / 10;
    }

}