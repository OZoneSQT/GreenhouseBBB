/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 19-11-2022
 */

#include "servoAdapter.h"
#include "pwm.h"

namespace greenhouse {

#define SERVOCHANNEL 1

    void servoAdapter::openWindow() {
        controlServo("open");
    }

    void servoAdapter::halfOpenWindow() {
        controlServo("half");
    }

    void servoAdapter::closeWindow() {
        controlServo("close");
    }

    void controlServo(std::string i) {
        pwm pwm_servo;

        if (i == "open") {
            pwm_servo.send_pwm(2000000, 20000000, SERVOCHANNEL);
        } else if (i == "half") {
            pwm_servo.send_pwm(1500000, 20000000, SERVOCHANNEL);
        } else if (i == "close") {
            pwm_servo.send_pwm(1000000, 20000000, SERVOCHANNEL);
        }
    }

    /**
     * @brief Read the position of a window by reading pwm value of servo motor
     *
     * Reads a file:
     * value == 2000000 Window is open
     * value == 1500000 Window is half open
     * value == 1000000 Window is closed
     */
    void servoAdapter::readWindowPos() {
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

}