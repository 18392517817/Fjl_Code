#!/bin/bash

arr[0]=1
arr[1]=1

max=$1
index=0

while [ $index -le $max ]
do
	let arr[$index+2]=${arr[$index+1]}+${arr[$index]}
	#let index++
	(( index++ ))
done

echo ${arr[$index-1]}
