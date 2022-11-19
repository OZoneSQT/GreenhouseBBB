/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 17-11-2022
 */

#ifndef GREENHOUSE_HEATER_H
#define GREENHOUSE_HEATER_H

#include "../settings.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sys/stat.h>

class heater{
public:

    heater()
    {
        struct stat st;

        //Check if gpio49 / P9_23 is initializes
        if(!stat("/sys/class/gpio/gpio" + HEATER_PIN,&st) == 0)
        {
            //Create the file
            fs.open("/sys/class/gpio/export", std::fstream::out);
            fs << 49;
            fs << HEATER_PIN;
            fs.close();
        }

        // Set output
        fs.open("/sys/class/gpio/gpio" + HEATER_PIN + "/direction", std::fstream::out);
        fs << "out";
        fs.close();
    }

    void turnOnHeater();
    void turnOffHeater();
    void readHeaterStatus();

private:
    std::fstream fs;
};

#endif
