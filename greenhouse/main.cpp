/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#include "settings.h"
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

    /**
     * @brief Read temperature and humidity form hih8180.
     */
    void temperatureHumidity()
    {
        greenhouse::hih8120 hih8120(2, HIH8120_ADDRESS);
        hih8120.readCurrentTemperatureHumidity();

        std::cout << "Temperature: " << hih8120.temperature << "     " << std::endl;
        std::cout << "Humidity:    " << hih8120.humidity << "     " << std::endl;
    }

    /**
     * @brief Read temperature form hih8180.
     */
    void temperature()
    {
        greenhouse::hih8120 hih8120(2, HIH8120_ADDRESS);
        hih8120.readCurrentTemperatureHumidity();

        std::cout << "Temperature: " << hih8120.temperature << "     " << std::endl;
    }

    /**
     * @brief Read humidity form hih8180.
     */
    void humidity()
    {
        greenhouse::hih8120 hih8120(2, HIH8120_ADDRESS);
        hih8120.readCurrentTemperatureHumidity();

        std::cout << "Humidity:    " << hih8120.humidity << "     " << std::endl;
    }


    /**
     * @brief Prints light level from reading the light depended resistor
     */
    void ldrLevel() {
        greenhouse::ldr ldr;
        ldr.readCurrentLightLevel();

        std::cout << "Light level: " << ldr.lightLevel << "     " << std::endl;
    }


    /**
    * @brief Control the light intensity of the led light
    *
    * @param i 0-100 integer value
    */
    void lightSetIntensity(int i)
    {
        greenhouse::pwm led;

        led.send_pwm_percentage(i, 20000000, PWM_CHANNEL_A);
    }

    /**
     * @brief Sets the light intensity of the led light to 0
     */
    void lightOff()
    {
        greenhouse::pwm led;

        led.send_pwm_percentage(0, 20000000, PWM_CHANNEL_A);
    }

    /**
     * @brief Read the percentage of power going to led lamp
     *
     * Read directly form a file that stores the duty_cycle
     * The duty cycle is then divided by the period to get percentage
     */
    void lightIntensity()
    {
        std::string lightDuty = readFile("/sys/class/pwm/pwmchip1/pwm-1:1/duty_cycle");
        std::cout << "Led light:   " + std::to_string(atoi(lightDuty.c_str()) / 200000)<< "     " << std::endl;
    }


    /**
     * @brief Sets the position of a window by sending a pwm pulse to servo motor
     * value == 2000000 Window is open
     */
    void windowOpen()
    {
        greenhouse::pwm servo;
        servo.send_pwm(2000000, 20000000, PWM_CHANNEL_B);
    }

    /**
     * @brief Sets the position of a window by sending a pwm pulse to servo motor
     * value == 1500000 Window is half open
     */
    void windowHalf()
    {
        greenhouse::pwm servo;
        servo.send_pwm(1500000, 20000000, PWM_CHANNEL_B);
    }

    /**
     * @brief Sets the position of a window by sending a pwm pulse to servo motor
     * value == 1000000 Window is closed
     */
    void windowClose()
    {
        greenhouse::pwm servo;
        servo.send_pwm(1000000, 20000000, PWM_CHANNEL_B);
    }

    /**
     * @brief Read the position of a window by reading pwm value of servo motor
     *
     * Reads a file:
     * value == 2000000 Window is open
     * value == 1500000 Window is half open
     * value == 1000000 Window is closed
     */
    void windowStatus()
    {
        std::string wpos = readFile("/sys/class/pwm/pwmchip1/pwm-1:0/duty_cycle");
        if (wpos.compare("2000000") == 0) {
            std::cout << "Window:      open" << "     " << std::endl;
        } else if (wpos.compare("1500000") == 0) {
            std::cout << "Window:      half open" << "     " << std::endl;
        } else if (wpos.compare("1000000") == 0) {
            std::cout << "Window:      closed" << "     " << std::endl;
        } else {
            std::cout << "error reading window pos" << std::endl;
        }
    }


    /**
     * @brief Set heater to "on"
     */
    void heatOn()
    {
        heater heater;
        heater.turnOnHeater();
    }

    /**
     * @brief Set heater to "off"
     */
    void heatOff()
    {
        heater heater;
        heater.turnOffHeater();
    }

    /**
     * @brief Read the status of the heater: on or off
     */
    void heatStatus()
    {
        heater heater;
        heater.readHeaterStatus();
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
                      << "setLedLight - controls led light intensity. Params from 0 to 100." << std::endl
                      << "offLedLight - sets led light intensity to 0." << std::endl
                      << "readLedLight - Prints led light intensity. From 0% to 100%" << std::endl
                      << "setWindowStatus - controls window in greenhouse. Params open, half open or close." << std::endl
                      << "readWindow - reads position,open, half open or close." << std::endl
                      << "readHeater - reads status,on or off." << std::endl
                      << "setHeaterStatus - controls heater in greenhouse.Params on or off." << std::endl;

        }

        // hih8120
        else if (std::string(argv[1]) == "readTempAndHumidity")
        {
            temperatureHumidity();
        }
        else if (std::string(argv[1]) == "readTemp") {
            temperature();
        }
        else if (std::string(argv[1]) == "readHumidity")
        {
            humidity();
        }

        // ldr
        else if (std::string(argv[1]) == "readLightLevel")
        {
            ldrLevel();
        }

        // pwm, light
        else if(std::string(argv[1]) == "setLedLight")
        {
            lightSetIntensity(atoi(argv[2]));
        }
        else if(std::string(argv[1]) == "offLedLight")
        {
            lightOff();
        }
        else if (std::string(argv[1]) == "readLedLight") {
            lightIntensity();
        }

        // pwm, servo
        else if(std::string(argv[1]) == "setWindowStatus")
        {
            if (argv[2] == "open")
            {
                windowOpen();
            }
            else if (argv[2] == "half")
            {
                windowHalf();
            }
            else if (argv[2] == "close")
            {
                windowClose();
            }
            else
            {
                std::cout << "Argument unrecognized see --help" << std::endl;
            }
        }
        else if(std::string(argv[1]) == "readWindow")
        {
            windowStatus();
        }

        // heater
        else if(std::string(argv[1]) == "setHeaterStatus")
        {
            if (argv[2] == "on")
            {
                heatOn();
            }
            else if (argv[2] == "off")
            {
                heatOff();
            }
            else
            {
                std::cout << "Argument unrecognized see --help" << std::endl;
            }
        }
        else if (std::string(argv[1]) == "readHeater")
        {
            heatStatus();
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
