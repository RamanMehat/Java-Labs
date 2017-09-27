/* SYSC 2006 Winter 2014 Lab 11. */

#include <stdio.h>
#include <math.h>

//Exercise 1
/* Return x raised to the power n for n >= 0. */
double power(double x, int n)
{
	if (n == 0) {
        return 1;
    }
    return (x * power(x, n-1)); 	  
}

//Exercise 2
/* Return x raised to the power n for n >= 0. */
double power2(double x, int n)
{
	if (n == 0){
		return 1;
	}   
	if (n % 2 == 0){
		return (power2(x,n/2))*(power2(x,n/2));
	}
	else {
		return x*(power2(x,n/2))*(power2(x,n/2));
	}
}

//Exercise 4
/* Return the number of digits in integer n, n >= 0. */
int num_digits(int n)
{
    if (n < 10){
		return 1;
	}
	return (1 + num_digits(n/10));
}

//Exercise 5
/* Return the count of the number of times target occurs in the first 
 * n elements of array a.
 */   
int occurrences(int a[], int n, int target)
{
 	int count = 0;	
	if (n == 0){
		return count;
	}
	if (a[0] == target){
		return 1;
	}
	if (a[n] == target){
		count++;
	}
	count = count + occurrences(a, n-1, target);
	return count;
}
