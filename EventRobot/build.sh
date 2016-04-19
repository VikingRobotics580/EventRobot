#!/bin/bash

for f in ./src/*.cpp
do
    arm-frc-linux-gnueabi-g++ -g -Wall -W -I`echo ~`/wpilib/cpp/current/include -I. -std=c++14 -fPIC -L`echo ~`/wpilib/cpp/current/lib -lwpi "$f" -o $(basename "$f").o
done

