#!/bin/bash


echo "Статическая компиляция"

gcc -c *.c

ar rc libtimes.a times.o

gcc -o lab12_2 main.c -L . -l times
#gcc -o lab12_2 main.c libtimes.a

./lab12_2

echo "====================="
