/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 19-11-2022
 */

#include "heaterAdapter.h"
#include "heater.h"

namespace greenhouse {

    heaterAdapter::heaterAdapter() {}

    /**
     * @brief Set heater to "on"
     */
    void heaterAdapter::on()
    {
        heaterOnOff("on");
    }

    /**
     * @brief Set heater to "off"
     */
    void heaterAdapter::off()
    {
        heaterOnOff("off");
    }

    /**
     * @brief Turns heater on or off depending if a correct string is passed.
     *
     * @param i = string which indicates if to turn on heater or turn off
     */
    void heaterOnOff(std::string i) {
        heater::heater heater;
        if (i == "on") {
            heater.turnOnHeater();
        } else if (i == "off") {
            heater.turnOffHeater();
        }
    }

    /**
     * @brief Read the status of the heater: on or off
     */
     void heaterAdapter::isRunning()
     {
         heater::heater heater;
         heater.readHeaterStatus();
     }

}