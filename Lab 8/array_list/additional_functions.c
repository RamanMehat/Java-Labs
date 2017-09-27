/* 
 * SYSC 2006 Winter 2014 Lab 8
 *
 * Copy these incomplete function definitions and paste them at the end of 
 * the array_list.c file you developed in Lab 7. 
 */

/* Return the index (position) of the first occurrence of an integer
 * equal to target in the list pointed to by parameter list. 
 * Return -1 if target is not in the list.
 * Terminate the program via assert if list is NULL.
 */
int intlist_index(const IntList *list, int target)
{
    return -1;
}

/* Count the number of integers that are equal to target, in the list 
 * pointed to by parameter list, and return that number.
 */
int intlist_count(const IntList *list, int target)
{
    return -1;
}

/* Determine if an integer in the list pointed to by parameter list 
 * is equal to target.
 * Return true if target is in the list, otherwise return false.
 * Terminate the program via assert if list is NULL.
 */
_Bool intlist_contains(const IntList *list, int target)
{
    return false;
}

/* Delete the integer at the specified position in the list pointed
 * to by parameter list.
 * Parameter index is the position of the integer that should be removed.
 * Terminate the program via assert if list is NULL, or if index
 * is not in the range 0 .. intlist_size() - 1.

 */
void intlist_delete(IntList *list, int index)
{
}

/* Remove the first occurrence of an integer equal to target in the list 
 * pointed to by parameter list. 
 * Return true if target was found and deleted; otherwise return false.
 * Terminate the program via assert if list is NULL.
 */
_Bool intlist_remove(IntList *list, int target)
{
    return false;
}

/* Increase the capacity of the list pointed to by parameter list to
 * the specified new capacity.
 * Terminate the program via assert if new_capacity not greater than the
 * list's current capacity.
 */
void increase_capacity(IntList *list, int new_capacity)
{
}
