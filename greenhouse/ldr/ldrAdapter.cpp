/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 19-11-2022
 */

#include "ldrAdapter.h"
#include "ldr.h"

namespace greenhouse {

    void ldrAdapter::init()
    {

    }

    /**
     * @brief Prints light level from reading the light depended resistor
     */
    void ldrAdapter::printLightLevel(int pinId)
    {
        greenhouse::ldr ldr(pinId);
        ldr.readCurrentLightLevel();
        std::cout << "Light level: " << ldr.lightLevel << "     " << std::endl;
    }

}