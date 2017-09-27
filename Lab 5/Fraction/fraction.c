/* fraction.c - SYSC 2006 Winter 2014 Lab 5 */

#include <stdlib.h>  // abs(x)
#include <stdio.h>   // printf

#include "fraction.h"

/* Print fraction f in the form a/b. */
//Exercise #1
void print_fraction(fraction_t f)
{
	int a = f.num;
	int b = f.den;
	printf("%d/%d\n",a,b);
	printf("This function should print fraction f in the form a/b.");
}

/* Return the greatest common divisor of integers a and b; 
   i.e., return the largest positive integer that evenly divides 
   both values.
*/

int gcd(int a, int b)
/* Euclid's algorithm, using iteration and calculation of remainders. */
{
	int q = abs(a);
	int p = abs(b);
	int r = (q%p);

	while (r != 0){
		q = p;
		p = r;
		r = (q%r);
	}

	return p;
}

/* Return the reduced form of fraction f.

   This means that:
   (1) if the numerator is equal to 0 the denominator is always 1.
   (2) if the numerator is not equal to 0 the denominator is always
       positive, and the numerator and denominator have no common
       divisors other than 1.

   In other words,
   (1) if the numerator is 0 the denominator is always changed to 1.
   (2) if the numerator and denominator are both negative, both values
       are made positive, or if the numerator is positive and the 
       denominator is negative, the numerator is made negative and the 
       denominator is made positive.
   (3) the numerator and denominator are both divided by their greatest
       common divisor. 
*/
fraction_t reduce(fraction_t f)
{ 
	if (f.den == 0){
		exit(1);
			}
	if (f.num == 0) {
		f.den = 1;  
	}

	else {

		if (f.den < 0){
			f.num = f.num * - 1; //changing to positive
			f.den = f.den * - 1;
		}
		
		int a = gcd(f.num,f.den);
		f.num = (f.num/a);
		f.den = (f.den/a);
	}

    return f;
}

/* Return a fraction with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
*/
fraction_t make_fraction(int a, int b)
{
 fraction_t f;   
	
	f.num = a;
  	f.den = b;

	f = reduce(f);
	
	return f;
}

/* Return the sum of fractions f1 and f2.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
 */
fraction_t add_fractions(fraction_t f1, fraction_t f2)
{
	int a = (f1.num*f1.den) + (f2.num*f2.den);
	int b = (f2.num*f2.den);

	return make_fraction(a,b);
}

/* Return the product of fractions f1 and f2.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
 */
fraction_t multiply_fractions(fraction_t f1, fraction_t f2)
{
	int a = (f1.num*f2.num);
	int b = (f2.den*f1.den);
 
	return make_fraction(a, b);
}
