EXEC=fork
OBJS=fork.o
CC=gcc
all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
clean:
	-rm -f $(EXEC) *.elf *.gdb *.o
