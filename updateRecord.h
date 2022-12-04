#ifndef UPDATERECORD_H
#define UPDATERECORD_H

#include "displayRecordsInFile.h"
void updateRecord()
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
		printf("\n\t\tEnter Id of the patient which you want to update: ");
		gets(id);

		while (strlen(id) == 0)
		{
			printf("\t\tEnter Id of the patient which you want to update: ");
			fflush(stdin);
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
			printf("\t\tInvalid Number: \n");
			printf("\t\tEnter id of the patient which you want to update: ");
			gets(id);
			while (strlen(id) == 0)
			{
				printf("\t\tEnter Id of the patient which you want to update: ");
				fflush(stdin);
				gets(id);
			}

			while (id[0] == '-' || id[0] == '0')
			{
				fflush(stdin);
				printf("\t\tEnter positive ID number or greater than 0\n ");
				printf("\t\tEnter Id of the patien which you want to delete: ");
				gets(id);
			}
		}

		if (idExists(id))
		{
			while (fread(&patient, sizeof(Patient), 1, file))
			{
				if (strcmp(patient.id, id) == 0)
				{
					printf("\t\tEnter New Phone Number : ");
					gets(patient.phoneNo);

					while (!isValidNumber(patient.phoneNo))
					{
						fflush(stdin);
						printf("\n\t\tNo space or dash is allowed\n");
						printf("\t\tEnter Phone Number of the Patient (11 digits): ");
						gets(patient.phoneNo);
					}

					fflush(stdin);
					printf("\n\t\tEnter disease name : ");
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

					fflush(stdin);
					printf("\t\tIs Admiited Press YES or NO : ");
					gets(patient.isAdmitted);
					while (!isValidAdmiited(patient.isAdmitted))
					{
						fflush(stdin);
						printf("\t\tPress (YES or NO) small or capital letters.\n");
						printf("\t\tIs Admiited Press YES or NO : ");
						gets(patient.isAdmitted);
					}

					fflush(stdin);

					printf("\n\t\t--------------------------\n");
					printf("\t\tPatient Record Updated....\n");
					printf("\t\t-------------------------\n");
				}
				fwrite(&patient, sizeof(Patient), 1, fileTwo);
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
			// this function writes actual data to user readable form
			displayInFile();
		}
		else
		{
			remove("temp.txt");
			printf("\n");
			printf("\t\t-------------------\n");
			printf("\t\tNo Record Found....\n");
			printf("\t\t-------------------\n");
		}
	}
}

#endif