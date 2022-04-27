#include "table_functions.h"

int main()
{
    struct table *tables;
    int command, end=0, num_of_tables=0, tables_size=0, table_num=0;
    printf("Welcome!\n");
    do{
        printf("Enter command:\n"
               "\t1-add a new table\n"
               "\t2-select a table\n");
        scanf("%d",&command);
        switch(command){
        case 1:
            printf("You chose: add a new table.\n");
            ++num_of_tables;
            tables_size = num_of_tables*sizeof(struct table);
            if(num_of_tables==1){
                tables = (struct table*)malloc(tables_size);
            }
            else{
                tables = realloc(tables,tables_size);
            }
            add_table(tables+num_of_tables-1);
            printf("New table added successfully. Current number of tables is: %d\n",num_of_tables);
            break;
        case 2:
            printf("You chose: select a table.\n"
                   "Enter table number: ");
            scanf("%d",&table_num);
            if(table_num-1<=num_of_tables){
                do{
                    printf("Enter a command:\n"
                       "\t1-add an order to the table\n"
                       "\t2-get the bill of the table\n");
                    scanf("%d",&command);
                    switch(command){
                    case 1:
                        printf("You chose: add an order to the table.\n");
                        add_order(tables+table_num-1);
                        break;
                    case 2:
                        printf("You chose: get the bill of the table.\n\n");
                        get_bill(tables+table_num-1);
                        --num_of_tables;
                        break;
                    default:
                        printf("Invalid input! Try again.\n");
                        break;
                    }
                    printf("\nDo you want to continue? (1-Yes 0-No): ");
                    scanf("%d",&end);
                }while(end!=0);
                printf("Returning to main menu...\n");
            }
            else{
                printf("This table does not exist.\n");
            }
            break;
        default:
            printf("Invalid input! Try again.\n");
            break;
        }
        printf("\nDo you want to continue? (1-Yes 0-No): ");
        scanf("%d",&end);
    }while(end!=0);
    free(tables);
    printf("Thank you!Goodbye!\n");
    return 0;
}
