#ifndef SEARCHRECORD_H
#define SEARCHRECORD_H

#include "patient.h"
#include <stdio.h>


void searchRecord()
{
    int isFound = 0;  // this variable is used to 
    FILE *file = fopen("patient_record.txt", "r");

    if (file == NULL)
    {
        printf("File could not be open...\n");
    }
    else
    {
        char id[10];
        printf("\t\tEnter id of the patient which you want to search: ");
        gets(id);


        /*
         * This condition checks if user enter number not directly enter key
         * 
         */
        while (strlen(id) == 0)
        {
            printf("\t\tEnter Id of the patient which you want to search: ");
            fflush(stdin);
            gets(id);
        }

        while (!isValidID(id))
        {
            fflush(stdin);
            printf("\t\tInvalid Number: \n");
            printf("\t\tEnter id of the patient which you want to search: ");
            gets(id);

            while (strlen(id) == 0)
            {
                printf("\t\tEnter Id of the patient which you want to search: ");
                fflush(stdin);
                gets(id);
            }
        }
        Patient patient;

        while (fread(&patient, sizeof(Patient), 1, file))
        {
            if (strcmp(patient.id, id) == 0)
            {

                isFound = 1;
                printf("\n%60s", "PATIENTS INFORMATION");
                printf("\n\t--------------------------------------------");
                printf("--------------------------------------------------------\n");
                printf("\t%-10s%-20s%-20s%-20s%-20s%-10s\n", "Id", "Name",
                       "Cnic", "Phone Number", "Disease", "IsAdmitted");
                printf("\t--------------------------------------------");
                printf("--------------------------------------------------------\n");

                printf("\t%-10s%-20s%-20s%-20s%-20s%-10s", patient.id, patient.name, patient.cnic, patient.phoneNo, patient.disease, strupr(patient.isAdmitted));
                strlwr(patient.isAdmitted);
                printf("\n\t--------------------------------------------");
                printf("--------------------------------------------------------\n");
            }
        }
        fclose(file);
    }
    /*
     * If record is not found  
     * than print message
     */
    if (!isFound)
    {
        printf("\n");
        printf("\t\t-------------------\n");
        printf("\t\tNo Record Found....\n");
        printf("\t\t-------------------\n");
    }
}

#endif