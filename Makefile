LC_ALL=cs._CZ.utf8
CC =gcc
CFLAGS= -O2 -std=c11 -Wall -pedantic -Wextra -g 
PROGS = primes primes-i steg-decode
LIBS =-lm
all:$(PROGS)

run: primes primes-i
	ulimit -s 65000 && time ./primes
	ulimit -s 65000 && time ./primes-i

primes: primes.o eratosthenes.o bitset.o error.o
	$(CC) $(CFLAGS) primes.o eratosthenes.o bitset.o error.o -o primes $(LIBS)
primes-i: primes-i.o eratosthenes-i.o bitset-i.o error.o
	$(CC) $(CFLAGS) primes-i.o bitset-i.o eratosthenes-i.o error.o -o primes-i $(LIBS)

steg-decode: eratosthenes.o bitset.o steg-decode.o ppm.o error.o
	$(CC) $(CFLAGS) eratosthenes.o bitset.o steg-decode.o ppm.o error.o -o steg-decode $(LIBS)


primes.o: primes.c
	$(CC) $(CFLAGS) -c primes.c -o primes.o

eratosthenes.o: eratosthenes.c
	$(CC) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

bitset.o: bitset.c
	$(CC) $(CFLAGS) -c bitset.c -o bitset.o

bitset-i.o: bitset.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c bitset.c -o bitset-i.o 

primes-i.o: primes.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o

eratosthenes-i.o: eratosthenes.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o


error.o: error.c
	$(CC) $(CFLAGS) -c error.c -o error.o 

ppm.o: ppm.c
	$(CC) $(CFLAGS) -c ppm.c -o ppm.o
steg-decode.o: steg-decode.c
	$(CC) $(CFLAGS) -c steg-decode.c -o steg-decode.o
	

clear:
	rm *.o $(PROGS)

pack:
		zip xmazak02.zip *.c *.h Makefile
