/* 
 * SYSC 2006 Winter 2014 Lab 8
 *
 * Copy these function prototypes and paste them at the end of 
 * the array_list.h file used in Lab 7. 
 */

int intlist_index(const IntList *list, int target);
int intlist_count(const IntList *list, int target);
_Bool intlist_contains(const IntList *list, int target);
void intlist_delete(IntList *list, int index);
_Bool intlist_remove(IntList *list, int target);

void increase_capacity(IntList *list, int new_capacity);

