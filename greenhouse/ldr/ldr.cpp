/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#include "ldr.h"
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <iomanip>
#include <fstream>

using namespace std;

namespace greenhouse {


    //Constructor
    ldr::ldr(unsigned int I2CBus){
        this->lightLevel = I2CBus;
    }

    // Read current value from ldr
    void ldr::readCurrentLightLevel(){
        // Read from file and take only 4 character
        ifstream indata;
        char data[4];
        indata.open("/sys/bus/iio/devices/iio\:device0/in_voltage0_raw");
        indata >> data;
        indata.close();

        //Convert to int and map the value to be 0-100 percentage, then set it as the stored light level variable
        int value = atoi(data);
        this->lightLevel = this->mapVoltsToPercentage(value);
    }

    float ldr::mapVoltsToPercentage(unsigned int value){
        int min = 0;
        float max = 3700;
        //Also rounds the value to single decimal
        return floor((value/max * 100.0) * 10) / 10;
    }
}