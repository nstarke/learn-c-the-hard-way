CFLAGS=-Wall -g
clean:
	rm -f ex1 ex3 ex3-without-age ex3-without-age-value \
	ex7 ex7-without-printf-arg ex7-without-value ex8 \
	ex8-fixed ex9 ex9-backwards ex10 ex10-lowercase-conversion \
	ex11 ex11-change-type
all:
	make ex1 ex3 ex3-without-age ex3-without-age-value \
	ex7 ex7-without-printf-arg ex7-without-value ex8 \
	ex8-fixed ex9 ex9-backwards ex10 ex10-lowercase-conversion \
	ex11 ex11-change-type
