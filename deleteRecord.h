#ifndef DELETERECORD_h
#define DELETERECORD_h

#include "patient.h"
#include <stdio.h>
#include "validInput.h"
#include "displayRecordsInFile.h"

void deleteRecord()
{
	FILE *file = fopen("patient_record.txt", "r");
	FILE *fileTwo = fopen("temp.txt", "w");

	if (file == NULL || fileTwo == NULL)
	{
		printf("File could not be opened...\n");
	}
	else
	{
		char id[10];
		Patient patient;
		Patient temp;
		printf("\t\tEnter Id of the patien which you want to delete: ");
		gets(id);

		while (strlen(id) == 0)
		{
			fflush(stdin);
			printf("\t\tEnter Id of the patien which you want to delete: ");
			gets(id);
		}

		while (id[0] == '-' || id[0] == '0')
		{
			fflush(stdin);
			printf("\t\tEnter positive ID number or greater than 0\n ");
			printf("\t\tEnter Id of the patien which you want to delete: ");
			gets(id);
		}

		while (!isValidID(id))
		{
			fflush(stdin);
			printf("\t\tNot Valid ID No space or spceial characters\n");
			printf("\t\tEnter Id of the patien which you want to delete: ");
			gets(id);

			while (strlen(id) == 0)
			{
				fflush(stdin);
				printf("\t\tEnter Id of the patien which you want to delete: ");
				gets(id);
			}

			while (id[0] == '-' || id[0] == '0')
			{
				fflush(stdin);
				printf("\t\tEnter positive ID number or greater than 0\n ");
				printf("\t\tEnter Id of the patien which you want to delete: ");
				gets(id);
			}

			while (strlen(id) == 0)
			{
				fflush(stdin);
				printf("\t\tEnter Id of the patien which you want to delete: ");
				gets(id);
			}
		}

		if (idExists(id))
		{
			while (fread(&patient, sizeof(Patient), 1, file))
			{
				if (strcmp(patient.id, id) != 0)
				{
					fwrite(&patient, sizeof(Patient), 1, fileTwo);
				}
				else
				{
					temp = patient;
				}
			}
			fclose(file);
			fclose(fileTwo);

			file = fopen("patient_record.txt", "w");
			fileTwo = fopen("temp.txt", "r");

			while (fread(&patient, sizeof(patient), 1, fileTwo))
			{
				fwrite(&patient, sizeof(patient), 1, file);
			}

			fclose(file);
			fclose(fileTwo);
			remove("temp.txt");

			printf("\n%60s", "DELETED PATIENT INFORMATION");
			printf("\n\t--------------------------------------------");
			printf("---------------------------------------------------\n");
			printf("\t%-10s%-20s%-20s%-15s%-20s%-10s\n", "Id", "Name",
				   "Cnic", "Phone Number", "Disease", "IsAdmitted");
			printf("\t--------------------------------------------");
			printf("---------------------------------------------------\n");

			printf("\t%-10s%-20s%-20s%-15s%-20s%-10s", temp.id, temp.name, temp.cnic, temp.phoneNo, temp.disease, strupr(temp.isAdmitted));

			printf("\n\t--------------------------------------------");
			printf("---------------------------------------------------\n");
		}
		else
		{
			remove("temp.txt");
			fclose(fileTwo);
			printf("\n");
			printf("\t\t-------------------\n");
			printf("\t\tNo Record Found....\n");
			printf("\t\t-------------------\n");
		}

		/*
		* This function writes the data in formatted_output.txt
		* in user readable form
		*/
		displayInFile();
	}
}

#endif