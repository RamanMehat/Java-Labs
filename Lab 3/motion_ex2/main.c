#include <stdio.h>
#include "motion.h"

int main(void)
{
	double initial_velocity = 10.0;  // m/s
	double time = 100.0;  // s
	double acceleration = 3.5;  // m/s^2

	printf("Calculating final velocity of an object with:\n");
	printf("\tinitial velocity = %.2f m/s\n", initial_velocity);
	printf("\tconstant acceleration = %.2f m/s^2\n", acceleration);
	printf("\telapsed time = %.2f s\n\n", time);
	printf("\tExpected result = 360.0 m/s\n");
	printf("\tActual result = %.2f m/s\n", 
		   calculate_velocity(initial_velocity, acceleration, time));
}


