/* 
 * SYSC 2006 Winter 2014 Lab 7
 */

#include <stdbool.h>

struct intlist {
    int     *elems;
    int     capacity;       /* Maximum number of elements in the list. */
    int     size; 		    /* Current number of elements in the list */
};

typedef struct intlist IntList;

IntList  *intlist_construct(int capacity);
void    intlist_destroy(IntList *list);

int     intlist_size(const IntList *list);
int     intlist_capacity(const IntList *list);

_Bool   intlist_append(IntList *list, int element);
int     intlist_get(const IntList *list, int index);
int     intlist_set(IntList *list, int index, int element);
void    intlist_removeall(IntList *list);

void    intlist_print(const IntList *list);
