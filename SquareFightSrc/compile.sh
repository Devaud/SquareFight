#!/bin/bash

g++ -c $1.cpp
echo "Compiled. Library are adding !"
g++ $1.o -o $2 -lsfml-graphics -lsfml-window -lsfml-system
echo "You can run $2"
