
/*  Name:  Jay Shin		 						  */
/*  Date:  MM/DD/YYYY 										  */
/*  Assignment:  APP B22-1									  */
/*  Seat:  XX		Instructor:  XYZ		Time:  HH:MM  */

#include <stdio.h>
#include  <stdlib.h>
#include  <math.h>
#define PI 3.14159265359

int main ( )
{
	/* Declare variables */
	float rad_c, rad_r, tor_sa, tor_vol;

	/* Tell the user what the program does.  Prompt/read the required dimensions*/

  	printf ("\nThis program computes the volume and surface area of a torus.\n");
  	printf ("A torus is a surface of revolution created by revolving a circle\n");
  	printf ("about an axis coplanar with and not touching the circle.\n");
  	printf ("You know...a doughnut.  http://en.wikipedia.org/wiki/Torus\n\n");

	printf ("Enter the radius of the circle being revolved (r) and\n");
	printf ("the radius from the axis of revolution to the center of the\n");
	printf ("circle (R) separated by a space.\n\n");
	printf ("r and R in inches > ");
	
	/* Read two floating point values from the keyboard and store the values in
	   rad_c and rad_r.  scanf() will wait until <ENTER> has been pressed. */

	scanf ("%f%f", &rad_c, &rad_r);

	/* Display the values for  pi, r, and R */
  	printf ("pi = %f  r = %f R = %f\n\n ", PI, rad_c, rad_r);

	/* Calculate the volume and surface area.  Store the results in the variables
	   tor_vol and tor_sa. If you want, you could use pow(PI, 2.0)
	   and pow(rad_c, 2.0) for PI*PI and rad_c*rad_c, respectively.  Try it! */

	tor_vol = 2.0 * PI * PI * rad_r * rad_c * rad_c;
	tor_sa = 4.0 * PI * PI * rad_r * rad_c;

	/* Display the torus radii in inches, the surface area in square inches
	   and the volume in cubic inches. */

  	printf ("A torus with r = %6.2f inches and R = %6.2f inches\n", rad_c, rad_r);
	printf ("has a surface area of %10.2f square inches\n", tor_sa);
	printf( "and a volume of %10.2f cubic inches. \n\n", tor_vol);
}

