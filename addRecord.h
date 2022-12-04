#ifndef ADDRECORD_H // this macro will basically use to avoid confliction between files
#define ADDRECORD_H

#include "validInput.h"
#include <stdio.h>
#include "patient.h"
#include "displayRecordsInFile.h"


void addPatient()
{
    FILE *file;
    file = fopen("patient_record.txt", "a");
    if (file == NULL)
    {
        printf("File could not be openend.....\n");
    }
    else
    {
        fflush(stdin);
        Patient patient;
        printf("\n\t\tEnter patient ID : ");
        gets(patient.id);
        /*
         * Following condition checks if user enter directly enter key or not
         */
        while (strlen(patient.id) == 0)
        {
            fflush(stdin);
            printf("\n\t\tEnter patient ID : ");
            gets(patient.id);
        }

        /*
         * Following condition checks if user positive id and no speacial char
         * or alphabets in id
         */
        while (!isValidID(patient.id))
        {
            printf("\n\t\tEnter ID in numbers (positive) no space or special Characters\n");
            printf("\n\t\tEnter patient ID : ");
            gets(patient.id);
        }

        /*
         * Following conditions check if id exists or not in record
         * and than again all above conditions are applied on id
         */
        while (idExists(patient.id))
        {
            fflush(stdin);
            printf("\n\t\tPatient with Id already exists....\n");
            printf("\t\tEnter patient ID : ");
            gets(patient.id);

            while (strlen(patient.id) == 0)
            {
                fflush(stdin);
                printf("\n\t\tEnter patient ID : ");
                gets(patient.id);
            }

            while (!isValidID(patient.id))
            {
                printf("\n\t\tEnter ID in numbers (positive) no space or special Characters\n");
                printf("\n\t\tEnter patient ID : ");
                gets(patient.id);
            }
        }
        fflush(stdin);

        printf("\n\t\tEnter Patient Name : ");
        gets(patient.name);

        /*
         * Following condition checks if user enter name greater than 1
         */
        while (strlen(patient.name) <= 1)
        {
            fflush(stdin);
            printf("\n\t\tEnter name of length greater than 1\n");
            printf("\n\t\tEnter Patient Name : ");
            gets(patient.name);
        }

        /*
         * Following condition checks if user enter name in correct form
         * and than again above condition apply
        */

        while (!isValid(patient.name))
        {
            fflush(stdin);
            printf("\n\t\tNo spacial characeter or digits are allowed in name\n");
            printf("\t\tEnter Patient Name : ");
            gets(patient.name);

            while (strlen(patient.name) <= 1)
            {
                fflush(stdin);
                printf("\n\t\tEnter name of length greater than 1\n");
                printf("\n\t\tEnter Patient Name : ");
                gets(patient.name);
            }
        }

        /*
        * Following condition checks if user cnic in correct form
        */

        fflush(stdin);
        printf("\n\t\tEnter Patient cnic (Fornmat: xxxxx-xxxxxxx-x) : ");
        gets(patient.cnic);

        while (!isValidCnic(patient.cnic))
        {
            fflush(stdin);
            printf("\n\t\tEnter Patient cnic (Fornmat: xxxxx-xxxxxxx-x) : ");
            gets(patient.cnic);
        }

        printf("\n\t\tEnter Patient Phone Number (03*********): ");
        gets(patient.phoneNo);

        while (!isValidNumber(patient.phoneNo))
        {
            fflush(stdin);
            printf("\n\t\tNo space or dash or special character is allowed\n");
            printf("\t\tEnter Phone Number of the Patient (11 digits): ");
            gets(patient.phoneNo);
        }

        /*
        * Following condition checks if user enter disease properly
        */
       
        fflush(stdin);
        printf("\n\t\tEnter Disease Name : ");
        gets(patient.disease);

        while (strlen(patient.disease) <= 1)
        {
            fflush(stdin);
            printf("\n\t\tEnter Disease name of length greater than 1\n");
            printf("\n\t\tEnter Disease Name : ");
            gets(patient.disease);
        }

        while (!isValid(patient.disease))
        {
            fflush(stdin);
            printf("\n\t\tNo spacial characeter or digits are allowed in Disease\n");
            printf("\n\t\tEnter Disease Name : ");
            gets(patient.disease);

            while (strlen(patient.disease) <= 1)
            {
                fflush(stdin);
                printf("\n\t\tEnter Disease name of length greater than 1\n");
                printf("\n\t\tEnter Disease Name : ");
                gets(patient.disease);
            }
        }

        printf("\n\t\tIs Admiited Press YES or NO : ");
        gets(patient.isAdmitted);
        while (!isValidAdmiited(patient.isAdmitted))
        {
            fflush(stdin);
            printf("\t\tPress (YES or NO) small or capital letters.\n");
            printf("\t\tIs Admiited Press YES or NO : ");
            gets(patient.isAdmitted);
        }

        fwrite(&patient, sizeof(Patient), 1, file);
        printf("\n\t\t-------------------\n");
        printf("\t\tRecord Written....|\n");
        printf("\t\t-------------------\n");
        fclose(file);
        // this function writes data to actual file
        displayInFile();

    }
}

#endif