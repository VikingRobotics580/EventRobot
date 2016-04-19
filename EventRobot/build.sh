#!/bin/bash

for f in $(find src -name "*.cpp")
do
    echo "Compiling $f"
    arm-frc-linux-gnueabi-g++ -g -c -Wall -W -I`echo ~`/wpilib/cpp/current/include -I. -std=c++14 "$f" -o $(basename "$f").o || { exit 1; }
done

ar rvs libs/libeventrobot.a ./*.o || { exit 1; }

