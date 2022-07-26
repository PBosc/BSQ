#!/bin/sh

a=0

while [ $a -lt 10 ]
do
	perl generator.pl 9 9 5 | ./bsq
	a=`expr $a + 1`
	echo '\n'
done