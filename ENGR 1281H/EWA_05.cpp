/*****************************************/
/* Name: Jay Shin    Date: 10/25/2020    */
/* Seat: 00          File: EWA_05.cpp    */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PS_PER_LY 0.30659458
#define CMPD_PER_GPH 0.090849883
#define TEV_PER_CAL 26125697.8238
int main(){
printf("*****************************************\n");
printf("* Name: Jay Shin    Date: 10/25/2020    *\n");
printf("* Seat: 00          File: EWA_05.cpp *  *\n");
printf("* Instructor: Brooke Morin 12:40-2:45   *\n");
printf("*****************************************\n");
float strm, ly, cal, gph;
float og, ps, tev, cmpd;
FILE * file;
//Prompt the user for the following quantities:
//An area in stremmas
printf("Enter area in stremmas: ");
scanf("%f", &strm);
//A distance in light years
printf("enter distance in light years: ");
scanf("%f", &ly);
//An amount of energy in calories
printf("Enter amount of energy in calories: ");
scanf("%f", &cal);
//A flowrate in gallons/hour
printf("Enter a glowrate in gallons/hour: ");
scanf("%f", &gph);
//Convert the: Stremmas to oxgangs
og = strm / 60;
//Light years to parsecs
ps = ly * PS_PER_LY;
//Calories to teraelectronvolts
tev = cal * TEV_PER_CAL;
//Gallons/hour to cubic meters/day
cmpd = gph * CMPD_PER_GPH;
//Display the results of the conversions in the Linux window.
printf("%f stremmas: %f oxgangs\n", strm, og);
printf("%f light years: %f parsecs\n", ly, ps);
printf("%f Calories: %e Teralectronvolts\n", cal, tev);
printf("%f gallons/hour: %f cubic meters/day\n", gph, cmpd);
//Write to the screen that the program has completed.
printf("The program has completed.");
//Write the same information to the file EWA_05.txt. 
file = fopen("EWA_05.txt", "w");
fprintf(file, "%f stremmas: %f oxgangs\n", strm, og);
fprintf(file, "%f light years: %f parsecs\n", ly, ps);
fprintf(file, "%f Calories: %e Teralectronvolts\n", cal, tev);
fprintf(file,"%f gallons/hour: %f cubic meters/day\n", gph, cmpd);
}
