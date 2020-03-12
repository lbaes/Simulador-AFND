CC = gcc
CFLAGS = -g -Wall

default: afnd

afnd: lista.o quintupla.o afnd.o
	$(CC) ${CFLAGS} -o ../afnd.out afnd.o lista.o quintupla.o

afnd.o: afnd.c quintupla.h
	$(CC) ${CFLAGS} -c afnd.c

lista.o: lista.c lista.h
	$(CC) ${CFLAGS} -c lista.c

quintupla.o: quintupla.c quintupla.h
	$(CC) ${CFLAGS} -c quintupla.c

clean:
	rm ../afnd.out *.o
