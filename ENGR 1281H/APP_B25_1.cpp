/*****************************************/
/* Name: Jay Shin    Date: 10/19/2020    */
/* Seat: 00          File: APP_B23_1.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
printf("*****************************************\n");
printf("* Name: Jay Shin    Date: 10/19/2020    *\n");
printf("* Seat: 00          File: APP_B23_1.cpp *\n");
printf("* Instructor: Brooke Morin 12:40-2:45   *\n");
printf("*****************************************\n");
int randNum;
int num;
int play = 1;
int zero_counter = 0;
int one_counter = 0;
int two_counter = 0;
int three_counter = 0;
int four_counter = 0;
int five_counter = 0;
int cont;
while(play == 1){
//Prompt the user to enter any number of random integers to generate.
printf("How many random unbers would you like to generate?: ");
//Use a scanf statement to get this input.
scanf("%i", &num);
//Inform the user when an entry is invalid (When it is 0 or negative) and ignore that entry.
while(num <= 0){
printf("Entry is invalid.\n");
printf("How many random numbers would you like to generate?: ");
scanf("%i", &num);
}
//temporary counters
int t_zero_counter = 0;
int t_one_counter = 0;
int t_two_counter = 0;
int t_three_counter = 0;
int t_four_counter = 0;
int t_five_counter = 0;
for(int i = 0; i < num; i++){
//Use the random number generator to get a random integer in the range 0 <= x <= 5. 
randNum = rand()%6;
//Use a switch–case structures to count which value was generated
switch (randNum){
	case 0:
	t_zero_counter += 1;
	break;
	case 1:
	t_one_counter += 1;
	break;
	case 2:
	t_two_counter += 1;
	break;
	case 3:
	t_three_counter += 1;
	break;
	case 4:
	t_four_counter += 1;
	break;
	case 5:
	t_five_counter += 1;
	break;
}
//Repeat for the user specified number of times
}
//Display the results of how many occurrences of each value (0 through 5) there were and keep a running total for statistics.
printf("0s: %i\n", t_zero_counter);
printf("1s: %i\n", t_one_counter);
printf("2s: %i\n", t_two_counter);
printf("3s: %i\n", t_three_counter);
printf("4s: %i\n", t_four_counter);
printf("5s: %i\n", t_five_counter);
zero_counter += t_zero_counter;
one_counter += t_one_counter;
two_counter += t_two_counter;
three_counter += t_three_counter;
four_counter += t_four_counter;
five_counter += t_five_counter;
//At the end of each game prompt the user to choose one of the following:(1) play again(2) see statistics(3) reset statistics(4) quit
do{
printf("Enter 1 to play again, 2 to see statistics, 3 to reset statistics, and 4 to quit: ");
scanf("%i", &cont);
//Use an if  – else if – else structure to implement this choice.
if(cont == 1){
break;
}
if(cont == 2){
printf("0s: %i\n", zero_counter);
printf("1s: %i\n", one_counter);
printf("2s: %i\n", two_counter);
printf("3s: %i\n", three_counter);
printf("4s: %i\n", four_counter);
printf("5s: %i\n", five_counter);
}
else if(cont == 3){
zero_counter = 0;
one_counter = 0;
two_counter = 0;
three_counter = 0;
four_counter = 0;
five_counter = 0;
}
else if(cont == 4){
printf("Program quitting...");
play = 0;
cont = 1;
}
//Display an error if one of those options is not entered.
else{
printf("input a correct number!\n");
printf("Enter 1 to play again, 2 to see statistics, 3 to reset statistics, and 4 to quit: ");
scanf("%i", &cont);
}
} while(cont != 1);
}
}
