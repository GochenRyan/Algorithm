EXEC= pipe
OBJS= pipe.o
SOC=pipe.c
CC=gcc
LDFLAGS=-g -Wall
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
$(OBJS): $(SOC)
	$(CC) $(LDFLAGS) -c $(SOC)
clean:
	-rm -f $(EXEC) *.elf *.gdb *.o
