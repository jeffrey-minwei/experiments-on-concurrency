.SILENT: clean
CC:=gcc
CFLAGS:=-std=c11
LINKER:=-latomic -pthread
OUT:=test_harris

list: list.c node.h
	$(CC) $(CFLAGS) $@.c -c -o $@.o

harris_solution: harris_solution.c node.h
	$(CC) $(CFLAGS) $@.c -c -o $@.o

test_harris: test_harris.c harris_solution.o list.o
	$(CC) $(CFLAGS) $(LINKER) $^ -o $@

clean:
	rm *.o
	if [ -f $(OUT) ] ; then rm $(OUT) ; fi;
