/*****************************************/
/* Name: Jay Shin   Date: 10/20/2020     */
/* Seat: 00        File: APP_B24_1.cpp   */
/* Instructor: Brooke Morin  12:40-2:45  */
/*****************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
printf("*****************************************\n");
printf("* Name: Jay Shin    Date: 10/20/2020    *\n");
printf("* Seat: 00          File: APP_B24_1.cpp *\n");
printf("* Instructor: Brooke Morin 12:40-2:45   *\n");
printf("*****************************************\n");
FILE *file;
float fo;
//Prompt the user for a volume in fluid ounces. 
printf("Enter a volume in fluid ounces: ");
//Read the user’s response. 
scanf("%f", &fo);
//Compute the equivalent volume in: cups [c], gallons [Ga], quarts [Q], Pints [P], tablespoons[Tbsp], and teaspoons [tsp].
float cups = fo / 8;
float gallons = fo / 128;
float quartz = fo / 32;
float pints = fo / 16;
float tablespoons = fo * 2;
float teaspoons = fo * 6;
//Display to the screen the volume in fluid ounces as the input and the six corresponding values as the output. Include proper units on all. 
printf("%f fluid ounces equals %f cups\n", fo, cups);
printf("%f fluid ounces equals %f gallons\n", fo, gallons);
printf("%f fluid ounces equals %f quartz\n", fo, quartz);
printf("%f fluid ounces equals %f pints\n", fo, pints);
printf("%f fluid ounces equals %f tablespoons\n", fo, tablespoons);
printf("%f fluid ounces equals %f teaspoons\n", fo, teaspoons);
//Write the same information to the file APP_B24_1_result.txt
file = fopen("APP_B24_1_result.txt", "w");
fprintf(file, "%f fluid ounces equals %f cups\n%f fluid ounces equals %f gallons\n%f fluid ounces equals %f quartz\n%f fluid ounces equals %f pints\n%f fluid ounces equals %f tablespoons\n%f fluid ounces equals %f teaspoons\n", fo, cups, fo, gallons, fo, quartz, fo, pints, fo, tablespoons, fo, teaspoons);
}
