#include <stdio.h>
#include <string.h>
#include "dbg.h"

#define MAX_SIZE 1000

int normal_copy(char *from, char *to, int count) {
    int i = 0;

    for (i = 0; i < count; i++) {
        to[i] = from[i];
    }

    return i;
}

int duffs_device(char *from, char *to, int count){

    {
        int n = (count + 7) / 8;

        switch (count % 8) {
            case 0:
                do {
                    *to++ = *from++;
                    case 7:
                    *to++ = *from++;
                    case 6:
                    *to++ = *from++;
                    case 5:
                    *to++ = *from++;
                    case 4:
                    *to++ = *from++;
                    case 3:
                    *to++ = *from++;
                    case 2:
                    *to++ = *from++;
                    case 1:
                    *to++ = *from++;

            } while (--n > 0);
        }
    }

    return count;
}

int zeds_device(char *from, char *to, int count)
{
    {
        int n = (count + 7) / 8;

        switch (count % 8) {
            case 0:
again:
             *to++ = *from++;
            case 7:
            *to++ = *from++;
            case 6:
            *to++ = *from++;
            case 5:
            *to++ = *from++;
            case 4:
            *to++ = *from++;
            case 3:
            *to++ = *from++;
            case 2:
            *to++ = *from++;
            case 1:
            *to++ = *from++;

            if (--n > 0)
                goto again;
        }
    }

    return count;
}

int valid_copy(char *data, int count, char expects) {
    int i = 0;
    for (i = 0; i < count; i++) {
        if (data[i] != expects) {
            log_err("[%d] %c != %c", i, data[i], expects);
            return 0;
        }
    }

    return 1;
}

void print_chars(char *chars, int size){
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%c ", chars[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    char from[MAX_SIZE] = { 'a' };
    char to[MAX_SIZE] = { 'c' };
    int rc = 0;

    debug("Starting");
    // set up the from to have some stuff
    debug("Set up from");
    memset(from, 'x', MAX_SIZE);
    print_chars(from, MAX_SIZE);
    // set it to a failure mode
    debug("Set up to");
    memset(to, 'y', MAX_SIZE);
    print_chars(to, MAX_SIZE);
    check(valid_copy(to, MAX_SIZE, 'y'), "Not initialized correctly");

    // use normal copy to
    rc = normal_copy(from, to, MAX_SIZE);
    check(rc == MAX_SIZE, "Normal copy failed: %d", rc);
    check(valid_copy(to, MAX_SIZE, 'x'), "Normal copy failed");

    // reset
    memset(to, 'y', MAX_SIZE);
    debug("From: ");
    print_chars(from, MAX_SIZE);
    debug("To: ");
    print_chars(to, MAX_SIZE);
    rc = duffs_device(from, to, MAX_SIZE);
    debug("Duffs - From: ");
    print_chars(from, MAX_SIZE);
    debug("Duffs - To: ");
    print_chars(to, MAX_SIZE);

    debug("Duff's value: %d", rc);
    check(rc == MAX_SIZE, "Duff's device failed: %d", rc);
    check(valid_copy(to, MAX_SIZE, 'x'), "Duff's device copy failed");

    // reset
    memset(to, 'y', MAX_SIZE);

    // zed shaw's version
    debug("From: ");
    print_chars(from, MAX_SIZE);
    debug("To: ");
    print_chars(to, MAX_SIZE);
    rc = zeds_device(from, to, MAX_SIZE);
    debug("Zed - From: ");
    print_chars(from, MAX_SIZE);
    debug("Zed - To: ");
    print_chars(to, MAX_SIZE);    debug("Zed's value: %d", rc);
    check(rc == MAX_SIZE, "Zed's device failed: %d", rc);
    check(valid_copy(to, MAX_SIZE, 'x'), "Zed's device failed copy");

    debug("Finishing");
    return 0;
error:
    return 1;
}
