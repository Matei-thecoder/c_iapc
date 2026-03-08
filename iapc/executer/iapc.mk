${CC} = clang

iapc: main.o alocari.o executare.o verificare.o
	${CC} -Wall main.o alocari.o executare.o verificare.o -o iapc

main.o: main.c alocari.h executare.h verificare.h
	${CC} -c -Wall main.c 

alocari.o: alocari.c alocari.h 
	${CC} -c -Wall alocari.c 

executare.o: executare.c executare.h 
	${CC} -c -Wall executare.c

verificare.o: verificare.c verificare.h executare.h alocari.h
	${CC} -c -Wall verificare.c

.PHONY: clean
.clean:
	rm -rf *.o
	rm iapc
