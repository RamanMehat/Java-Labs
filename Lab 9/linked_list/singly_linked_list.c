/* SYSC 2006 Winter 2014 Lab 9
   A module that implements a singly-linked list of integers. 
   Version 1.02 - dlb 
 */

#include <assert.h>  // assert
#include <stdlib.h>  // malloc, free
#include <stdbool.h>
#include <stdio.h>   // printf

#include "singly_linked_list.h"

/* Return a pointer to a new IntNode (a node in a singly-linked list).

   Parameter value: the integer to be stored in the node.
   Parameter next: a pointer to the node that the new node should point to.
   This pointer should be NULL if the new node is the last node in the 
   linked list.
   Terminate (via assert) if memory for the node cannot be allocated.
 */ 
IntNode *intnode_construct(int value, IntNode *next)
{
    IntNode *p = malloc(sizeof(IntNode));
    assert (p != NULL);
    p->value = value;
    p->next = next;
    return p;
}

/* Print the linked list pointed to by p.
 */
void print_linked_list(IntNode *p)
{
	if (p == NULL) {
		printf("empty list");
		return; 
 	}

	/* Print every node in the linked list except the last one,
	   using the format: value1 -> value2 -> value3 -> ...
	 */
	for (; p->next != NULL; p = p->next) {
		printf("%d -> ", p->value);
	}

	/* Print the last node. */
	printf("%d", p->value);
}

/* Return true if the linked list pointed to by head contains the
   specified value; otherwise return false.
 */ 
_Bool contains(IntNode *head, int value)
{
    IntNode *p;

    for (p = head; p != NULL; p = p->next) {
        if (value == p->value) {
            return true;
        }
    }
    return false;
} 

/* A version of contains that eliminates local variable p.
   Make sure you understand why we don't need that variable.
   Make sure you understand why the statement head = head->next
   does not mangle the linked list passed to this function.
   (Hint: draw a memory diagram showing the stack frames for
   this function and its caller.)
 */
_Bool contains_shorter(IntNode *head, int value)
{
    for ( ; head != NULL; head = head->next) {
        if (value == head->value) {
            return true;
        }
    }
    return false;
} 

/* Insert a node containing the specified integer value at the front 
   of the linked list pointed to by head, and return a pointer to the 
   first node in the modified list.
 */
IntNode *insert_front(IntNode *head, int value)
{
    return intnode_construct(value, head);
}

/* Append a node containing the specified integer value at the rear 
   of the linked list pointed to by head, and return a pointer to the 
   first node in the modified list.

   Exercise - can we replace local variable p with parameter head?
 */
IntNode *append_rear(IntNode *head, int value)
{
    if (head == NULL) {
        /* Appending a node to the end of an empty linked list
         * is the same as inserting a node at the front of an 
         * empty linked list.
         */
        head = intnode_construct(value, head /* NULL */); 
    } else {
        IntNode *p;

		// Traverse the linked list until p points to the last node.

        for (p = head; p->next != NULL; p = p->next) 
        {}

        p->next = intnode_construct(value, p->next /* NULL */);
    }
	return head;
}

/* Remove the node at the front of the linked list pointed to by head, 
   and return a pointer to the first node in the modified list.
   Terminate (via assert) if asked to remove a node from an empty 
   linked list.
 */
IntNode *remove_first(IntNode *head)
{
    assert(head != NULL);

	/* We need to retrieve the pointer to the second node (or NULL, if the
	   list contains one node) BEFORE we free the first node.
	   Remember, the result of accessing a node after it has been
	   freed in undefined.
	 */
    IntNode *p = head;
    head = head->next;
    free(p);
	return head;
}

/* Remove the node at the rear of the linked list pointed to by head, 
   and return a pointer to the first node in the modified list.
   Terminate (via assert) if asked to remove a node from an empty 
   linked list.

   Exercise: rewrite this function to use a single pointer to
   traverse and modify the linked list, instead of two pointers (p1 and p2).
 */
IntNode *remove_last(IntNode *head)
{
    assert(head != NULL);
    
    if (head->next == NULL) {
        /* There is exactly one node in the linked list. */
        free(head);
        head = NULL;
    } else {
        IntNode *p1, *p2 = NULL;
        for (p1 = head; p1->next != NULL; p1 = p1->next) {
            p2 = p1;
        } 

        /* Now p1 points to the last node and p2 points to the node before
         * the last node.
         */
        free(p1);
        p2->next = NULL;
    }
	return head;
}

// Exercise 1
int count(IntNode *head, int target)
{
	int count = 0;
	IntNode *node = head;
	while (node){
		if (node -> value == target)
			count++;
		node = node -> next;
	}
    return count;
} 

// Exercise 2
int index(IntNode *head, int target)
{
	int index = 0;
	IntNode *node = head;
	while (node){
		if (node -> value == target)
			return index;
		node = node -> next;
		index++;
	}
    return -1;
}

// Exercise 3
int fetch(IntNode *head, int index)
{
	assert(head != NULL);
	assert(index >= 0);
	
	IntNode *node = head;
	int count = 0;
	while (node){
		if (count == index)
			return (node -> value);
		count++;
		node = node -> next;
	}
	assert(index <= count);
	return -1;
}

// Exercise 4
IntNode *remove_last_one_pointer(IntNode *head)
{
	assert(head != NULL);
	
	IntNode *node = head;
	if(node -> next){
		while (node -> next -> next)
			node = node -> next;
		free(node -> next);
		node -> next = NULL;
	}
	else
		return NULL;
    return head;
}
