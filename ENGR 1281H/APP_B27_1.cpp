/*****************************************/
/* Name: Jay Shin    Date: 10/27/2020    */
/* Seat: 00          File: APP_B27_1.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
printf("*****************************************\n");
printf("* Name: Jay Shin    Date: 10/27/2020    *\n");
printf("* Seat: 00          File: APP_B27_1.cpp *\n");
printf("* Instructor: Brooke Morin 12:40-2:45   *\n");
printf("*****************************************\n");
FILE *file;
int num = 5;
float base, height;
float baseArr[num];
float heightArr[num];
float areaArr[num];
//Write a complete C/C++ programAPP_B27_1.cpp to perform the following tasks:
//Open an existing data file, APP_B27_1_triangle.dat, verifying the file opened successfully.
file = fopen("APP_B27_1_triangle.dat", "r");
//Read each line in the file.  You must use a while loop and check for the end of file while reading in the data. The file has two columns, the first column is the triangle’s base (mm) and the second column is the triangle’s height (mm). 
int index = 0;
while(feof(file) == 0){
fscanf(file, "%f%f", &base, &height);
if(feof(file) == 0){
//Write each line from the input file to the screen along with the calculated area for a triangle with the given base and height.
printf("base: %.3fmm height: %.3fmm area: %.3fmm^2\n", base, height, base*height/2);
baseArr[index] = base;
heightArr[index] = height;
areaArr[index] = base*height/2;
index++;
}
}
//Determine the average of the bases, average of the heights, and average of the areas.
float baseTotal = 0;
float heightTotal = 0;
float areaTotal = 0;
for(int i = 0; i < num; i++){
baseTotal += baseArr[i];
heightTotal += heightArr[i];
areaTotal += areaArr[i];
}
float baseAvg = baseTotal / num;
float heightAvg = heightTotal / num;
float areaAvg = areaTotal / num;
//Write the resulting averages, properly labeled, to the screen.
printf("Average base: %.3fmm\n", baseAvg);
printf("Average height: %.3fmm\n", heightAvg);
printf("Average area: %.3fmm\n", areaAvg);
//Write the number of triangles, properly labeled, to the screen.
printf("There are %i triangles\n", num); 
//Compile, link, and run your program.
//Once working, modify the program to perform the following tasks:
//Create and open an output file named APP_B27_1_result.txt, verifying the file opened successfully.
file = fopen("APP_B27_1_result.txt", "w");
//Write the same values to this output file that are printed to the screen. 
for(int i = 0; i <= num; i++){
fprintf(file, "base: %.3fmm height: %.3fmm area: %.3fmm^2\n", baseArr[i], heightArr[i], areaArr[i]);
}
fprintf(file, "Average base: %.3fmm\n", baseAvg);
fprintf(file, "Average height: %.3fmm\n", heightAvg);
fprintf(file, "Average area: %.3fmm\n", areaAvg);
fprintf(file, "There are %i triangles\n", num); 
//Close APP_B27_1_result.txt
fclose(file);
//Compile, link, and run your program.
}

