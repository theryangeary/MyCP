mycp: mycp.o
	gcc -o mycp mycp.o 

mycp.o: mycp.c
	gcc -O -Wall -c mycp.c

debug: mycp.c
	gcc -g mycp.c

clean:
	rm -f mycp.o mycp a.out
