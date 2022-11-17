/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 17-11-2022
 */

#include "Heater.h"

// function to turn on heater by writing to gpio pin
void heater::turnOnHeater()
{
    fs.open("/sys/class/gpio/gpio49/value", std::fstream::out);
    fs << 1;
    fs.close();
}

// function to turn off heater by writing to gpio pin
void heater::turnOffHeater()
{
    fs.open("/sys/class/gpio/gpio49/value", std::fstream::out);
    fs << 0;
    fs.close();
}