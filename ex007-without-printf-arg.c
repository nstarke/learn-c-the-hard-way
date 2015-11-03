#include <stdio.h>

int main(int argc, char* argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";

    printf("You are %d miles away.\n");
    printf("You have %f levels of power.\n");
    printf("You have %f awesome super powers.\n");
    printf("I have an initial %c.\n");
    printf("I have a first name %s.\n");
    printf("I have a last name %s.\n");
    printf("My whole name is %s %c. %s.\n");

    int bugs = 100;
    double bug_rate = 1.2;

    printf("You have %d bugs at the imaginary rate of %f.\n");

    long universe_of_defects = 1L * 1024L * 1024L * 1024L;

    printf("The entire universe has %ld bugs.\n");

    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %f bugs.\n");

    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the universe.\n");

    // this makes no sense, just a demo of something weird
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    printf("Which means you should care %d%%.\n");

    return 0;
}
