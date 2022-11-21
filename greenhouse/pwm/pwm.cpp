/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 18-11-2022
 */

#include "pwm.h"

void greenhouse::pwm::send_pwm(int duty_cycle, int period, int channel){

    // duty cycle
    fs.open(("/sys/class/pwm/pwmchip1/pwm-1:"+std::to_string(channel)+"/duty_cycle").c_str(), std::fstream::out);
    fs << std::to_string(duty_cycle);
    fs.close();

    // set period
    fs.open(("/sys/class/pwm/pwmchip1/pwm-1:"+std::to_string(channel)+"/period").c_str(), std::fstream::out);
    fs << std::to_string(period);
    fs.close();

    // enable pwm
    fs.open(("/sys/class/pwm/pwmchip1/pwm-1:"+std::to_string(channel)+"/enable").c_str(), std::fstream::out);
    fs << std::to_string(1);
    fs.close();
}

// LED light
// 200000 = 1% of period
void greenhouse::pwm::send_pwm_percentage(int percent, int period, int channel)
{
    send_pwm(percent * 200000, period, channel);
}