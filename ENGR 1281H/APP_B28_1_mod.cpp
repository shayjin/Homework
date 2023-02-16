/*****************************************/
/* Name: Jay Shin    Date: 10/29/2020    */
/* Seat: 00      File: APP_B28_1_mod.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
printf("*****************************************\n");
printf("* Name: Jay Shin    Date: 10/29/2020    *\n");
printf("* Seat: 00      File: APP_B28_1_mod.cpp *\n");
printf("* Instructor: Brooke Morin 12:40-2:45   *\n");
printf("*****************************************\n");
//Once the code is working, save the code as APP_B28_1_mod.cpp and modify the program to perform the following tasks: 
float a, b, c, avg;
float *ptr1, *ptr2, *ptr3, *ptr4; 
ptr1 = &a; 
ptr2 = &b; 
ptr3 = &c; 
ptr4 = &avg;
//Prompt the user a second time for three numbers.  
printf("Input number a: ");
scanf("%f", &a);
printf("Input bumber b: ");
scanf("%f", &b);
printf("Input number c: ");
scanf("%f", &c);
//Compute the average of the numbers, the absolute values, and the average of the absolute values, and print to the screen.
//However, in the modified portion of the code, you may not use any pointer variables.You must use only the variables a, b, c, and avgthat were previously declared.
avg = (a+b+c)/3;
printf("Average is: %f\n", avg);
printf("Absolute value of a: %f\n", fabs(a));
printf("Absolute value of b: %f\n", fabs(b));
printf("Absolute value of c: %f\n", fabs(c));
//Print the value and address of a (not using pointer variables!).  (B)
printf("Value of a: %f\n", a);
printf("Address of a: %li\n", &a);
//Compile, link, and run your program.
}


