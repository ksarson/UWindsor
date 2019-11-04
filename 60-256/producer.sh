#!/bin/bash
file=($(cat storage.txt))
if test "$((file+8))" -lt 100; then
	echo "$((file+8))" > storage.txt
	echo "From Producer:  Current total is $((file+8))"
	gcc consumer.c -o output
	./output
else
	echo "From Producer:  Now i will take a rest!"
	exit 1
fi