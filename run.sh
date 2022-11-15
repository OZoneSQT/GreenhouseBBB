#!/bin/bash
#
# Authors:
# Bastian Durand 239735
# Michel Sommer 273966
# Date: 2022-11-15
#
# Script for starting Greenhouse project
#

echo ***Starting Greenhouse...
#.Greenhouse #Run Greenhouse project 
sleep 30 #Sleep script for 30 seconds
echo ***starting server...
node server.js
sleep 10 #Sleep script for 10 seconds
echo ***server is ready at port\: 26001
