#ifndef VALIDINPUT_H
#define VALIDINPUT_H

/*
 * this header file contains all validations inputs 
 */

#include <string.h>
#include "patient.h"
#include<stdio.h>


int isValidID(char id[])
{
    for(int i=0;id[i]!='\0';i++)
    {
        if(id[i] >= '0' && id[i] <= '9')
        {
            // is valid
        }
        else
        {
            return 0;
        }
    }
    return 1;

}

int isValidCnic(char cnic[])
{
    if (strlen(cnic) == 15)
    {
        for (int i = 0; cnic[i] != '\0'; i++)
        {
            if((i == 5 || i == 13) && cnic[i] == '-' )
            {
                // is valid
            }
            else if ((cnic[i] >= '0' && cnic[i] <= '9'))
            {
                // Valid
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }
    return 1;
}

int idExists(char id[])
{
    FILE *file;
    file = fopen("patient_record.txt", "r");

    Patient patient;
    while(fread(&patient, sizeof(Patient), 1, file))
    {
        if (strcmp(patient.id, id) == 0)
        {
            return 1;
        }
    }
    fclose(file);

    return 0;
}

int isValidNumber(char number[])
{
    if(strlen(number) == 11)
    {
        for(int i=0;number[i]!='\0';i++)
        {
            if(number[i] >='0' && number[i]<='9')
            {
                // is valid
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }
    return 1;
}

int isValid(char name[])
{
    for(int i=0;name[i]!='\0';i++)
    {
        if((name[i] >= 'A' && name[i] <='Z') || (name[i] >= 'a' && name[i] <='z') || name[i] == ' ')
        {
            // is valid
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int isValidAdmiited(char isAdmiited[])
{
    if(strlen(isAdmiited) == 3 || strlen(isAdmiited) == 2)
    {
        if((strcmp(strlwr(isAdmiited),"yes") == 0) || (strcmp(strlwr(isAdmiited),"no") == 0))
        {
                // valid
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
    return 1;
}

#endif