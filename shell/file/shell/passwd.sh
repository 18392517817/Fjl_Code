#!/bin/bash

read passwd
count=0
while [ ! $"X${passwd}" == "Xyes" ]
do
	let count++
	if [ count -ge 3  ];then
	echo "you have try 3 times,sorry!"
	exit 1
	fi
	echo "please try again "
	read passwd

done

echo "you are in!"
