/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 19-11-2022
 */

#ifndef GREENHOUSEBBB_SETTINGS_H
#define GREENHOUSEBBB_SETTINGS_H

namespace greenhouse {

    // Heater control with IO
    // P9_1	                GND         Black
    // P9_7	                5V	        Red
    // P9_23     gpio49	    IO	        Purple
    #define HEATER_PIN "49"


    // HIH8120 Temperature and humidity, I2C
    // P9_1	                GND	        Black
    // P9_4	                3.3V	    White
    // P9_19	  gpio13    SDA	        Yellow
    // P9_20	  gpio12    SDL	        Green
    // #define HIH8120_ADDRESS 0x53
    #define HIH8120_ADDRESS 0x27

    // Light measurement with ADC
    // P9_1	                GND	        Black
    // P9_7	                5V	        Red
    // P9_32	            1.8V ref.	Orange
    // P9_34	            GND ADC	    Black
    // P9_39	  AIN0      ADC	        Blue
    #define ADC_PIN_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
    #define ADC_PIN 0


    // Light Control with PWM
    // P9_1	                GND	        Black
    // P9_7	                sys 5V	    Red
    // P9_22	gpio2       PMW	        Brown
    #define PWM_LED_PIN "config-pin P9_22 pwm"
    #define PWM_CHANNEL_B 0


    // Servo motor control with PWM
    //  P9_1	            GND	        Black
    //  P9_7	            5V	        Red
    //  P9_21	gpio3       PMW	        Gray
    #define PWM_LED_SERVO "config-pin P9_21 pwm"
    #define PWM_CHANNEL_A 1

}

#endif