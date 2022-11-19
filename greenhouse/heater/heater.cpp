/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 17-11-2022
 */

#include "heater.h"

// turn on heater by writing to gpio pin
void heater::turnOnHeater()
{
    fs.open("/sys/class/gpio/gpio" + HEATER_PIN + "/value", std::fstream::out);
    fs << 1;
    fs.close();
}

// turn off heater by writing to gpio pin
void heater::turnOffHeater()
{
    fs.open("/sys/class/gpio/gpio" + HEATER_PIN + "/value", std::fstream::out);
    fs << 0;
    fs.close();
}

// Read the status of the heater: on or off
void heater::readHeaterStatus()
{
    struct stat st;
    if (stat("/sys/class/gpio/gpio" + HEATER_PIN, &st) == 0)
    {
        std::string val = readFile("/sys/class/gpio/gpio" + HEATER_PIN + "/value");
        if(val[0] == '1')
        {
            std::cout << "Heater:      on" << "    " << std::endl;
        }
        else
        {
            std::cout << "Heater:      off" << "    " << std::endl;
        }
    }
    else
    {
        std::cout << "Heater:      off" << "    " << std::endl;
    }
}