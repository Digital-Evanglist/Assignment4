#ifndef DISPLAYRECORDSINFILE_H
#define DISPLAYRECORDSINFILE_H


/*
* This function basically converts the binary data into user reradable data
*/

#include<stdio.h>
#include "patient.h"

void displayInFile()
{
    int counter = 0;
    Patient patient;
    FILE* file = fopen("patient_record.txt","r");
    FILE *outputFile = fopen("formatted_output.txt","w");

    if(file == NULL || outputFile == NULL)
    {
        printf("\t\tFile could not open\n");
    }
    else
    {
        fprintf(outputFile,"\n%60s","PATIENTS RECORDS");
        fprintf(outputFile,"\n\t--------------------------------------------");
        fprintf(outputFile,"--------------------------------------------------------\n");
		fprintf(outputFile,"\t%-10s%-20s%-20s%-20s%-20s%-10s\n","Id","Name",
			"Cnic","Phone Number","Disease","IsAdmitted");
            fprintf(outputFile,"\n\t--------------------------------------------");
            fprintf(outputFile,"--------------------------------------------------------\n");
        while(fread(&patient,sizeof(Patient),1,file))
        {
            counter++;
			fprintf(outputFile,"\t%-10s%-20s%-20s%-20s%-20s%-10s",patient.id
			,patient.name,patient.cnic,patient.phoneNo,patient.disease,strupr(patient.isAdmitted));
            strlwr(patient.isAdmitted);
            fprintf(outputFile,"\n\t--------------------------------------------");
            fprintf(outputFile,"--------------------------------------------------------\n");

        }
        fclose(file);
        fclose(outputFile);
    }
}

#endif