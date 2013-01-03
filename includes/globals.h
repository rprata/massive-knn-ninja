#ifndef __GLOBALS_H__
#define __GLOBALS_H__
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SUCCESS 1
#define ERROR 0

static const char * SETUP = "setup.txt";
static const char * SETUP_ACCESS_TYPE = "r";

static const char * ERROR_OPEN = "Error opening file";
static const char * ERROR_COMPARE = "Error comparing files";
static const char * MESSAGE_RESULT = "The total hits in exam %s is: %.2f%%\n";

char pTrainingFile[20];
char pTestFile[20];
int K;
int numberOfClasses;

int total;
int error;
float testClazz;

#endif
