#line 1 "F:\Sysc Labs\2006-C\Lab 3\motion_ex1\motion.c"


#line 1 "F:\Sysc Labs\2006-C\Lab 3\motion_ex1\motion.h"


double calculate_velocity(double initial_v, double accel, double time);
#line 4 "F:\Sysc Labs\2006-C\Lab 3\motion_ex1\motion.c"


#line 9 "F:\Sysc Labs\2006-C\Lab 3\motion_ex1\motion.c"
double calculate_velocity(double initial_v, double accel, double time)
{
	return initial_v + accel * time;
}
