#!/bin/bash

arr=(fu jin long)


echo ${arr[0]}
echo ${arr[1]}
echo ${arr[2]}
echo ${arr[@]}
echo ${arr[*]}
echo ${#arr[@]}
echo ${#arr[2]}
arr[6]="hello"
echo ${arr[6]}
echo ${arr[7]}
echo ${arr[10]}
echo ${arr[*]}
echo ${#arr[@]}
echo ${#arr[7]}

