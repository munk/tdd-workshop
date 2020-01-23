#!/bin/sh

gcc -o test_bignum bignum.c test_bignum.c
./test_bignum
rm test_bignum
gcc -o add bignum.c main.c
./add 99 102  # should equal 201
