/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#ifndef GREENHOUSE_LDR_H
#define GREENHOUSE_LDR_H

/*
 *
 * THIS IS WRONG, IT MUST TAKE INPUT FROM AIN0
 *
 */
namespace greenhouse {

    class ldr {

    public:
        float lightLevel;

    private:
        unsigned int I2CBus, I2CAddress;

        float mapVoltsToPercentage(unsigned int value);

    public:
        ldr(unsigned int I2CBus);
        void readCurrentLightLevel();

    }; // class

} // Namespace



#endif //GREENHOUSE_LDR_H
