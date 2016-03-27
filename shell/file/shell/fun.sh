#!/bin/bash

function fun(){
	echo  $1
	echo  $2
#	echo  $3
#	echo  $4
	echo  $@
	echo  $#
	echo "I am a fun"

	
	return 11
    #echo 1

}


#fun a b c d 


fun "hello world" "good"
echo $?



#ret=$(fun)
#	echo $ret





