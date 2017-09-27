/* fraction.h - SYSC 2006 Winter 2014 Lab 6 */

struct fraction {
	int num;  // numerator
	int den;  // denominator
};

typedef struct fraction fraction_t;

/* Could instead declare the structure this way:

typedef {
    int num;
    int den;
} fraction_t;
*/

fraction_t *make_fraction(int a, int b);
void print_fraction(fraction_t *pf);
fraction_t *add_fractions(fraction_t *pf1, fraction_t *pf2);
fraction_t *multiply_fractions(fraction_t *pf1, fraction_t *pf2);

/* Helper functions. */
int gcd(int a, int b);
void reduce(fraction_t *pf);
