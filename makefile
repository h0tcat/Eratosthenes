CC=g++ --static -O3
PGNAME=eratosthenesSample
OBJS=main.o Eratosthenes.o

$(PGNAME): $(OBJS)
	$(CC) -o $@ $^ 
.cpp.o:
	$(CC) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(PGNAME) $(OBJS)