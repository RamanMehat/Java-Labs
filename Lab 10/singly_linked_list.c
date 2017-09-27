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

//Lab 9

// Exercise 1
int count(IntNode *head, int target)
{
    int count = 0;	
	for (IntNode *p = head; p != NULL; p = p->next){
		if (p->value == target){
			count++;
		}
	}
	return count;
} 

// Exercise 2
int index(IntNode *head, int target)
{
 	int index = 0;
	if (head == NULL){
		return -1;
	}
	for (IntNode *p = head; p != NULL; p = p->next){
		if (p->value == target){
			return index;
		}
		else{
			index++;
		}
	}  
	return -1;
}

// Exercise 3
int fetch(IntNode *head, int index)
{
 	assert (head != NULL);   
	int t = 0;
	for (IntNode *p = head; p != NULL; p = p->next){
		t++;
	}
	assert (index >= 0 && index < t);
	IntNode *p = head;
	for (int i = 0; i < index; i++){
		p = p->next;
	}
	return p->value;	
}

// Exercise 4
IntNode *remove_last_one_pointer(IntNode *head)
{
 	assert (head != NULL);
	IntNode *p = NULL;
 	if (head->next == NULL) {
        free(head);
        head = NULL;
    } 
	else {
		for (p = head; p->next->next != NULL; p = p->next){
		//Do nothing. p points to the last node after this loop.
		}
		free(p->next->next);
		p->next = NULL;
	}
	return head;
}

// Lab 10
//Exercise 1
IntNode *insert(IntNode *head, int index, int x)
{
 	int t = 0;
	for (IntNode *p = head; p != NULL; p = p->next){
		t++;
	}
	
	if (t == 0){	 //linked list is empty
		assert (index >= 0);
		head = intnode_construct(x, head);
	}
	else if (t > 0){	//linked list has more than one pointer
		assert (index >= 0 && index <= t);
		if (index == 0){
			IntNode *new = intnode_construct(x,head);
			head = new;
		}
		else if (index - 1 == t){ 
			IntNode *p = head;
			for (; p != NULL; p = p->next){
				//p points to the last node
			}
			p->next = intnode_construct(x,NULL);
		}
		else{
			IntNode *p = head;
			for (int i = 0; i < index-1; i++){
				p = p->next;
			}
			p->next = intnode_construct(x,p->next);
		}
	}
	return head;
}

//Exercise 2
IntNode *delete(IntNode *head, int index)
{
	int t = 0;
	for (IntNode *p = head; p != NULL; p = p->next){
		t++;
	}
	assert (head != NULL);	//if linked list is empty
	if (t == 1){	//there is just one node
		assert (index >= 0 && index <= t);
		if (index == 0){
			free(head->next);
			head = NULL;
		}
	}
	else{		//there are two or more nodes
		assert (index >= 0 && index <= t);
		if (index == 0){
			IntNode *p = head;
			head = p->next;
			free (p);
		}
		else if (index == t-1){
			IntNode *p = head;
			for (p = head; p->next->next != NULL; p = p->next){
				//p points to the second last node after this loop.
			}
			free(p->next->next);
			p->next = NULL;
		}
		else{
			IntNode *p = head;
			for (int i = 0; i < index-1; i++){
				p = p->next;
			}
			p->next = p->next->next;
			free(p->next->next);
		}
	}
	return head;
}

//Exercise 3
IntNode *delete_target(IntNode *head, int target, 
 _Bool *removed)
{
 	*removed = false;	
	
	int t = 0;
	for (IntNode *p = head; p != NULL; p = p->next){
		t++;
	}
	if (t == 0){
		head = NULL;
		return head;
	}
	if (t == 1){
		if (head->value == target){
			free(head);
			head = NULL;
			*removed = true;
			return head;
		}
	}
	else{
		IntNode *p = head;
		if (p->value == target){
			head = p->next;
			free(p);
			*removed = true;
			return head;
		}
		for (p = head; p->next->next != NULL; p = p->next){
			//p points to the second last node after this loop.
		}
		if (p->next->value == target){
			free(p->next->next);
			p->next = NULL;
			*removed = true;
			return head;
		}
		for (p = head; p->next->next != NULL; p = p->next){
			if (p->next->value == target){
				p->next = p->next->next;
				free(p->next->next);
				*removed = true;
				return head;
			}
		}
	}
	
	
	return head;
}
