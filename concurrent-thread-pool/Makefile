.SILENT: clean
CC:=gcc
CFLAGS:=-std=c11
LINKER:=-pthread
OUT:=test

thread_pool: thread_pool.c thread_pool.h
	$(CC) $(CFLAGS) $@.c -c -o $@.o

test: test.c thread_pool.o
	$(CC) $(CFLAGS) $(LINKER) $^ -o $@

clean:
	rm *.o
	if [ -f $(OUT) ] ; then rm $(OUT) ; fi;
