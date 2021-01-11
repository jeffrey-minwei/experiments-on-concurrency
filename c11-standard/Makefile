.SILENT: clean
CC:=gcc
CFLAGS:=-std=c11 -S -masm=intel
SRC:=modification_order.c
OUT_1:=modification_order.s
OUT_2:=modification_order_O2.s

modification_order:
	$(CC) $(SRC) $(CFLAGS) -o $@.s

modification_order_O2:
	$(CC) $(SRC) $(CFLAGS) -O2 -o $@.s

clean:
	if [ -f $(OUT_1) ] ; then rm $(OUT_1) ; fi;
	if [ -f $(OUT_2) ] ; then rm $(OUT_2) ; fi;
