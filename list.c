#include "list.h"

List * initializeList (Descriptor * descriptor)
{
	descriptor = (Descriptor *) malloc(sizeof(Descriptor));
	descriptor->begin = NULL;
	descriptor->end = NULL;
	descriptor->counter = 0;
	return NULL;
}

List * insertElement (List * list, Descriptor * descriptor, float distance, int clazz)
{
	List * p;

	p = (List *) malloc(sizeof (List));

	p->distance = distance;
	p->clazz = clazz;
	
	descriptor->counter++;

	if  (list == NULL)
	{
		descriptor->begin = descriptor->end = p;
		p->next = p->previous = NULL;
	}
	else
	{
		descriptor->begin = p;
		p->next = list;
		p->previous = NULL;
		list->previous = p;
	}

	list = p;

	return list;
}

List * sortList(List * list)
{               
    List * p, * q, * aux;

    for (p = list; p != NULL; p = p->next)
    {
    	q = p;
    	while ((q->next->distance < q->distance) && (q->next != NULL)) 
    	{
        	aux = q->next;
            q->next = q;
        	q = aux;
            q = q->next;    
        }               
    }

    return list;
}

List * removeLastElement (List * list)
{


	return list;
}

void printList(List * list)
{
	List * p;

	for (p = list; p != NULL; p = p->next)
	{
		printf("distance: %f --- class: %d\n",p->distance, p->clazz);
	}

}

