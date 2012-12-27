#ifndef __GLOBALS_H__
#define __GLOBALS_H__
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SUCCESS 1
#define ERROR 0

static const char * SETUP = "res/setup.txt";
static const char * SETUP_ACCESS_TYPE = "r";

// Globals Variables
char pTrainingFile[20];
char pTestFile[20];
int K;
int numberOfClasses;

#endif