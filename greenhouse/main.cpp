/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#include "hih8120/temperatureHumidityAdapter.h"
#include "ldr/ldrAdapter.h"
#include "pwm/lightAdapter.h"
#include "pwm/servoAdapter.h"
#include "heater/heaterAdapter.h"
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

//TODO https://www.positioniseverything.net/cpp-undefined-reference/,
// Look at greenhouse example, call Derived methods, from a method instead of main()


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

        }

        // hih8120
        else if (std::string(argv[1]) == "readTempAndHumidity")
        {
            // undefined reference
            greenhouse::temperatureHumidityAdapter adapter;
            adapter.printTemperatureAndHumidity();
        }
        else if (std::string(argv[1]) == "readTemp") {
            // undefined reference
            greenhouse::temperatureHumidityAdapter adapter;
            adapter.printTemperature();
        }
        else if (std::string(argv[1]) == "readHumidity")
        {
            // undefined reference
            greenhouse::temperatureHumidityAdapter adapter;
            adapter.printHumidity();
        }

        // ldr
        else if (std::string(argv[1]) == "readLightLevel")
        {
            // undefined reference
            greenhouse::ldrAdapter adapter;
            adapter.printLightLevel();
        }

        // pwm, light
        else if(std::string(argv[1]) == "setLedLight")
        {
            // undefined reference
            greenhouse::lightAdapter adapter;
            adapter.controlLightIntensity(atoi(argv[2]));
        }
        else if (std::string(argv[1]) == "readLedLight") {
            // undefined reference
            greenhouse::lightAdapter adapter;
            adapter.readLightIntensity();
        }

        // pwm, servo
        else if(std::string(argv[1]) == "setWindowStatus")
        {
            if (argv[2] == "open")
            {
                // undefined reference
                greenhouse::servoAdapter adapter;
                adapter.openWindow();
            }
            else if (argv[2] == "half")
            {
                // undefined reference
                greenhouse::servoAdapter adapter;
                adapter.halfOpenWindow();
            }
            else if (argv[2] == "close")
            {
                // undefined reference
                greenhouse::servoAdapter adapter;
                adapter.closeWindow();
            }
            else
            {
                std::cout << "Argument unrecognized see --help" << std::endl;
            }
        }
        else if(std::string(argv[1]) == "readWindow")
        {
            // undefined reference
            greenhouse::servoAdapter adapter;
            adapter.readWindowPos();
        }

        // heater
        else if(std::string(argv[1]) == "setHeaterStatus")
        {
            if (argv[2] == "on")
            {
                // undefined reference
                greenhouse::heaterAdapter adapter;
                adapter.on();
            }
            else if (argv[2] == "off")
            {
                // undefined reference
                greenhouse::heaterAdapter heaterAdapter;
                heaterAdapter.off();
            }
            else
            {
                std::cout << "Argument unrecognized see --help" << std::endl;
            }
        }
        else if (std::string(argv[1]) == "readHeater")
        {
            // undefined reference
            greenhouse::heaterAdapter::heaterAdapter() adapter;
            adapter.isRunning();
        }

        else
        {
            std::cout << "Argument unrecognized see --help" << std::endl;
        }
    }
    else
    {
        std::cout << "No arguments unrecognized see --help" << std::endl;
    }

    return 0;
}