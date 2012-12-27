#include <stdio.h>
#include <stdlib.h>
#include "includes/utils.h"

int main (void)
{

	if (!setup()) return 1;

   	printf("%s\n", pTrainingFile);
   	printf("%s\n", pTestFile);
   	printf("%d\n", K);
   	printf("%d\n", numberOfClasses);

	descriptor = (Descriptor *) malloc(sizeof(Descriptor));

	list = initializeList(descriptor);
	if (descriptor->begin == NULL) printf("testeeee\n");
	//if(!start()) return 1;

	list = insertElement (list, descriptor, 4.0, 1);
	if (descriptor->begin == NULL) printf("testeeee2\n");
	list = insertElement (list, descriptor, 1.0, 1);

	list = insertElement (list, descriptor, 3.0, 1);

	list = insertElement (list, descriptor, 1.0, 1);

	printList(list);

	return 0;
}