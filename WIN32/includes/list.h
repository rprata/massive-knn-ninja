#ifndef __LIST_H__
#define __LIST_H__

#include "globals.h"

typedef struct List_st List;

typedef struct Descriptor_st Descriptor;

struct Descriptor_st
{
	List * begin;
	int counter;
	List * end;
};

struct List_st
{
	float distance;
	int clazz;
	List * next;
};

List * list;
Descriptor * descriptor;

List * initializeList (Descriptor * descriptor);
List * insertElement (List * list, Descriptor * descriptor, float distance, int clazz);
List * removeLastElement (List * list, Descriptor * descriptor);

void printList(List * list);
int getEstimatedClassError(List * list, float estimatedClazz);

#endif