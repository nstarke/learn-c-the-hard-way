#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "dbg.h"

int search_file(char *file_name, char *search_strings[]) {
    FILE *file;
    int line_number = 1;
    char place_holder[512];

    file = fopen(file_name, "r");
    check(file != NULL, "Problem opening file");
    debug("Starting to loop over each line");
    while(fgets(place_holder, 512, file) != NULL) {
        int arg_index = 0;
        int search_string_count = 0;
        int find_value = 0;
        debug("Starting to loop through search strings");
        for (arg_index = 0; search_strings[arg_index] != NULL; arg_index++){
            if (strstr(place_holder, search_strings[arg_index])){
                find_value++;
            }
            search_string_count++;
        }

        if (search_string_count == find_value) {
            printf("%s:%d - %s", file_name, line_number, place_holder);
        }

        line_number++;
    }

    return 0;
error:
    return -1;
}

int main(int argc, char *argv[]) {
    char *search_strings[argc];
    int arg_index = 0;
    for (arg_index = 0; arg_index <= argc; arg_index++){
        if (arg_index == 0){
            continue;
        }
        if (arg_index == argc){
            search_strings[arg_index - 1] = NULL;
        } else {
            search_strings[arg_index - 1] = argv[arg_index];
        }
    }
    int i = 0;
    for (i = 0; i < arg_index - 1; i++) {
        printf("search string at index %d: %s\n", i, search_strings[i]);
    }

    return search_file("/var/log/syslog", search_strings);
}
