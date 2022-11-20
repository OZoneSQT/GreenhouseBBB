/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 19-11-2022
 */

#include "lightAdapter.h"
#include "pwm.h"

namespace greenhouse {

    /**
     * @brief Control the light intensity of the led light
     *
     * @param i 0-100 integer value
     */
    void pwmAdapter::controlLightIntensity(int i)
    {
        pwm pwm_led;
        pwm_led.send_pwm_percentage(i, 20000000, PWM_CHANNEL_A);
    }

    /**
     * @brief Read the percentage of power going to led lamp
     *
     * Read directly form a file that stores the duty_cycle
     * The duty cycle is then divided by the period to get percentage
     */
    void pwmAdapter::readLightIntensity()
    {
        std::string lightDuty = readFile("/sys/class/pwm/pwmchip" + PWM_CHIP + "/pwm-" + PWM_CHIP + ":" + PWM_CHANNEL_A + "/duty_cycle");
        std::cout << "Led light:   " + std::to_string(atoi(lightDuty.c_str()) / 200000)<< "     " << std::endl;
    }

}