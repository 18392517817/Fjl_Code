
#!/bin/bash

bar=''

index=0
pos=0
flag=("|" "/" "-" "\\")

while [ $index -le 100  ]
do
	let pos=index%4
	bar=${bar}# ;
	sleep 0.1
#	echo $bar
	printf "[43;34;1m[%-100s][1m%d%%][%c]\r" "${bar}" "${index}" "${flag[pos]}"
#	(( index++ ))
	let index++
done



