#!/bin/bash
function sum(){
	local tmp=$1
	local tmp1
	if [ $tmp -eq 1 ];then
		r=1
	else
		tmp1=`expr ${tmp} - 1`
			sum $tmp1
		r=`expr $r + $tmp`
	fi

}
sum $1
echo $r
