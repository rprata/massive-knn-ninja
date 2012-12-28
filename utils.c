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


List * generateKNNList (List * list, Descriptor * descriptor, float distance, int clazz)
{
	if (descriptor->counter < K)
	{
		list = insertElement (list, descriptor, distance, clazz);
	}
	else
	{
		if (descriptor->begin->distance > distance)
		{
			list = removeLastElement (list, descriptor);
			list = insertElement (list, descriptor, distance, clazz);
		}
	}

	return list;
}

int start()
{
	FILE * pFile;
	char buffer[300];
	char * pValue;

	int counter = 0;
	float fValue[100];

	pFile =	fopen(pTestFile, SETUP_ACCESS_TYPE);

	if (!pFile)
	{
		perror ("Error opening file");
		return ERROR;
	}	

	while (fgets(buffer, 300, pFile) != NULL)
	{
		counter = 0;
		total++;

		if (descriptor != NULL) free (descriptor);
		descriptor = (Descriptor *) malloc(sizeof(Descriptor));

		if (list != NULL) free (list);
		list = initializeList(descriptor);

		pValue = strtok(buffer, " ");
  		while (pValue != NULL)
  		{
  			if (pValue[0] != 13)
  			{
    			fValue[counter] = atof(pValue);
    			counter++;
    		}
    		pValue = strtok (NULL, " ");
  		}

  		testClazz = fValue[counter - 1];

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
	char buffer[300];
	char * pValue;

	int counter = 0;
	float fValue[40];

	float distance;
	int clazz;

	pFile =	fopen(pTrainingFile, SETUP_ACCESS_TYPE);

	if (!pFile)
	{
		perror ("Error opening file");
		return ERROR;
	}	

	while (fgets(buffer, 300, pFile) != NULL)
	{
		counter = 0;
		pValue = strtok(buffer," ");
  		while (pValue != NULL)
  		{
  			if (pValue[0] != 13)
  			{
    			fValue[counter] = atof(pValue);
    			counter++;
    		}
    		pValue = strtok (NULL, " ");
  		}
  		distance = calculatesDistance(elementsTest, fValue, counter);
  		clazz = (int) fValue[counter - 1];
 		list = generateKNNList(list, descriptor, distance, clazz);
	}

	if (getEstimatedClassError(list, testClazz))
		error++;

	fclose (pFile);

	return SUCCESS;

}