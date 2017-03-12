CC=gcc
FLAGS=-Wall -Werror -g
TESTBIN=test_bst.out

build: bst.o test_bst.o
	$(CC) $(FLAGS) bst.o test_bst.o -o $(TESTBIN)

bst.o: bst.c bst.h
	$(CC) $(FLAGS) -c bst.c

test_bst.o: test_bst.c bst.h
	$(CC) $(FLAGS) -c test_bst.c

clean:
	rm *.o *.out
