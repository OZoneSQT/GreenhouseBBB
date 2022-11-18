cmake_minimum_required(VERSION 3.23)
project(greenhouse)

set(CMAKE_CXX_STANDARD 14)

add_executable(greenhouse main.cpp I2CDevice.cpp I2CDevice.h heater/heater.cpp heater/heater.h ldr/ldr.cpp ldr/ldr.h pmw/pwm.cpp pmw/pwm.h hih8120/hih8120.cpp hih8120/hih8120.h settings.h servo/servo.cpp servo/servo.h)
