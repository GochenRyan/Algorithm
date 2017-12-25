EXEC1=fifo1
EXEC2=fifo2
EXEC=$(EXEC1) $(EXEC2)
OBJS1=fifo1.o
OBJS2=fifo2.o
CC=gcc  #这里注意，要使用版本3.4.1的交叉编译器
 
all: $(EXEC)
$(EXEC1): $(OBJS1)
	$(CC) $(LDFLAGS) -o $@ $(OBJS1)
$(EXEC2): $(OBJS2)
	$(CC) $(LDFLAGS) -o $@ $(OBJS2)

clean:
	-rm -f $(EXEC) *.elf *.gdb *.o
