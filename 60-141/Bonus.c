#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inputFile "assign6.dat"
#define outputFile "assign6out.dat"

/* Structure Definition */
typedef struct StudentStruct
{
	int ID;
	float Grades[10];
	float GPA;
} studentInfo;

/* Function Protoypes */
void loadData(int *recCount, int *inputByteCount, int *outputByteCount);
void sortData(FILE *filePtr, int numRecords);
void printData(FILE *filePtr);

/* Main Function */
int main()
{
	int Count;
	int inputBytes = 0;
	int outputBytes = 0;

	loadData(&recordCount, &inputBytes, &outputBytes);

	FILE *filePtr = fopen("assign6out.dat", "rb+");		//  Open for reading and writing binary

	sortData(filePtr, recordCount);

	printData(filePtr);

	printf("Input Bytes: %d.\nStored Bytes: %d.\n", inputBytes, outputBytes);

	return 0;

}

/* Load Data
Purpose:	
Input:		
Output:		*/
void loadData(int *recCount, int *inByteCount, int *outByteCount)
{
	FILE *FilePtr1 = fopen(inputFile, "r");		// Open for reading
	FILE *FilePtr2 = fopen(outputFile, "wb");	// Open for writing binary
	studentInfo tempStruct;
	
	char tempString[100], *token;
	float tempFloat = 0;

	fscanf(inFilePtr, " %[^\n]s", tempString);	// Take input from file
	
	while(!feof(inFilePtr))
	{
		(*recCount)++;

		tempStruct.GPA = 0;

		*inByteCount += sizeof(char) * strlen(tempString);	// Tally of bytes inputted
		*outByteCount += sizeof(studentInfo);	// Tally of bytes outputted

		token = strtok(tempString, " ");
		tempStruct.ID = atoi(token);

		for(int i = 0; i < 10; i++)		// Loops through for 10 student records
		{
			token = strtok(NULL, " \n");
			tempFloat = atof(token);
			tempStruct.Grades[i] = tempFloat;
			tempStruct.GPA += tempFloat;
		}

		tempStruct.GPA/=10;

		fwrite(&tempStruct, sizeof(studentInfo), 1, FilePtr2);	// Writes to output file
		fscanf(FilePtr1, " %[^\n]s", tempString);	// Scan next input
	}
}

/* Sort Data
Purpose:	
Input:		
Output:		*/
void sortData(FILE *Ptr, int numRecords)
{
	if(numRecords <= 1) return;

	studentInfo tempStruct1, tempStruct2;
	int swapPos = 0, swapID;
	fseek(Ptr, 0, SEEK_SET);	// Initializes the location in the file pointer to start from
	fread(&tempStruct1, sizeof(studentInfo), 1, Ptr);	// Fills a line of a temporary structure from file pointer
	swapID = tempStruct1.ID;

	for(int i = 1; i < numRecords; i++)
	{
		fread(&tempStruct1, sizeof(studentInfo), 1, Ptr);	// Fills next line of the temporary structure from file pointer

		if(tempStruct1.ID > swapID)	
		{
			swapID = tempStruct1.ID;
			swapPos = i;
		}
	}

	fseek(Ptr, swapPos * sizeof(studentInfo), SEEK_SET);
	fread(&tempStruct2, sizeof(studentInfo), 1, Ptr);
	fseek(Ptr, -sizeof(studentInfo), SEEK_CUR);
	fwrite(&tempStruct1, sizeof(studentInfo), 1, Ptr);
	fseek(Ptr, (numRecords-1)*sizeof(studentInfo), SEEK_SET);
	fwrite(&tempStruct2, sizeof(studentInfo) , 1, Ptr);

	return sortData(Ptr, numRecords-1);

}

/* Print Data
Purpose:	
Input:		
Output:		*/
void printData(FILE *Ptr)
{
	studentInfo tempStruct;
	fseek(Ptr, 0, SEEK_SET);	// Initializes the location in the file pointer to start from
	fread(&tempStruct, sizeof(studentInfo), 1, Ptr);	// Fills a line of a temporary structure from file pointer

	while(!feof(Ptr))	// Loops until file pointer is empty
	{
		printf("ID: %-6d Grades: ", tempStruct.ID);

		for(int i = 0; i < 10; i++)
		printf("%-5.1f ", tempStruct.Grades[i]);

		printf("GPA: %-3.1f\n", tempStruct.GPA);
		fread(&tempStruct, sizeof(studentInfo), 1, Ptr);	// Fills next line of the temporary structure from file pointer
	}
}