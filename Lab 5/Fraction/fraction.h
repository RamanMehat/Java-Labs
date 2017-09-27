/* fraction.h - SYSC 2006 Fall 2013 Lab 8 */

struct fraction {
	int num;  // numerator
	int den;  // denominator
};

typedef struct fraction fraction_t;

/* We could combine the structure declaration and the typedef into
 * a single declaration:

typedef {
    int num;
    int den;
} fraction_t;
*/

fraction_t make_fraction(int a, int b);
void print_fraction(fraction_t f);
fraction_t add_fractions(fraction_t f1, fraction_t f2);
fraction_t multiply_fractions(fraction_t f1, fraction_t f2);

/* Helper functions. */
int gcd(int a, int b);
fraction_t reduce(fraction_t f);
