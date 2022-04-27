#ifndef TABLE_FUNCTIONS_H_INCLUDED
#define TABLE_FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

struct order{
    char name[50];
    double price;
};

struct table{
    double bill;
    bool is_taken;
    time_t start_time;
    time_t end_time;
    struct order *orders;
    int num_of_order;
};

void add_table(struct table* currentTable);
void add_order(struct table* currentTable);
void get_bill(struct table* currentTable);

#endif // TABLE_FUNCTIONS_H_INCLUDED
