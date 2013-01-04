#include "list.h"

List * initializeList (Descriptor * descriptor)
{
	descriptor->begin = NULL;
	descriptor->end = NULL;
	descriptor->counter = 0;
	return NULL;
}

List * insertElement (List * list, Descriptor * descriptor, float distance, int clazz)
{
	List * p, * q, *aux;

	p = (List *) malloc(sizeof (List));

	p->distance = distance;
	p->clazz = clazz;
	
	descriptor->counter++;

	if  (list == NULL)
	{
		descriptor->begin = descriptor->end = p;
		p->next = NULL;
		return p;
	}
	else
	{
		q = list;

		if (q->distance <= distance)
		{
			descriptor->end = p;
			p->next = q;
			return p;
		}

		while (q->next != NULL && q->next->distance > distance)
		{
			q = q->next;
		}

		if (q->next == NULL)
			descriptor->begin = p;

		p->next = q->next;
		q->next = p;
		return list;
	}

}

List * removeLastElement (List * list, Descriptor * descriptor)
{
	List * p;

	if(descriptor->counter >= 2)
	{
		p = list->next;
		descriptor->begin = p;
		descriptor->counter--;
		free(list);
		return p;
	}
	else if (descriptor->counter == 1)
	{
		free(list);
		descriptor->begin = descriptor->end = NULL;
		descriptor->counter--;
		return NULL;
	}
	else
	{
		return NULL;
	}
}

void printList(List * list)
	{
	List * p;

	for (p = list; p != NULL; p = p->next)
	{
		printf("distance: %f --- class: %d\n",p->distance, p->clazz);
	}
}

int getEstimatedClassError(List * list, float estimatedClazz)
{
	int counter = 0;

	List * p;

	for (p = list; p != NULL; p = p->next)
	{
		if (p->clazz != estimatedClazz)
		{
			counter++;
		}
	}	

	if (counter > K/2)
		return 1;
	else
		return 0;
}