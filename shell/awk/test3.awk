#!/bin/awk/ -f
BEGIN{
	FS=":"
}
/bash$/{
printf("%d:\n",NF);
printf("%s:\n",$NF);
}
