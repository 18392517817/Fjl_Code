#!/bin/bash
echo "one"
echo 'Input a num between 1-3'
read num
case $num in
	1) echo '1'
	;;
	'2')
	echo '2'
	;;
	"3") echo '3';;
	*)
	echo "you input error"
	;;
esac




