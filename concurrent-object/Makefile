.SILENT: clean
CC:=gcc
CFLAGS:=-std=c11
LINKER:=-lpthread
OUT_1:=lock_queue

lock_queue:
	$(CC) $@.c $(CFLAGS) $(LINKER) -o $@

clean:
	if [ -f $(OUT_1) ] ; then rm $(OUT_1) ; fi;
