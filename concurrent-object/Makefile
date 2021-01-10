.SILENT: clean
CC:=gcc
CFLAGS:=-std=c11
LINKER:=-lpthread
OUT_1:=lock_queue
OUT_2:=queue_without_lock

lock_queue:
	$(CC) $@.c $(CFLAGS) $(LINKER) -o $@

queue_without_lock:
	$(CC) $@.c $(CFLAGS) $(LINKER) -o $@

clean:
	if [ -f $(OUT_1) ] ; then rm $(OUT_1) ; fi;
	if [ -f $(OUT_2) ] ; then rm $(OUT_2) ; fi;
