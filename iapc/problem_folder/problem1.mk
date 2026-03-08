problem1: problem1.o
	clang -Wall problem1.o -o problem1

problem1.o: problem1.c
	clang -c -Wall problem1.c

.PHONY: clean
.clean:
	rm -rf *.o
	rm test
