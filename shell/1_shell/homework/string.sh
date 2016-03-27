#!/bin/bash
g_file=file
while read line
do
	part1=$(echo $line | cut -c 1-3)
	part2=$(echo $line | cut -c 4-6 |tr '[a-z]' '[A-Z]')
	part3=$(echo $line | cut -c 7-9)
	echo "${part3}$part2$part1">>log
done<file # >log
