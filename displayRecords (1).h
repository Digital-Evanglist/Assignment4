#ifndef DISPLAYRECORDS_H
#define DISPLAYRECORDS_H

#include "patient.h"

void displayAllRecords()
{
	int counter = 0;
    FILE *file = fopen("patient_record.txt","r");

    if(file == NULL)
    {
        printf("File could not be open...\n");
    }
    else
    {
        Patient patient;
        printf("\n%60s","PATIENTS RECORDS");
        printf("\n\t--------------------------------------------");
        printf("--------------------------------------------------------\n");
		printf("\t%-10s%-20s%-20s%-20s%-20s%-10s\n","Id","Name",
			"Cnic","Phone Number","Disease","IsAdmitted");
            printf("\n\t--------------------------------------------");
            printf("--------------------------------------------------------\n");
       while(fread(&patient,sizeof(Patient),1,file))
       {
       		counter++;
			printf("\t%-10s%-20s%-20s%-20s%-20s%-10s",patient.id
			,patient.name,patient.cnic,patient.phoneNo,patient.disease,strupr(patient.isAdmitted));
            strlwr(patient.isAdmitted);
              printf("\n\t--------------------------------------------");
            printf("--------------------------------------------------------\n");
       }
       fclose(file);

    }

    /*
    *   This condition checks if no records exist
    */
    if(counter == 0)
    {
    	printf("\n");
		printf("\t\t-------------------\n");
		printf("\t\tNo Record Found....\n");
		printf("\t\t-------------------\n");
		
	}
}

#endif