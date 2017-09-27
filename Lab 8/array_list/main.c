/* main.c - SYSC 2006 Winter 2014 Lab 8 Test Harness */

#include <stdlib.h>  // exit, malloc, free
#include <stdio.h>   // printf
#include "sput.h"

#include "array_list.h"

/* By default, Pelles C generates "warning #2154: Unreachable code"
   and "warning #2130: Result of comparison is constant" when the 
   macros in sput.h are used. The following pragma directive disables the
   generation of these warnings.
 */
#pragma warn(disable: 2130 2154)

static _Bool compare_arrays(int arr1[], int arr2[], int n)
{
    for (int i = 0; i < n; i = i + 1) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

static void test_intlist_construct(void)
{
    IntList *list = intlist_construct(10);
    sput_fail_unless(list->capacity == 10,
                     "list = intlist_construct(10),\n"
                     "verifying list->capacity == 10");
    sput_fail_unless(list->size == 0,
                     "list = intlist_construct(10),\n"
                     "verifying list->size == 0");
    sput_fail_unless(list->elems != NULL,
                     "list = intlist_construct(10),\n"
                     "verifying list->elems is not NULL");

    intlist_destroy(list);
}

static void test_intlist_print(void)
{
    printf("\nTesting intlist_print\n\n");

    IntList *list = intlist_construct(4);

    /* Print [] */

	list->size = 0;

    /* We can't assume that intlist_print is working, so we can't call it
     * to display the expected output!
     */
	printf("Expected output: []\n");
	printf("Actual output:   ");
	intlist_print(list);
	printf("\n\n");

    /* Print [1] */

	/* We can't assume intlist_append is working, so we have to initialize
	 * the list ourselves.
	 */
	list->elems[0] = 1;
	list->size = 1;

	printf("Expected output: [1]\n");
	printf("Actual output:   ");
	intlist_print(list);
	printf("\n\n");

    /* Print [1, 5, -3, 9] */

	list->elems[0] = 1;
	list->elems[1] = 5;
	list->elems[2] = -3;
	list->elems[3] = 9;
	list->size = 4;

	printf("Expected output: [1 5 -3 9]\n");
	printf("Actual output:   ");
	intlist_print(list);
	printf("\n\n");

    intlist_destroy(list);
}

static void test_intlist_append(void)
{
    _Bool appended;
    int expected[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    
    IntList *list = intlist_construct(10);

    appended = intlist_append(list, 0);
    sput_fail_unless(appended == true, 
                     "append 0 to empty list\n"
                     "verifying return value is true");
    sput_fail_unless(list->size == 1,
                     "verifying list size is 1");
    sput_fail_unless(compare_arrays(list->elems, expected, 1), 
                     "verifying list is [0]");

    appended = intlist_append(list, 2);
    sput_fail_unless(appended == true, 
                     "append 2 to [0]\n"
                     "verifying return value is true");
    sput_fail_unless(list->size == 2,
                     "verifying list size is 2");
    sput_fail_unless(compare_arrays(list->elems, expected, 2), 
                     "verifying list is [0, 2]");

    for (int i = 2; i < 9; i++) {
        appended = intlist_append(list, 2 * i);
    }
    /* The list is now [0, 2, 4, ..., 16], size == 9, capacity == 10 */

    appended = intlist_append(list, 18);
    sput_fail_unless(appended == true, 
                     "append 18 to [0, 2, 4, ..., 16]\n"
                     "verifying return value is true");
    sput_fail_unless(list->size == 10,
                     "verifying list size is 10");
    sput_fail_unless(compare_arrays(list->elems, expected, 10), 
                     "verifying list is [0, 2, 4, ..., 18]");

#ifdef notdef
    /* These tests assume that intlist_append doesn't increase
     * the capacity of a full list.
     */

    /* Now attempt to append an integer to a full list.*/

    appended = intlist_append(list, 20);
    sput_fail_unless(appended == false, 
                     "append 20 to full list,\n"
                     "verifying return value is false");
    sput_fail_unless(list->size == 10,
                     "verifying list size is 10");
    sput_fail_unless(compare_arrays(list->elems, expected, 10), 
                     "verifying list is [0, 2, 4, ..., 18]");
#endif

    intlist_destroy(list);
}

static void test_intlist_capacity(void)
{
    IntList *list = intlist_construct(10);

    sput_fail_unless(intlist_capacity(list) == 10, 
                     "list = intlist_construct(10),\n"
                     "verifying intlist_capacity(list) => 10");

    /* Initialize list to [0, 2, 4, 6, 8] */
    for (int i = 0; i < 5; i++) {
        intlist_append(list, 2 * i);
    }

    /* Verify that appending integers doesn't change the list's capacity. */
   
    sput_fail_unless(intlist_capacity(list) == 10, 
                     "append 5 integers,\n"
                     "verifying intlist_capacity(list) => 10");

    intlist_destroy(list);
}

static void test_intlist_size(void)
{
    IntList *list = intlist_construct(10);

    sput_fail_unless(intlist_size(list) == 0, 
                     "list = intlist_construct(10),\n"
                     "verifying intlist_size(list) => 0");

    /* Initialize list to [0, 2, 4, 6, 8] */
    for (int i = 0; i < 5; i++) {
        intlist_append(list, 2 * i);
    }

    sput_fail_unless(intlist_size(list) == 5, 
                     "append 5 integers,\n "
                     "verifying intlist_size(list) => 5");
  
    intlist_destroy(list);
}

static void test_intlist_get(void)
{
    IntList *list = intlist_construct(10);

    /* Initialize list to [0, 2, 4, 6, 8] */
    for (int i = 0; i < 5; i++) {
        intlist_append(list, 2 * i);
    }

    sput_fail_unless(intlist_get(list, 0) == 0,
                     "verifying intlist_get(list, 0) => 0");

    sput_fail_unless(intlist_get(list, 1) == 2,
                     "verifying intlist_get(list, 1) => 2");

    sput_fail_unless(intlist_get(list, 2) == 4,
                     "verifying intlist_get(list, 2) => 4");

    sput_fail_unless(intlist_get(list, 3) == 6,
                     "verifying intlist_get(list, 3) => 6");

    sput_fail_unless(intlist_get(list, 4) == 8,
                     "verifying intlist_get(list, 4) => 8");

    intlist_destroy(list);
}

static void test_intlist_set(void)
{
    IntList *list = intlist_construct(10);

    /* Initialize list to [0, 2, 4, 6, 8] */
    for (int i = 0; i < 5; i++) {
        intlist_append(list, 2 * i);
    }

    sput_fail_unless(intlist_set(list, 0, 1) == 0,
                     "verifying intlist_set(list, 0, 1) => 0");
    sput_fail_unless(intlist_get(list, 0) == 1,
                     "verifying list element 0 is now 1");

    sput_fail_unless(intlist_set(list, 1, 3) == 2,
                     "verifying intlist_set(list, 1, 3) => 2");
    sput_fail_unless(intlist_get(list, 1) == 3,
                     "verifying list element 1 is now 3");

    sput_fail_unless(intlist_set(list, 2, 5) == 4,
                     "verifying intlist_set(2) => 4");
    sput_fail_unless(intlist_get(list, 2) == 5,
                     "verifying list element 2 is now 5");

    sput_fail_unless(intlist_set(list, 3, 7) == 6,
                     "verifying intlist_set(list, 3, 7) => 6");
    sput_fail_unless(intlist_get(list, 3) == 7,
                     "verifying list element 3 is now 7");

    sput_fail_unless(intlist_set(list, 4, 9) == 8,
                     "verifying intlist_set(list, 4, 9) => 8");
    sput_fail_unless(intlist_get(list, 4) == 9,
                     "verifying list element 4 is now 9");

    intlist_destroy(list);
}

static void test_intlist_removeall(void)
{
    IntList *list = intlist_construct(10);

    /* Initialize list to [0, 2, 4, 6, 8] */
    for (int i = 0; i < 5; i++) {
        intlist_append(list, 2 * i);
    }
    intlist_removeall(list);

    sput_fail_unless(intlist_size(list) == 0,
                     "intlist_removeall(list)\n"
                     "verifying list->size is now 0");

    sput_fail_unless(intlist_capacity(list) == 10,
                     "verifying list->capacity is 10");

    intlist_destroy(list);
}

/*****************************************************************
 * Tests for the functions written in Lab 8 are below this line.
 */

/* Use global variables, so we don't have to pass all of these pointers 
 * to a bunch of test functions.
 */
IntList *list1, *list2, *list3, *list4, *list5, *list6, *list7, *list8;

static void setup(void)
{
    // Empty list, [].
    list1 = intlist_construct(1);

    // [5]
    list2 = intlist_construct(1);
    intlist_append(list2, 5);

    // [7]
    list3 = intlist_construct(1);
    intlist_append(list3, 7);

    // [5, 3, 2]
    list4 = intlist_construct(3);
    intlist_append(list4, 5);
    intlist_append(list4, 3);
    intlist_append(list4, 2);

    // [3, 2, 5]
    list5 = intlist_construct(3);
    intlist_append(list5, 3);
    intlist_append(list5, 2);
    intlist_append(list5, 5);

    // [7, 5, 2]
    list6 = intlist_construct(3);
    intlist_append(list6, 7);
    intlist_append(list6, 5);
    intlist_append(list6, 2);

    // [3, 8, 6]
    list7 = intlist_construct(3);
    intlist_append(list7, 3);
    intlist_append(list7, 8);
    intlist_append(list7, 6);

    // [7, 5, 3, 6, 5, 2]
    list8 = intlist_construct(6);
    intlist_append(list8, 7);
    intlist_append(list8, 5);
    intlist_append(list8, 3);
    intlist_append(list8, 6);
    intlist_append(list8, 5);
    intlist_append(list8, 2);
}

static void teardown(void)
{
    intlist_destroy(list1);
    intlist_destroy(list2);
    intlist_destroy(list3);
    intlist_destroy(list4);
    intlist_destroy(list5);
    intlist_destroy(list6);
    intlist_destroy(list7);
    intlist_destroy(list8);
}

static void test_intlist_index(void)
{
    setup();

    sput_fail_unless(intlist_index(list1, 5) == -1,
                     "intlist_index([], 5) => -1)");

    sput_fail_unless(intlist_index(list2, 5 == 0),
                     "intlist_index([5], 5) => 0)");

    sput_fail_unless(intlist_index(list3, 5) == -1,
                     "intlist_index([7], 5) => -1)");

    sput_fail_unless(intlist_index(list4, 5) == 0,
                     "intlist_index([5, 3, 2], 5) => 0)");

    sput_fail_unless(intlist_index(list5, 5) == 2,
                     "intlist_index([3, 2, 5], 5) => 2)");

    sput_fail_unless(intlist_index(list6, 5) == 1,
                     "intlist_index([7, 5, 2], 5) => 1)");

    sput_fail_unless(intlist_index(list7, 5) == -1,
                     "intlist_index([3, 8, 6], 5) => -1)");

    sput_fail_unless(intlist_index(list8, 5) == 1,
                     "intlist_index([7, 5, 3, 6, 5, 2], 5) => 1)");

    teardown();
}

static void test_intlist_count(void)
{
    setup();

    sput_fail_unless(intlist_count(list1, 5) == 0,
                     "intlist_count([], 5) => 0)");

    sput_fail_unless(intlist_count(list2, 5) == 1,
                     "intlist_count([5], 5) => 1)");

    sput_fail_unless(intlist_count(list3, 5) == 0,
                     "intlist_count([7], 5) => 0)");

    sput_fail_unless(intlist_count(list4, 5) == 1,
                     "intlist_count([5, 3, 2], 5) => 1)");

    sput_fail_unless(intlist_count(list5, 5) == 1,
                     "intlist_count([3, 2, 5], 5) => 1)");

    sput_fail_unless(intlist_count(list6, 5) == 1,
                     "intlist_count([7, 5, 2], 5) => 1)");

    sput_fail_unless(intlist_count(list7, 5) == 0,
                     "intlist_count([3, 8, 6], 5) => 0)");

    sput_fail_unless(intlist_count(list8, 5) == 2,
                     "intlist_count([7, 5, 3, 6, 5, 2], 5) => 2)");

    teardown();
}

static void test_intlist_contains(void)
{
    setup();

    sput_fail_unless(intlist_contains(list1, 5) == false,
                     "intlist_contains([], 5) => false)");

    sput_fail_unless(intlist_contains(list2, 5),
                     "intlist_contains([5], 5) => true)");

    sput_fail_unless(intlist_contains(list3, 5) == false,
                     "intlist_contains([7], 5) => false)");

    sput_fail_unless(intlist_contains(list4, 5),
                     "intlist_contains([5, 3, 2], 5) => true)");

    sput_fail_unless(intlist_contains(list5, 5),
                     "intlist_contains([3, 2, 5], 5) => true)");

    sput_fail_unless(intlist_contains(list6, 5),
                     "intlist_contains([7, 5, 2], 5) => true)");

    sput_fail_unless(intlist_contains(list7, 5) == false,
                     "intlist_contains([3, 8, 6], 5) => false)");

    sput_fail_unless(intlist_contains(list8, 5),
                     "intlist_contains([7, 5, 3, 6, 5, 2], 5) => true)");

    teardown();
}

static void test_intlist_delete(void)
{
    setup();

    /* Delete the integer @ index 0 in this list: [5]
     * list should become []
     */
    intlist_delete(list2, 0);
    sput_fail_unless(list2->size == 0,
                     "delete element @ 0 in [5]\n"
                     "verifying list size is now 0");

    /* Delete the integer @ index 0 in this list: [5, 3, 2]
     * list should become [3, 2]
     */
    intlist_delete(list4, 0);
    sput_fail_unless(list4->size == 2,
                     "delete element @ 0 in [5, 3, 2]\n"
                     "verifying list size is now 2");
    int expected1[] = {3, 2};
    sput_fail_unless(compare_arrays(list4->elems, expected1, 2), 
                     "verifying list is now [3, 2]");

    teardown();
    setup();

    /* Delete the integer @ index 1 in this list: [5, 3, 2]
     * list should become [5, 2]
     */
    intlist_delete(list4, 1);
    sput_fail_unless(list4->size == 2,
                     "delete element @ 1 in [5, 3, 2]\n"
                     "verifying list size is now 2");
    int expected2[] = {5, 2};
    sput_fail_unless(compare_arrays(list4->elems, expected2, 2), 
                     "verifying list is now [5, 2]");

	teardown();
	setup();

    /* Delete the integer @ index 2 in this list: [5, 3, 2]
     * list should become [5, 3]
     */
    intlist_delete(list4, 2);
    sput_fail_unless(list4->size == 2,
                     "delete element @ 2 in [5, 3, 2]\n"
                     "verifying list size is now 2");
    int expected3[] = {5, 3};
    sput_fail_unless(compare_arrays(list4->elems, expected3, 2), 
                     "verifying list is now [5, 3]");

	teardown();
}

static void test_intlist_remove(void)
{
    setup();

    /* Remove 5 from this list: [5]
     * intlist_remove should return true; list should become []
     */
    sput_fail_unless(intlist_remove(list2, 5),
                     "remove 5 from [5]\n"
                     "intlist_remove([5], 5) => true");
    sput_fail_unless(list2->size == 0,
                     "verifying list size is now 0");

    /* Remove 5 from this list: [7]
     * intlist_remove should return false; list should be [7]
     */
    sput_fail_unless(intlist_remove(list3, 5) == false,
                     "remove 5 from [7]\n"
                     "intlist_remove([7], 5) => false");
    sput_fail_unless(list3->size == 1,
                     "verifying list size is 1");
    int expected1[] = {7};
    sput_fail_unless(compare_arrays(list3->elems, expected1, 1), 
                     "verifying list is [7]");

    /* Remove 5 from this list: [5, 3, 2]
     * intlist_remove should return true; list should be [3, 2]
     */
    sput_fail_unless(intlist_remove(list4, 5) == true,
                     "remove 5 from [5, 3, 2]\n"
                     "intlist_remove([5, 3, 2], 5) => true");
    sput_fail_unless(list4->size == 2,
                     "verifying list size is 2");
    int expected2[] = {3, 2};
    sput_fail_unless(compare_arrays(list4->elems, expected2, 2), 
                     "verifying list is now [3, 2]");

    /* Remove 5 from this list: [3, 2, 5]
     * intlist_remove should return true; list should be [3, 2]
     */
    sput_fail_unless(intlist_remove(list5, 5) == true,
                     "remove 5 from [3, 2, 5]\n"
                     "intlist_remove([3, 2, 5], 5) => true");
    sput_fail_unless(list5->size == 2,
                     "verifying list size is 2");
    int expected3[] = {3, 2};
    sput_fail_unless(compare_arrays(list5->elems, expected3, 2), 
                     "verifying list is now [3, 2]");

    /* Remove 5 from this list: [7, 5, 2]
     * intlist_remove should return true; list should be [7, 2]
     */
    sput_fail_unless(intlist_remove(list6, 5) == true,
                     "remove 5 from [7, 5, 2]\n"
                     "intlist_remove([7, 5, 2], 5) => true");
    sput_fail_unless(list6->size == 2,
                     "verifying list size is 2");
    int expected4[] = {7, 2};
    sput_fail_unless(compare_arrays(list6->elems, expected4, 2), 
                     "verifying list is now [7, 2]");

   /* Remove 5 from this list: [3, 8, 6]
    * intlist_remove should return false; list should be [3, 8, 6]
    */
    sput_fail_unless(intlist_remove(list7, 5) == false,
                     "remove 5 from [3, 8, 6]\n"
                     "intlist_remove([3, 8, 6], 5) => false");
    sput_fail_unless(list7->size == 3,
                     "verifying list size is 3");
    int expected5[] = {3, 8, 6};
    sput_fail_unless(compare_arrays(list7->elems, expected5, 3), 
                     "verifying list is [3, 8, 6]");

    /* Remove 5 from this list: [7, 5, 3, 6, 5, 2]
     * intlist_remove should return true; list should be [7, 3, 6, 5, 2]
     */
    sput_fail_unless(intlist_remove(list8, 5) == true,
                     "remove 5 from [7, 5, 3, 6, 5, 2]\n"
                     "intlist_remove([7, 5, 3, 6, 5, 2], 5) => true");
    sput_fail_unless(list8->size == 5,
                     "verifying list size is 5");
    int expected6[] = {7, 3, 6, 5, 2};
    sput_fail_unless(compare_arrays(list8->elems, expected6, 5), 
                     "verifying list is now [7, 3, 6, 5, 2]");
    teardown();
}

static void test_increase_capacity(void)
{
    /* Initialize a new list to [4, 7, 3, -2, 9] */
    IntList *list = intlist_construct(5);
    intlist_append(list, 4);
    intlist_append(list, 7);
    intlist_append(list, 3);
    intlist_append(list, -2);
    intlist_append(list, 9);

    int *old_array = list->elems;

    /* Increase the list's capacity from 5 to 10. */
    increase_capacity(list, 10);

    sput_fail_unless(list->capacity == 10,
                     "Verifying list capacity increased from 5 to 10");
    sput_fail_unless(list->elems != old_array,
                     "Verifying that a new array was allocated");

    int expected[] = {4, 7, 3, -2, 9};
    sput_fail_unless(compare_arrays(list->elems, expected, 5),
                     "Verifying list unchanged when capacity increased");

    intlist_destroy(list);
}

static void test_modified_intlist_append(void)
{
    _Bool appended;
    int expected[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    
    IntList *list = intlist_construct(10);
    for (int i = 0; i < 10; i += 1) {
        appended = intlist_append(list, i * 2);
    }
    sput_fail_unless(list->size == list->capacity,
                     "verifying list is full (size == capacity == 10)");
    sput_fail_unless(compare_arrays(list->elems, expected, 10), 
                     "verifying list is [0, 2, 4, 6, 8, 10, 12, 14, 16, 18]");

    /* Now append an integer to a full list.*/

    appended = intlist_append(list, 20);
    sput_fail_unless(appended == true, 
                     "append 20 to full list,\n"
                     "verifying return value is true");
    sput_fail_unless(list->size == 11,
                     "verifying list size is 11");
    sput_fail_unless(list->capacity == 20,
                     "verifying list capacity is 20");
    sput_fail_unless(compare_arrays(list->elems, expected, 11), 
                     "verifying list is "
                      "[0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20]");

    intlist_destroy(list);
}


int main(void)
{
    sput_start_testing();

    sput_enter_suite("Lab 7, Exercise 1: intlist_construct()");
    sput_run_test(test_intlist_construct);

    test_intlist_print();

    sput_enter_suite("Lab 7, Exercise 3: intlist_append()");
    sput_run_test(test_intlist_append);

    sput_enter_suite("Lab 7, Exercise 4: intlist_capacity()");
    sput_run_test(test_intlist_capacity);

    sput_enter_suite("Lab 7, Exercise 5: intlist_size()");
    sput_run_test(test_intlist_size);

    sput_enter_suite("Lab 7, Exercise 6: intlist_get()");
    sput_run_test(test_intlist_get);

    sput_enter_suite("Lab 7, Exercise 7: intlist_set()");
    sput_run_test(test_intlist_set);

    sput_enter_suite("Lab 7, Exercise 8: intlist_removeall()");
    sput_run_test(test_intlist_removeall);

    sput_enter_suite("Lab 8, Exercise 1: intlist_index()");
    sput_run_test(test_intlist_index);

    sput_enter_suite("Lab 8, Exercise 2: intlist_count()");
    sput_run_test(test_intlist_count);

    sput_enter_suite("Lab 8, Exercise 3: intlist_contains()");
    sput_run_test(test_intlist_contains);

    sput_enter_suite("Lab 8, Exercise 4: intlist_delete()");
    sput_run_test(test_intlist_delete);

    sput_enter_suite("Lab 8, Exercise 5: intlist_remove()");
    sput_run_test(test_intlist_remove);

    sput_enter_suite("Lab 8, Exercise 6: increase_capacity()");
    sput_run_test(test_increase_capacity);

    sput_enter_suite("Lab 8, Exercise 7: modified intlist_append()");
    sput_run_test(test_modified_intlist_append);

    sput_finish_testing();
    return sput_get_return_value();
}
