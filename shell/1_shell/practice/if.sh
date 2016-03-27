#!/bin/bash

echo '1'

a=10
b=20
if [ $a == $b ];then
	echo "a is equal to b"
else
	echo "a is not equal to b"
fi

echo '2'
read c d
if [ $c -gt $d ];then
echo "c>d"
elif [ $c -lt $d ];then
echo "c<d"
elif [ $c -eq $d ];then
echo "c=d"
else
echo "no "
fi
