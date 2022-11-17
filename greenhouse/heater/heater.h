/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 17-11-2022
 */

#ifndef GREENHOUSE_HEATER_H
#define GREENHOUSE_HEATER_H

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include <sys/stat.h>

// gpio49 = P9_23
class heater{
public:

    //Constructor that initializes gpio50 if it is not initialized and then sets it to output
    heater()
    {

        struct stat st;
        //Check if gpio49 already exists
        if(!stat("/sys/class/gpio/gpio49",&st) == 0)
        {
            //Create the file
            fs.open("/sys/class/gpio/export", std::fstream::out);
            fs << 50;
            fs.close();
        }

        // Set it to output
        fs.open("/sys/class/gpio/gpio49/direction", std::fstream::out);
        fs << "out";
        fs.close();
    }

    void turnOnHeater();
    void turnOffHeater();
    void isHeaterOn();

private:
    std::fstream fs;
};

#endif //GREENHOUSE_HEATER_H
