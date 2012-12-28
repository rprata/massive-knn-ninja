#include <stdio.h>
#include <stdlib.h>
#include "includes/utils.h"

int main (void)
{

	if (!setup()) return 1;

	if (!start()) return 1;
	
	printf (MESSAGE_RESULT, pTestFile, ((float)(total - error)/total)*100);

	return 0;
}