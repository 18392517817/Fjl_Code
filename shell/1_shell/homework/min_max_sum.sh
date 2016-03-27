#!/bin/bash
proc=$(basename $0)
function usage(){
	echo "Uage : ${proc} data1 data2... datan"
		exit 1
}

[ $# -lt 1 ] && usage

min=$1
max=$1
sum=0

for val in $@
do
	if [ $min -gt $val ];then
	min=$val
	fi
	if [ $max -lt $val ];then
	max=$val
	fi
	let sum+=$val
done

echo "max is : ${amx}"
echo "min is : ${min}"
echo "sum is : ${sum}"
echo "ibase=10; scale=3; ${sum}/$#" | bc


