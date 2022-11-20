cmake_minimum_required(VERSION 3.23)
project(greenhouse)

set(CMAKE_CXX_STANDARD 14)

add_executable(greenhouse main.cpp I2CDevice.cpp I2CDevice.h heater/heater.cpp heater/heater.h ldr/ldr.cpp ldr/ldr.h pwm/pwm.cpp pwm/pwm.h hih8120/hih8120.cpp hih8120/hih8120.h servo/servo.cpp servo/servo.h heater/heaterAdapter.cpp heater/heaterAdapter.h hih8120/temperatureHumidityAdapter.cpp hih8120/temperatureHumidityAdapter.h ldr/ldrAdapter.cpp ldr/ldrAdapter.h settings.h pwm/lightAdapter.cpp pwm/lightAdapter.h pwm/servoAdapter.cpp pwm/servoAdapter.h)
