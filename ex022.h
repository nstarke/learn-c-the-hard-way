#ifndef _ex22_h
#define _ex22_h

// makes THE_SIZE in ex022.c available to other .c files
extern int THE_SIZE;

// gets and sets an internal static variable in ex022.c
int get_age();
void set_age(int age);

// updates a static variable that's inside update_ration
double update_ratio(double ration);

void print_size();

#endif
