CFLAGS=-Wall -g
clean:
	rm -f ex001 ex003 ex003-without-age ex003-without-age-value \
	ex007 ex007-without-printf-arg ex007-without-value ex008 \
	ex008-fixed ex009 ex009-backwards ex010 ex010-lowercase-conversion \
	ex011 ex011-change-type ex012 ex012-no-null-chars ex013 \
	ex013-sizeof ex013-wrong-num_states ex014 ex014-strlen \
	ex014-index-out-of-bounds ex015 ex015-all-pointers ex015-all-arrays \
	ex015-print-addresses ex015-functions ex016 ex017 ex017-die ex018 \
	ex018-function-dump ex019 ex022.o ex022_main ex023 ex024 ex025 \
	logfind ex027_1
all:
	make ex001 ex003 ex003-without-age ex003-without-age-value \
	ex007 ex007-without-printf-arg ex007-without-value ex008 \
	ex008-fixed ex009 ex009-backwards ex010 ex010-lowercase-conversion \
	ex011 ex011-change-type ex012 ex012-no-null-chars ex013 \
	ex013-sizeof ex013-wrong-num_states ex014 ex014-strlen \
	ex014-index-out-of-bounds ex015 ex015-all-pointers ex015-all-arrays \
	ex015-print-addresses ex015-functions ex016 ex017 ex017-die ex018 \
	ex018-function-dump ex019 ex023 ex024 ex025 ex027_1
