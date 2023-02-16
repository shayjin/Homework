/*****************************************/
/* Name: Jay Shin    Date: 10/29/2020    */
/* Seat: 00          File: APP_B28_1.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
printf("*****************************************\n");
printf("* Name: Jay Shin    Date: 10/29/2020    *\n");
printf("* Seat: 00          File: APP_B28_1.cpp *\n");
printf("* Instructor: Brooke Morin 12:40-2:45   *\n");
printf("*****************************************\n");
//Write a complete C/C++ program APP_B28_1.cpp to perform the following tasks:
printf("For APP_B28_1.cpp:\n");
float a, b, c, avg;
float *ptr1, *ptr2, *ptr3, *ptr4; 
ptr1 = &a; 
ptr2 = &b; 
ptr3 = &c; 
ptr4 = &avg;
//Prompt the user to input three numbers, either positive or negative.
printf("Input number a: ");
scanf("%f", ptr1);
printf("Input bumber b: ");
scanf("%f", ptr2);
printf("Input number c: ");
scanf("%f", ptr3);
//Print their average to the screen.
*ptr4 = (*ptr1 + *ptr2 + *ptr3)/3;
printf("Average is: %f\n", *ptr4);
//Compute the absolute value of each number.  
//Print the absolute values to the screen. The function fabs()computes the absolute value for floating point numbers and is included in math.h.
printf("Absolute value of a: %f\n", fabs(*ptr1)); 
printf("Absolute value of b: %f\n", fabs(*ptr2)); 
printf("Absolute value of c: %f\n", fabs(*ptr3)); 
//Print the average of the absolute values to the screen.
printf("Average of the absolute values is: %f\n", (fabs(*ptr1)+fabs(*ptr2)+fabs(*ptr3))/3);
//Print the value and address of a (using only pointer variables!).  (A)
printf("Value of a: %f\n", *ptr1);
printf("Address of a: %li\n", ptr1);
//Compile, link, and run your program.
//Once the code is working, save the code as APP_B28_1_mod.cpp and modify the program to perform the following tasks: 
printf("\nFor APP_B28_1_mod.cpp:\n");
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
printf("Average of the absolute values is: %f\n", (fabs(a)+fabs(b)+fabs(c))/3);
//Print the value and address of a (not using pointer variables!).  (B)
printf("Value of a: %f\n", a);
printf("Address of a: %li\n", &a);
//Compile, link, and run your program.
}

