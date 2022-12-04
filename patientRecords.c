
/*
* This program will create two files named patient_record.txt and
* formatted_output.txt. patient_record.txt will be in binary for which is for 
* program. And formatted_output will be in the form user readable form
* so user can easily see and read data from formatted_output.txt
* It will also create third file which is used temporarily for delete and 
* update functions.
*/


#include "addRecord.h"
#include <stdlib.h>

#include "deleteRecord.h"
#include "displayRecords.h"
#include "updateRecord.h"
#include "searchrecord.h"



int main()
{
    /* 
    * checkin if file exists then no need to create file just open it
    * else create a file
    */
    FILE *file;
    file = fopen("patient_record.txt", "r");
    if (file == NULL)
    {
        file = fopen("patient_record.txt", "w");
    }
    fclose(file);

    
    /* 
    * Giving user a menu driven execution
    */

    char choice;
    do
    {
        printf("\n\n\t\t\t--------------------------------------------\n");
        printf("\t\t\tWELCOME TO HOSPITAL RECORD MANAGEMENT SYSTEM\n");
        printf("\t\t\t--------------------------------------------");
        printf("\n\n\t\t----------------------------\n");
        printf("\t\t0. Exit\n");
        printf("\t\t1. Add Patient\n");
        printf("\t\t2. Delete Patient\n");
        printf("\t\t3. Update Patient\n");
        printf("\t\t4. Search Patient\n");
        printf("\t\t5. Display All Patient\n");
        printf("\t\t6. Clear Screen\n");
        printf("\t\t----------------------------\n");

        printf("\t\tIF YOU ENTER MORE THAN 1 CHAR THAN ONLY FIRST CHAR WILL");
        printf("\n\t\tBE TAKEN LIKE IF YOU ENTER 100 THEN 1 WILL BE TAKEN\n");
        printf("\n\t\tEnter your choice : ");
        scanf("%1c", &choice);

        while (choice == 10) // if simply user enter enter than it will store in char so to avoid this
        {
            printf("\n\t\tEnter your choice : ");
            scanf("%1c", &choice);
        }
        fflush(stdin);

        switch (choice)
        {
        case '0':
            break;
        case '1':
            addPatient();
            break;
        case '2':
            deleteRecord();
            break;
        case '3':
            updateRecord();
            break;
        case '4':
            searchRecord();
            break;
        case '5':
            displayAllRecords();
            break;
        case '6':
            system("cls");
            break;

        default:
            printf("\n\t\tInvalid Option!!!\n");
            break;
        }
    } while (choice != '0');

    return 0;
}
