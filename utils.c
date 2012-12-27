#include "includes/utils.h"

int setup()
{
	FILE * pFile;
	char buffer[200];

	int counter = 0;

	pFile =	fopen(SETUP, SETUP_ACCESS_TYPE);

	if (!pFile)
	{
		perror ("Error opening file");
		return ERROR;
	}

	while (fgets(buffer, 200, pFile) != NULL)
	{
		switch (counter)
		{
			case 0:
			  	memcpy (pTrainingFile, buffer, strlen(buffer) - 1);
				break;
			case 1:
				memcpy (pTestFile, buffer, strlen(buffer) - 1);
				break;
			case 2:
				K = atoi(buffer);
					break;
			case 3:
			   	numberOfClasses = atoi(buffer);
				break;
			default:
				break;
		}
		counter++;
	}
 
    fclose (pFile);

    return SUCCESS;
}

float calculatesDistance (float elementsTest[], float elementsTraining[], int counter)
{
	int i;
	float result = 0;
	for(i = 0; i < counter - 1; i++)
	{
		result += pow((elementsTraining[i] - elementsTest[i]), 2);
	}

	return sqrt(result);
}


List * generateKNNList (List * list, float distance, int clazz)
{

	return list;
}

int start()
{
	FILE * pFile;
	char buffer[30];
	char * pValue;

	int counter = 0;
	float fValue[20];

	// list = initializeList(descriptor);

	pFile =	fopen(pTestFile, SETUP_ACCESS_TYPE);

	if (!pFile)
	{
		perror ("Error opening file");
		return ERROR;
	}	

	while (fgets(buffer, 30, pFile) != NULL)
	{
		counter = 0;
		pValue = strtok(buffer," ");
  		while (pValue != NULL)
  		{
    		fValue[counter] = atof(pValue);
    		counter++;
    		pValue = strtok (NULL, " ");
  		}
  		if(!compareFiles(fValue))
  		{
  			perror ("Error comparing files");
  			return ERROR;
  		}
	}

	fclose (pFile);

	return SUCCESS;

}

int compareFiles(float elementsTest[])
{
	FILE * pFile;
	char buffer[30];
	char * pValue;

	int counter = 0;
	float fValue[20];

	float distance;
	int clazz;

	pFile =	fopen(pTrainingFile, SETUP_ACCESS_TYPE);

	if (!pFile)
	{
		perror ("Error opening file");
		return ERROR;
	}	

	while (fgets(buffer, 30, pFile) != NULL)
	{
		counter = 0;
		pValue = strtok(buffer," ");
  		while (pValue != NULL)
  		{
    		fValue[counter] = atof(pValue);
    		counter++;
    		pValue = strtok (NULL, " ");
  		}
  		distance = calculatesDistance(elementsTest, fValue, counter);
  		clazz = (int) fValue[counter - 1];
  		printf("%f\n", distance);
//  		generateKNNList(list, distance, clazz);
	}

	fclose (pFile);

	return SUCCESS;

}