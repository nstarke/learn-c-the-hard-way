#include <stdio.h>

void first(int ages[], char *names[], int count) {
    int i = 0;

    // first way using indexing
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");
}

void second(int *cur_age, char **cur_name, int count) {
    int i = 0;
    // second way using pointers
    for (i = 0; i < count; i++) {
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");
}

void third(int *cur_age, char **cur_name, int count) {
    int i = 0;

    // third way, pointers are just arrays
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");
}

void fourth(int *cur_age, char **cur_name, int ages[], char *names[], int count) {
    // fourth way with pointers in a stupid complex way
    for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }
}

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = { 23, 43, 12, 89, 2 };

    char *names[] = {
        "Alan", "Frank", "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);

    first(ages, names, count);

    // set up the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    second(cur_age, cur_name, count);

    third(cur_age, cur_name, count);

    fourth(cur_age, cur_name, ages, names, count);
    return 0;
}
