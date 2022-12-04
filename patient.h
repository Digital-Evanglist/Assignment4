#ifndef PATIENT_H
#define PATIENT_H


/*
* This header file defines struct patient
*/

typedef struct patient
{
    char id[10]; // taking id in char just to avoid if user enter letter mistakenly
                    // so program do not go in infinte loop
    char name[50];
    char cnic[17];  // cnic number is kept larger just for validation 
    char phoneNo[14];   // number is kept larger just for validation
    char disease[40];
    char isAdmitted[4]; // lenhgth of admitted is kept larger just for validation
}Patient;

#endif