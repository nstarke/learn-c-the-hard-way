#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

#include "dbg.h"

#define MAX_SIZE 512
int search_file(char *file_name, char *search_strings[]) {
    debug("search_file called for file: %s", file_name);
    FILE *file;
    int line_number = 1;
    char place_holder[MAX_SIZE];

    file = fopen(file_name, "r");
    check(file != NULL, "Problem opening file");
    debug("Starting to loop over each line");
    while(fgets(place_holder, MAX_SIZE, file) != NULL) {
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

    fclose(file);
    return 0;

error:
    if (file) fclose(file);
    return -1;
}

char *trim_white_space(char *str)
{
  char *end;

  // Trim leading space
  while(isspace(*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

int parse_logfind_file(char *search_strings[]) {
    FILE *logfind_file;
    char file_name_line[MAX_SIZE];

    logfind_file = fopen(".logfind", "r+");
    check(logfind_file != NULL, "Problem opening .logfind file");
    while(fgets(file_name_line, MAX_SIZE, logfind_file) != NULL) {
        search_file(trim_white_space(file_name_line), search_strings);
    }

    fclose(logfind_file);
    return 0;

error:
    if (logfind_file) fclose(logfind_file);
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
       debug("search string at index %d: %s", i, search_strings[i]);
    }

    parse_logfind_file(search_strings);

    return 0;
}
