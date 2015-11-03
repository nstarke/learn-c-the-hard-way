CFLAGS=-Wall -g
clean:
	rm -f ex1 ex3 ex3-without-age ex3-without-age-value \
	ex7 ex7-without-printf-arg ex7-without-value ex8 \
	ex8-fixed ex9 ex9-backwards ex10 ex10-lowercase-conversion \
	ex11 ex11-change-type ex12 ex12-no-null-chars ex13 \
	ex13-sizeof ex13-wrong-num_states ex14 ex14-strlen \
	ex14-index-out-of-bounds ex15
all:
	make ex1 ex3 ex3-without-age ex3-without-age-value \
	ex7 ex7-without-printf-arg ex7-without-value ex8 \
	ex8-fixed ex9 ex9-backwards ex10 ex10-lowercase-conversion \
	ex11 ex11-change-type ex12 ex12-no-null-chars ex13 \
	ex13-sizeof ex13-wrong-num_states ex14 ex14-strlen \
	ex14-index-out-of-bounds ex15
