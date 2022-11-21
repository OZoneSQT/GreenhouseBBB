#!/bin/bash
#
# Authors:
# Bastian Durand 239735
# Michel Sommer 273966
# Date: 2022-11-15
#
# Build script for compiling Greenhouse project
# using g++ in terminal
#

echo *** Greenhouse compiler ***

# Compile: Remember to put main.cpp last, to have dependence ready for main.cpp
g++ heater/heater.cpp ldr/ldr.cpp pwm/pwm.cpp I2CDevice.cpp hih8120/hih8120.cpp main.cpp -o greenhouse

sleep 10 #Sleep script for 10 seconds
echo *** Giving program to Greenhouse ***

# Giving program all permissions
# chmod a+rwx greenhouse

sleep 10 #Sleep script for 10 seconds
echo *** Build script for Greenhouse project is executed ***