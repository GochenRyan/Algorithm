KERNELDIR=/usr/src/linux-2.4
INCLUDER=$(KERNELDIR)/include

AS=as
LD=ld
CC=gcc
CPP=$(CC)-E
AR=ar
NM=nm
STRIP=strip
OBJCOPY=objcopy
OBJDUMP=objdump
CFLAGS+=-I
CFLAGS+=-Wall -O -D__KERNEL__ -DMODULE -I$(INCLUDER)
TARGET=evan.o test_demo

all:$(TARGET)
evan.o:demodriver.c
	$(CC) -c $(CFLAGS) $^ -o $@
test_demo:test_demo.o
	$(CC) $^ -o $@
install:
	install -d.
	install 0c $(TARGET).o. 
clean:
	rm -f *.o *~ core.depend


