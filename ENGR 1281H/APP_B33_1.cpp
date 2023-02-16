/*****************************************/
/* Name: Jay Shin    Date: 11/13/2020    */
/* Seat: 29          File: APP_B33_1.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/

/*
  1281H APP B33-1
Program to practice use of structs by creating a Calendar struct that contains date and time.  User is asked to input birth date and time and current date and time.  Calendar date and time are  converted to seconds from a "zero" time, then the time difference is computed in seconds and that time difference converted back to elapsed time in years, months, etc. and stored in a third Calendar struct.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
   Definitions of conversion constants and reference date.
*/

#define YEAR_TO_SECONDS 31557600
#define MONTH_TO_SECONDS 2628000
#define DAY_TO_SECONDS 86400
#define HOUR_TO_SECONDS 3600
#define MINUTE_TO_SECONDS 60
#define YEAR_ZERO 1980

/* 
   Each struct Calendar variable will be defined by this struct.
*/

struct Calendar
{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;

};

/* 
   Function prototypes for each user-written function.
*/
void GetTime(struct Calendar *, FILE *);
long int SecondsFromZero(struct Calendar);
void ConvertToCalendar(long int , struct Calendar *);

int main()
{
//Open an output file, APP_B33_1_result.txt, and write everything to the file that is being written to the screen.
  FILE *fout;
  fout = fopen("APP_B33_1_result.txt", "w");

	printf ("********************************************\n");
	printf ("* Name: Jay Shin          Date: 11/13/2020 *\n");
	printf ("* Seat: 29     File: APP_B33_1.cpp         *\n");
	printf ("* Instructor: Brooke Morin  12:40-2:45     *\n");
	printf ("********************************************\n");

	fprintf (fout, "********************************************\n");
	fprintf (fout, "* Name: Jay Shin          Date: 11/13/2020 *\n");
	fprintf (fout, "* Seat: 29     File: APP_B33_1.cpp         *\n");
	fprintf (fout, "* Instructor: Brooke Morin  12:40-2:45     *\n");
	fprintf (fout, "********************************************\n");

/* 
   Declare three instances of "struct Calendar".

   Declare three long integer variables to hold the seconds from zero until birth, the seconds from zero until now, and the difference in seconds between the two.

   zBirth and zNow will be for user input, while zAge will be the output of ConvertToCalendar (). 
*/ 

  struct Calendar zBirth, zNow, zAge;
  long int secondsNow, secondsBirth, secondsDifference;

/* 
   Fill zBirth and zNow with input from the user
*/

//Prompt the user for the time of birth and the current time.
  printf("\n\nTime of Birth:\n");
  fprintf(fout, "\n\nTime of Birth:\n");
  GetTime(&zBirth, fout);

  printf("\n\nTime Now:\n");
  fprintf(fout, "\n\nTime Now:\n");
  GetTime(&zNow, fout);

/* 
   Calculate the difference of the two times, in seconds, and use the ConvertToCalendar () function to get this in terms of all "struct Calendar" variables.
*/

//Convert each date and time entered into a number of seconds from a reference date using SecondsFromZero(). January 1, 1980 at 00:00:00 works well, assuming the datesentered are after 1980.
  secondsNow = SecondsFromZero(zNow);
  secondsBirth = SecondsFromZero(zBirth);
//Take the difference of the two values in seconds.
  secondsDifference = secondsNow - secondsBirth;
//Convert the elapsed time in seconds to a variable of type “struct Calendar”using ConvertToCalendar().
  ConvertToCalendar(secondsDifference, &zNow);


/* 
   Print the results of the calculations to the screen.
*/ 

//Display the elapsed time in seconds.
  printf("\n\n\nIt has been %ld seconds since you were born.\n", secondsDifference);
  fprintf(fout, "\n\n\nIt has been %ld seconds since you were born.\n", secondsDifference);
//Display the elapsed time in the format: “You have been alive uuyears, vv months, wwdays, xx hours, yy minutes, and zz seconds.” using a variable of type “struct Calendar”. 
  printf("You have been alive %d years, %d months, %d days, %d hours, %d minutes, and %d seconds.\n\n", zNow.year, zNow.month, zNow.day, zNow.hour, zNow.minute, zNow.second);
  fprintf(fout, "You have been alive %d years, %d months, %d days, %d hours, %d minutes, and %d seconds.\n\n", zNow.year, zNow.month, zNow.day, zNow.hour, zNow.minute, zNow.second);

  fclose(fout);
}

