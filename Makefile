# FLAGS
CC = gcc
thr = -pthread

make: Prod_Cons.c
	$(CC) $(thr) $< -o $@

.PHONY: run clean

run: 
	./make

clean:
	rm make
