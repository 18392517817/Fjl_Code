#!/bin/bash

function sum(){
	local index=0
	local total=0
	while [ ${index} -eq ${1}  ]
	do
	let total+=$index
	let index++
	done
	echo ${total}
}


sum 100
