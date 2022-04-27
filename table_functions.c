#include "table_functions.h"

void add_table(struct table* currentTable){
    currentTable->is_taken = true;
    time(&currentTable->start_time);
    currentTable->bill = 0.0;
    currentTable->num_of_order = 0;
}

void add_order(struct table* currentTable){
    if (currentTable->is_taken != false){
        if (currentTable->num_of_order == 0){
            currentTable->orders = (struct order*)malloc(1*sizeof(struct order));
        }
        else{
            currentTable->orders = realloc(currentTable->orders,
                                           (currentTable->num_of_order+1)*sizeof(struct order));
        }
        printf("Enter order name: ");
        fflush(stdin);//clear the '\n' in the buffer
        fgets(currentTable->orders[currentTable->num_of_order].name,
              sizeof(currentTable->orders[currentTable->num_of_order].name),stdin);
        currentTable->orders[currentTable->num_of_order].name[strcspn(currentTable->orders[currentTable->num_of_order].name,"\n")]=0;//clear the '\n' from the end of the string
        printf("Enter order price: ");
        scanf("%lf",&currentTable->orders[currentTable->num_of_order].price);
        printf("Thank you! The order is saved.\n");
        ++(currentTable->num_of_order);
    }
    else{
        printf("Sorry, the table is empty.\n");
    }
}

void get_bill(struct table* currentTable){
    time(&currentTable->end_time);
    printf("Registered in: %s\n",ctime(&currentTable->start_time));
    printf("Registered out: %s\n",ctime(&currentTable->end_time));
    printf("Your orders: \n");
    int order_cnt;
    for (order_cnt= 0; order_cnt<currentTable->num_of_order; ++order_cnt){
        printf("\t%d. %s\t%.2f\n",order_cnt+1,
               currentTable->orders[order_cnt].name,
               currentTable->orders[order_cnt].price);
        currentTable->bill += currentTable->orders[order_cnt].price;
    }
    printf("\n\t\tTotal:\t%.2f\n", currentTable->bill);
    currentTable->is_taken = false;
    free(currentTable->orders);
}
