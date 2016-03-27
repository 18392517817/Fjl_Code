#!/bin/bash

count=0
while [ $count -lt 5 ]
do
   # count=`expr $count+1
#    let count++
	(( count++ ))
    echo $count
done



