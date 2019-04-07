CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=bitabit test_read test_write

all: $(EXEC)


bit_operations.o: bit_operations.c bit_operations.h bfile.h
	$(CC) -o $@ -c $< $(CFLAGS)

test_read.o: test_read.c bfile.h
	$(CC) -o $@ -c $< $(CFLAGS)

test_write.o: test_write.c bfile.h
	$(CC) -o $@ -c $< $(CFLAGS)	

test_write: test_write.o bit_operations.o
	$(CC) -o $@ $^ $(LDFLAGS)

test_read: test_read.o bit_operations.o
	$(CC) -o $@ $^ $(LDFLAGS)

bitabit.o: bitabit.c bit_operations.h
	$(CC) -o $@ -c $< $(CFLAGS)

bitabit: bitabit.o bit_operations.o
	$(CC) -o $@ $^ $(LDFLAGS)
clean:
	rm -rf *.o
	rm -rf $(EXEC)