/* 
   GetTime () is used to fill the instance of "struct Calendar" with user input.  It returns data through the pointer to a variable of type "struct Calendar". 
*/

void GetTime(struct Calendar *pTime, FILE *fout)
{

/* 
   Print and scan statements, requiring a particular input format
*/

  printf("Enter Date (mm-dd-yyyy): ");
  scanf("%2d%*c%2d%*c%4d", &(*pTime).month, &(*pTime).day, &(*pTime).year);

  printf("Enter 24-Hour Clock Time (hh:mm:ss): ");
  scanf("%2d%*c%2d%*c%2d", &(*pTime).hour, &(*pTime).minute, &(*pTime).second);

  fprintf(fout, "Enter Date (mm-dd-yyyy): %d-%d-%d",(*pTime).month,(*pTime).day,(*pTime).year);
  fprintf(fout, "\nEnter 24-Hour Clock Time (hh:mm:ss): %d-%d-%d",(*pTime).hour,(*pTime).minute,(*pTime).second);
}

/* 
   SecondsFromZero () returns the number of seconds a variable of type "struct Calendar" is from the reference time. According to current settings, this reference time is Jan 1, 1980 at 00:00:00. The year (1980) can be modified, but the other elements of the date may not be changed in this code. 
*/

long int SecondsFromZero(struct Calendar t)
{
  long int year_seconds, month_seconds, day_seconds, hour_seconds, minute_seconds, second_seconds, total_seconds;

/*
  Convert each parts of the date and time to seconds
*/

  year_seconds = (t.year - YEAR_ZERO) * YEAR_TO_SECONDS;
  month_seconds = t.month * MONTH_TO_SECONDS;
  day_seconds = t.day * DAY_TO_SECONDS;
  hour_seconds = t.hour * HOUR_TO_SECONDS;
  minute_seconds = t.minute * MINUTE_TO_SECONDS;
  second_seconds = t.second;

/*
  Once everything is converted to seconds, add them all up and return the total seconds.
*/

  total_seconds = year_seconds+month_seconds+day_seconds+hour_seconds+minute_seconds+second_seconds;

  return total_seconds;
}

/* 
   ConvertToCalendar () requires a number of seconds and the address of a "struct Calendar" variable. It utilizes integer division to determine how many years, months, days, etc. can be created from a number of seconds.
*/

void ConvertToCalendar(long int sec, struct Calendar *pz)
{

/* 
   remainder will be reused to store the remaining seconds available after integer division.
*/

  long int remainder;
  
  remainder = sec;

  (*pz).year = remainder / YEAR_TO_SECONDS;
  remainder = remainder - (*pz).year * YEAR_TO_SECONDS;
  (*pz).month = remainder / MONTH_TO_SECONDS;
  remainder = remainder - (*pz).month * MONTH_TO_SECONDS;
  (*pz).day = remainder / DAY_TO_SECONDS;
  remainder = remainder - (*pz).day * DAY_TO_SECONDS;
  (*pz).hour = remainder / HOUR_TO_SECONDS;
  remainder = remainder - (*pz).hour * HOUR_TO_SECONDS;
  (*pz).minute = remainder / MINUTE_TO_SECONDS;
  remainder = remainder - (*pz).minute * MINUTE_TO_SECONDS;
  (*pz).second = remainder;
  remainder = remainder - (*pz).second;
}

