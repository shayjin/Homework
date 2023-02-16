/*****************************************/
/* Name: Jay Shin    Date: 10/30/2020    */
/* Seat: 00          File: EWA_06.cpp    */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592653589793238
int main(){
printf("*****************************************\n");
printf("* Name: Jay Shin    Date: 10/30/2020    *\n");
printf("* Seat: 00          File: EWA_06.cpp    *\n");
printf("* Instructor: Brooke Morin 12:40-2:45   *\n");
printf("*****************************************\n");
FILE *info;
FILE *output;
int size = 15;
float d, r[size], sa[size], v[size];
float totalR = 0, totalV = 0, totalSA = 0;
int index = 0;
//Read in each diameter. 
info = fopen("EWA_06_gumdrops.dat", "r");
//Compute the volume and surface area of a sphere with that diameter. 
while(feof(info) == 0){
	fscanf(info, "%f", &d);
	if(feof(info) == 0){
		r[index] = d/2.0; 
		sa[index] = 4.0*PI*pow(r[index], 2);
		v[index] = 4.0/3.0*PI*pow(r[index],3);
		
		//Displays on the screen the:
		printf("Sphere %i:\n", index+1);
		//radius
		printf("radius is %.3f cm\n", r[index]);
		//sphere volume for that radius
		printf("volume is %.3f cm^3\n", v[index]);
		//sphere surface area for that radius
		printf("surface area is %.3f cm^2\n", sa[index]);
		
		totalR += r[index];
		totalV += v[index];
		totalSA += sa[index];

		index++;
	}
}
//average radius, average volume, and average surface area 
printf("average radius is: %.3f cm\n", totalR/(size));
printf("average volume is: %.3f cm^3\n", totalV/(size));
printf("average surface area is: %.3f cm^2\n", totalSA/(size));
//the number spheres with radius less than or equal to the average radius
//the number spheres with radius greater than the average radius
int smallR = 0;
int bigR = 0;
for(int i = 0; i < size; i++){
	if(r[i] <= totalR/size){
		smallR++;
	}
	if(r[i] > totalR/size){
		bigR++;
	}
}
printf("number of spheres with radius less than or equal to average radius: %i\n", smallR);
printf("number of spheres with radius greater than the average radius: %i\n", bigR);
//Use a field width of 10 with 3 decimal places for floating point output (i.e., radius, volume, and surface area).  
//Display a descriptive heading (e.g., name and units) at the top of each column on the screen
//Indicates the program has completed.
printf("program completed\n");
//Write the same information to the output file, EWA_06.txt.
output = fopen("EWA_06.txt", "w");
for(int i = 0; i < size; i++){
	fprintf(output, "Sphere %i:\n", i+1);
	fprintf(output, "radius is %.3f cm\n", r[i]);
	fprintf(output, "volume is %.3f cm^3\n", v[i]);
	fprintf(output, "surface area is %.3f cm^2\n", sa[i]);
}
fprintf(output, "average radius is: %.3f cm\n", totalR/(size));
fprintf(output, "average volume is: %.3f cm^3\n", totalV/(size));
fprintf(output, "average surface area is: %.3f cm^2\n", totalSA/(size));
fprintf(output, "number of spheres with radius less than or equal to average radius: %i\n", smallR);
fprintf(output, "number of spheres with radius greater than the average radius: %i\n", bigR);
//Closes all open files
fclose(info);
fclose(output);
}

