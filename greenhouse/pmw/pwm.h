/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#ifndef GREENHOUSE_PWM_H
#define GREENHOUSE_PWM_H

#include "../settings.h"
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

namespace greenhouse {

    class pwm {

    public:
        pwm()
        {
            system("config-pin P9_22 pwm"); // LED
            system("config-pin P9_21 pwm"); // Servo motor
        }

        void send_pwm(int duty_cycle, int period, int channel);
        void send_pwm_percentage(int percent, int period, int channel);

    private:
        std::fstream fs;
    };

}

#endif