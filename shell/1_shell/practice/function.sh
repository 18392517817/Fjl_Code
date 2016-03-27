#!/bin/bash

function fun(){
		echo 'one'
		echo "first parameter is $1"
		echo "two parameter is $2"
		echo "three parameter is $3"
		echo "four parameter is $4"
		echo "five parameter is $5"
		echo "ten parameter is $10"   #it is not you want
		echo "ten parameter is ${10}"
		echo "123 parameter is ${123}"  # NULL
		echo "two"
		echo $#
		echo $*
		echo $@
		echo $?
#	echo "Url is http://see.xidian.edu.cn/cpp/shell/"
	return 0
}
fun 0  2 3 4 5 6 7 8 9 10 11

#$unset .f fun
