mystandard:standard.o
	gcc -o mystandard standard.o
standard.o:standard.s
	gcc -c standard.s -o standard.o
standard.s:standard.i
	gcc -S standard.i -o standard.s
standard.i:standard.c
	gcc -E standard.c -o standard.i
.PHONY:clean
clean:
	rm standard.i standard.s standard.o mystandard -f
