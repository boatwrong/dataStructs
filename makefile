7:	7.c
	gcc -o 7 7.c
6:	6.c
	gcc -o 6 6.c
5:	5.c
	gcc -o 5 5.c
4:	4.c
	gcc -o 4 4.c
3:	3.c
	gcc -o 3 3.c
2:	2.c
	gcc -o 2 2.c
1:	1.c
	gcc -o 1 1.c

clean:	
	rm 1 2 3 4 5 6 7 

all:
	gcc -o 7 7.c
	gcc -o 6 6.c
	gcc -o 5 5.c
	gcc -o 4 4.c
	gcc -o 3 3.c
	gcc -o 2 2.c
	gcc -o 1 1.c
