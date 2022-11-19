/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#include "hih8120/hih8120.h"
#include "ldr/ldr.h"
#include "pwm/pwm.h"
#include "heater/heater.h"
#include <iostream>

/**
 * @brief Helper function to read text from files
 * 
 * @param path path to file.
 * @return std::string text from file
 */
std::string readFile(std::string path) {
    std::ifstream fs;
    std::string data;
    fs.open(path);
    fs >> data;
    fs.close();
    return data;
}

int main(int argc, char **argv) {
    //Check that there are enough variables
    if (argc >= 2) {

        //Check what functionality the user wants to 
        //perform and directs it to the appropriate function

        //Functions either scan a peripheral and print the details to console or just read some file and print to console prints.
        if (std::string(argv[1]) == "--help") {

            std::cout << std::endl << "Greenhouse device features arguments: " << std::endl << std::endl
                      << "readTempAndHumidity - Prints current temperature (C) and humidity (RH%) in greenhouse."<< std::endl
                      << "readTemp - Prints current temperature (C) in greenhouse." << std::endl
                      << "readHumidity - Prints current humidity (RH%)in greenhouse." << std::endl
                      << "readLightLevel - Prints current light level in greenhouse." << std::endl
                      << "setLedLight - controls led light intensity. Params from 0 to 100 ." << std::endl
                      << "readLedLight - Prints led light intensity. From 0% to 100%" << std::endl
                      << "setWindowStatus - controls window in greenhouse. Params open, half open or close ." << std::endl
                      << "readWindow - reads position,open, half open or close ." << std::endl
                      << "readHeater - reads status,on or off ." << std::endl
                      << "setHeaterStatus - controls heater in greenhouse.Params on or off ." << std::endl;

        } else if (std::string(argv[1]) == "readTempAndHumidity") {

            printTemperatureAndHumidity();

        } else if (std::string(argv[1]) == "readTemp") {

            printTemperature();

        } else if (std::string(argv[1]) == "readHumidity") {

            printHumidity();

        } else if (std::string(argv[1]) == "readLightLevel") {

            printLightLevel();

        }else if(std::string(argv[1]) == "setLedLight"){

            controlLightIntensity(atoi(argv[2]));

        } else if (std::string(argv[1]) == "readLedLight") {

            readLightIntensity();

        }else if(std::string(argv[1]) == "setWindowStatus"){

            controlServo(argv[2]);

        }else if(std::string(argv[1]) == "readWindow"){

            readWindowPos();

        }else if(std::string(argv[1]) == "setHeaterStatus"){

            heaterOnOff(argv[2]);

        } else if (std::string(argv[1]) == "readHeater") {

            readHeater();

        } else {

            std::cout << "Argument unrecognized see --help" << std::endl;

        }
    } else {

        std::cout << "No arguments unrecognized see --help" << std::endl;

    }

    return 0;
}