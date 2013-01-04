#ifndef __UTILS_H__
#define __UTILS_H__

#include "globals.h"
#include "list.h"

typedef struct testElement_st testElement;

struct testElement_st
{
	float vec[20];
	int counter;
};

testElement tElement;

int setup();
int start();
int compareFiles(float elementsTest[]);

#endif
