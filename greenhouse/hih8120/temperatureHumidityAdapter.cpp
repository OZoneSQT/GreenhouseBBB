/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 19-11-2022
 */

#include "temperatureHumidityAdapter.h"
#include "hih8120.h"

namespace greenhouse {

    /**
     * @brief Read temperature and humidity form hih8180.
     */
    void temperatureHumidityAdapter::printTemperatureAndHumidity()
    {
        greenhouse::hih8120 hih8120(2, ADDR);
        hih8120.readCurrentTemperatureHumidity();
        std::cout << "Temperature: " << hih8120.temperature << "     " << std::endl;
        std::cout << "Humidity:    " << hih8120.humidity << "     " << std::endl;
    }

    /**
     * @brief Read temperature form hih8180.
     */
    void temperatureHumidityAdapter::printTemperature()
    {
        greenhouse::hih8120 hih8120(2, ADDR);
        hih8120.readCurrentTemperatureHumidity();

        std::cout << "Temperature: " << hih8120.temperature << "     " << std::endl;
    }

    /**
     * @brief Read humidity form hih8180.
     */
    void temperatureHumidityAdapter::printHumidity()
    {
        greenhouse::hih8120 hih8120(2, ADDR);
        hih8120.readCurrentTemperatureHumidity();
        std::cout << "Humidity:    " << hih8120.humidity << "     " << std::endl;
    }

}