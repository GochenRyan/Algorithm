EXEC= popen
OBJS= popen.o
SOC=popen.c
CC=gcc
#LDFLAGS=-g -Wall
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
$(OBJS): $(SOC)
	$(CC) $(LDFLAGS) -c $(SOC)
clean:
	-rm -f $(EXEC) *.elf *.gdb *.o
