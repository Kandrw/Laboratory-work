#!/bin/bash


echo "Динамическая компиляция"

gcc -c times.c -o times.o

gcc -shared -o libtimes.so times.o

gcc -c main.c

gcc -o lab12_3 main.o -L. -l times -Wl,-rpath,.


./lab12_3

echo "====================="
