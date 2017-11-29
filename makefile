LIB = -lm 
OPT = -Wall -g

out: main.o 
	gcc main.o -o a.out 
 
main.o: main.c
	gcc -c main.c -o main.o $(OPT)


clean: 
	rm *.o







