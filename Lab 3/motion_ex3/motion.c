/* Functions that model the motion of an object. */

#include "motion.h"

/* Returns the velocity (m/s) of an object with initial velocity
   initial_v (m/s), undergoing constant acceleration accel (m/s^2), 
   after after time seconds.
*/
double calculate_velocity(double initial_v, double accel, double time)
{
	return initial_v + accel * time;
}

/* Returns the displacment (m/s) of an object with initial velocity
   initial_v (m/s), undergoing constant acceleration contant_accel (m/s^2), 
   after time seconds.
*/
//s = ut + 1/2at^2

double calculate_displacement(double initial_v, double accel, double time)
{
	return (initial_v * time) + ((0.5)*accel*(time*time));
} 
