/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 17-11-2022
 */

#include "heater.h"

// turn on heater by writing to gpio pin
void heater::turnOnHeater()
{
    fs.open("/sys/class/gpio/gpio49/value", std::fstream::out);
    fs << 1;
    fs.close();
}

// turn off heater by writing to gpio pin
void heater::turnOffHeater()
{
    fs.open("/sys/class/gpio/gpio49/value", std::fstream::out);
    fs << 0;
    fs.close();
}