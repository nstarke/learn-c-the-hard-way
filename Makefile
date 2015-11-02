CFLAGS=-Wall -g
clean:
	rm -f ex1 ex3 ex3-without-age ex3-without-age-value \
	ex7 ex7-without-printf-arg ex7-without-value ex8 ex8-backwards
all:
	make ex1 ex3 ex3-without-age ex3-without-age-value \
	ex7 ex7-without-printf-arg ex7-without-value ex8 ex8-backwards
