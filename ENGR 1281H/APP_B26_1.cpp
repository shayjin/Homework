/*****************************************/
/* Name: Jay Shin    Date: 10/26/2020    */
/* Seat: 00          File: APP_B26_1.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
printf("*****************************************\n");
printf("* Name: Jay Shin    Date: 10/26/2020    *\n");
printf("* Seat: 00          File: APP_B26_1.cpp *\n");
printf("* Instructor: Brooke Morin 12:40-2:45   *\n");
printf("*****************************************\n");
//Write a complete C program APP_B26_1.cpptoperform the following tasks:
FILE *file;
float swim[6];
float bike[6];
float run[6];
float tas[6];
int year[6] = {2007, 2008, 2009, 2010, 2011, 2012};
//Use a forloop to prompt the user to input the data from the Ironman World Championshipfor years 2007to 2012 (given in the table above).
for(int i = 0; i < 6; i++){
printf("Input swim speed for year %i: ", year[i]);
scanf("%f", &swim[i]);
printf("Input bike speed for year %i: ", year[i]);
scanf("%f", &bike[i]);
printf("Input run speed for year %i: ", year[i]);
scanf("%f", &run[i]);
printf("Input average speed for year %i: ", year[i]);
scanf("%f", &tas[i]);
}
//As the data is entered on the command line, store itin four arrays, one for the swim,one for bike, one for the run, and one for the total average speed.
//Compute the average speed in each category and print it to the screen.
float swimT = 0;
float bikeT = 0;
float runT = 0;
float avgT = 0;
for(int i = 0; i < 6; i++){
swimT += swim[i];
bikeT += bike[i];
runT += run[i];
avgT += tas[i];
}
printf("Average swim speed is %0.2f\n", swimT/6);
printf("Average bike speed is %0.2f\n", bikeT/6);
printf("Average run speed is %0.2f\n", runT/6);
printf("Average average speed is %0.2f\n", avgT/6);
//Find the fastest year in each category, as well as the year with the fastest overall race. 
float swimF = swim[0];
float bikeF = bike[0];
float runF = run[0];
float oF = tas[0];

int sfIndex = 0;
int bfIndex = 0;
int rfIndex = 0;
int ofIndex = 0;

for(int i = 0; i < 6; i++){
if(swimF < swim[i]){
swimF = swim[i];
sfIndex = i;
}
if(bikeF < bike[i]){
bikeF = bike[i];
bfIndex = i;
}
if(runF < run[i]){
runF = run[i];
rfIndex = i;
}
if(oF < tas[i]){
oF = tas[i];
ofIndex = i;
}
}
//Print each fastest speed and corresponding year to the screen. 
printf("fastest swim speed was %0.2f from year %i\n", swimF, year[sfIndex]);
printf("fastest bike speed was %0.2f from year %i\n", bikeF, year[bfIndex]);
printf("fastest run speed was %0.2f from year %i\n", runF, year[rfIndex]);
printf("fastest average speed was %0.2f from year %i\n", oF, year[ofIndex]);
//Compile, link, and run your program.
//Once working modify the program to perform the following tasks:
//Create and open an output file named APP_B26_1_result.txt., verifying the file opened successfully.
file = fopen("APP_B26_1_result.txt", "w");
//Write the same values to this output file that are also printed to the screen.
fprintf(file, "Average swim speed is %0.2f\n", swimT/6);
fprintf(file, "Average bike speed is %0.2f\n", bikeT/6);
fprintf(file, "Average run speed is %0.2f\n", runT/6);
fprintf(file,"Average average speed is %0.2f\n", avgT/6);
fprintf(file, "fastest swim speed was %0.2f from year %i\n", swimF, year[sfIndex]);
fprintf(file, "fastest bike speed was %0.2f from year %i\n", bikeF, year[bfIndex]);
fprintf(file, "fastest run speed was %0.2f from year %i\n", runF, year[rfIndex]);
fprintf(file, "fastest average speed was %0.2f from year %i\n", oF, year[ofIndex]);
//Close APP_B26_1_result.txt.
fclose(file);
}
