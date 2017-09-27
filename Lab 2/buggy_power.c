/* SYSC 2006 Winter 2014 Lab 2, Part 1 */

#include <stdio.h>
#include <stdlib.h>

int power(int m, int n);

int main(void)
{
    int x, result;

    x = 2;
    result = power(x, 5);
    printf("%d raised to the power 5 = %d\n", x, result);
    exit(0);
}

/* Return base raised to the n'th power; n >= 0. */
int power(int base, int n)
{
    int p = 1;
    while (n >= 1) {
        p = p * base;
        n = n - 1;
    }
    return p;
}
