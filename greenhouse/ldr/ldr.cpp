/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#include "ldr.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <cmath>

using namespace std;

namespace greenhouse {

    //Constructor
    ldr::ldr()
    {
        this->lightLevel = 0;
    }

    // Read current value from ldr
    // ADC = AIN + Id
    void readAnalog(int adcPin)
    {
        stringstream ss;
        ss << ADC_PIN_PATH << adcPin << "_raw";
        fstream fs;
        fs.open(ss.str().c_str(), fstream::in);
        fs >> adcPin;
        fs.close();
        this->lightLevel = this->mapVoltsToPercentage(adcPin);
    }

    float ldr::mapVoltsToPercentage(unsigned int value)
    {
        int min = 0;
        float max = 4095;
        //rounds the value to single decimal
        return floor((value/max * 100.0) * 10) / 10;
    }

    // update stored light level
    void ldr::readCurrentLightLevel()
    {
        ::greenhouse::readAnalog(ADC_PIN);
    }

}