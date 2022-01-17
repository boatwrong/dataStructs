3:	3.c
	gcc -o 3 3.c

2:	2.c
	gcc -o 2 2.c

1:	1.c
	gcc -o 1 1.c


clean:
	rm 2
	rm 1

