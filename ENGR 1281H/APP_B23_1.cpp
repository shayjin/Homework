//Start: Inlcude the standard comment and printf() statements indicating name, seat number, etc. 
/*****************************************/
/* Name: Jay Shin    Date: 10/19/2020    */
/* Seat: 00          File: APP_B23_1.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <math.h>

int main(){
printf("*****************************************\n");
printf("* Name: Jay Shin    Date: 10/19/2020    *\n");
printf("* Seat: 00          File: APP_B23_1.cpp *\n");
printf("* Instructor: Brooke Morin 12:40-2:45   *\n");
printf("*****************************************\n");
//Define b = 6.0
float b = 6.0;
//Define h = 3.0
float h = 3.0;
//Compute I using the area moment of inertia equation
float I = b*pow(h,3)/12;
//Display results to screen
printf("A rectangle with b = %6.2f in and h = %6.2f in \n", b, h);
printf("has an area moment of inertia of I = %6.2f in^4\n", I);
//Define b = 3.0
b = 3.0;
//Define h = 6.0
h = 6.0;
//Compute I using the area moment of inertia equation
I = b*pow(h,3)/12;
//Display results to screen
printf("A rectangle with b = %6.2f in and h = %6.2f in \n", b, h);
printf("has an area moment of inertia of I = %6.2f in^4\n", I);
//Define h = 2.0
h = 2.0;
//Define b = 2h
b = 2*h;
//Compute I using the area moment of inertia equation
I = b*pow(h,3)/12;
//Display results to screen
printf("A rectangle with b = %6.2f in and h = %6.2f in \n", b, h);
printf("has an area moment of inertia of I = %6.2f in^4\n", I);
//Define h = 3.0
h = 3.0;
//Define b = 2h
b = 2*h;
//Compute I using the area moment of inertia equation
I = b*pow(h,3)/12;
//Display results to screen
printf("A rectangle with b = %6.2f in and h = %6.2f in \n", b, h);
printf("has an area moment of inertia of I = %6.2f in^4\n", I);
//End: Check that the results displayed from 5) and 17) in the algorithm are the same
}
