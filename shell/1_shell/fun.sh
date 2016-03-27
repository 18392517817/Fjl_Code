#!/bin/bash
read max
num1=1
num2=1
num=0
index=1
while [ ${index} -lt $max ]
do
let 	num=${num1}+${num2}
let	num1=${num2}
let	num2=${num}
	let index++
done

echo ${num}
