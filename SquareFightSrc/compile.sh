#!/bin/bash

g++ -c main.cpp
g++ -c square.cpp
g++ -c zonning.cpp
echo "Compiled. Library are adding !"
g++ main.o square.o zonning.o -o SquareFight -lsfml-graphics -lsfml-window -lsfml-system
echo "You can run SquareFight"
