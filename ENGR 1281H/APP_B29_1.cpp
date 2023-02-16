/*****************************************/
/* Name: Jay Shin    Date: 11/03/2020    */
/* Seat: 00          File: APP_B29_1.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Vi 5
#define A 500
#define Sg 2.085
int main(){
printf("*****************************************\n");
printf("* Name: Jay Shin    Date: 11/03/2020    *\n");
printf("* Seat: 00          File: APP_B29_1.cpp *\n");
printf("* Instructor: Brooke Morin 12:40-2:45   *\n");
printf("*****************************************\n");
//Write a complete C/C++ program APP_B29_1.cpp to perform the following tasks: 
FILE *input, *output;
int arrayIndex = 0, maxIndex, minIndex;
float data[12000], d, max = 0, min = 100;
float et, e;
//Open and read the data file and then close it when finished.
input = fopen("APP_B29_1_bike.dat", "r");
//Read the four columns in, but discard the data values from the first three columns and store only the data from the fourth column in a one-dimensional array. 
//Your program will need to detect the end-of-file (EOF) to know when to stop reading data.  
while(feof(input) == 0){
//For skipping over the columns with unwanted data, you will need to use the assignment suppression operator, *, in the fscanf format.  
	fscanf(input, "%*s%*s%*f%f", &d);
	if(feof(input) == 0){
		data[arrayIndex] = d;
		arrayIndex++;
	}
}
//Close the input file when you reach the EOF.
fclose(input); 
//Process the data to determine the:
for(int i = 0; i < arrayIndex; i++){
	//maximum value in the array
	if(data[i] > max){
		max = data[i];
		maxIndex = i;
	}
	//minimum value in the array
	if(data[i] < min){
		min = data[i];
		minIndex = i;
	}
}
//elapsed time in seconds between the maximum and minimum values.
et = 0.005*fabs(maxIndex-minIndex);
//strain, ε, for the maximum and minimum voltage values.
e = (max-min)/(Vi*A*Sg);
//Display the results, well labeled, on the screen and write them to the output file APP_B29_1_result.txt. 
printf("Maximum voltage: %.3f V\n", max);
printf("Minimum voltage: %.3f V\n", min);
printf("Elasped time between maximum and minimum values: %.3f seconds\n", et);
printf("Strain, e: %f \n", e);
output = fopen("APP_B29_1_result.txt", "w");
fprintf(output, "Maximum voltage: %.3f V\n", max);
fprintf(output, "Minimum voltage: %.3f V\n", min);
fprintf(output, "Elasped time between maximum and minimum values: %.3f seconds\n", et);
fprintf(output, "Strain, e: %f \n", e);
fclose(output);
//Compile, link, and run your program.
}

