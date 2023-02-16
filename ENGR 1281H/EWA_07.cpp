/*****************************************/
/* Name: Jay Shin    Date: 11/04/2020    */
/* Seat: 00          File: EWA_07.cpp    */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
printf("*****************************************\n");
printf("* Name: Jay Shin    Date: 11/04/2020    *\n");
printf("* Seat: 00          File: EWA_07.cpp    *\n");
printf("* Instructor: Brooke Morin 12:40-2:45   *\n");
printf("*****************************************\n");
//In the file EWA_07.cpp, complete the following tasks:
FILE *input, *output;
int index = 0;
int numI[250];
float numF[250];
int oneThree = 0, oneThreeSum = 0, fourSix = 0, fourSixSum = 0, sevenNine = 0, sevenNineSum = 0, tenTwelve = 0, tenTwelveSum = 0;
float zeroToTwentyFive = 0, zeroToTwentyFiveSum = 0, twentyFiveToFifty = 0, twentyFiveToFiftySum = 0, fiftyToSeventyFive = 0, fiftyToSeventyFiveSum = 0, seventyFiveToHundred = 0, seventyFiveToHundredSum;
//Open the file EWA_07_random.dat and read in the integer and floating point values.
input = fopen("EWA_07_random.dat", "r");
//Open the file EWA_07.txt for writing.
output = fopen("EWA_07.txt", "w");
while(feof(input) == 0){
	fscanf(input, "%i%f", &numI[index], &numF[index]);
	if(feof(input) == 0){
		//Count the number of integer and floating point pairs (i.e.,  the number of lines).
		index++;
	}
}
fclose(input);
//Uses an if-else if selection structure for floating point values and a switch-case structure for integer values to find the averages over the following ranges:
for(int i = 0; i < index; i++){
	switch(numI[i]){
		//Integer 1 – 3 
		case 1:
		case 2:
		case 3:
			oneThree += 1;
			oneThreeSum += numI[i];
			break;
		//4 – 6 
		case 4:
		case 5:
		case 6:
			fourSix += 1;
			fourSixSum += numI[i];
			break;
		//7 – 9 
		case 7:
		case 8:
		case 9:
			sevenNine += 1;
			sevenNineSum += numI[i];
			break;
		//10 – 12 
		case 10:
		case 11:
		case 12:
			tenTwelve += 1;
			tenTwelveSum += numI[i];
			break;
	}
	//Float   0 to <= 25 
	if(0 <= numF[i] && numF[i] <= 25){
		zeroToTwentyFive += 1;
		zeroToTwentyFiveSum += numF[i];
	}
	//>25 to <= 50 
	else if(25 < numF[i] && numF[i] <= 50){
		twentyFiveToFifty += 1;
		twentyFiveToFiftySum += numF[i];	
	}
	//>50 to <= 75
	else if(50 < numF[i] && numF[i] <= 75){
		fiftyToSeventyFive += 1;
		fiftyToSeventyFiveSum += numF[i];
	}
	//>75 to <= 100
	else if(75 < numF[i] && numF[i] <= 100){
		seventyFiveToHundred += 1;
		seventyFiveToHundredSum += numF[i];
	}
}
//Write the number of integer and floating point pairs to the screen and to EWA_07.txt. 
printf("Number of integer and folating point pairs: %i\n", index);
fprintf(output, "Number of integer and floating pairs: %i\n", index);
//For each range listed above, write the average of the integer values
printf("Average of integer 1-3: %f\n", 1.0*oneThreeSum/oneThree);
printf("Average of integer 4-6: %f\n", 1.0*fourSixSum/fourSix);
printf("Average of integer 7-9: %f\n", 1.0*sevenNineSum/sevenNine);
printf("Average of integer 10-12: %f\n", 1.0*tenTwelveSum/tenTwelve);
//and the average of the floating point values to the screen
printf("Average of float [0, 25]: %f\n", zeroToTwentyFiveSum/zeroToTwentyFive);
printf("Average of float (25, 50]: %f\n", twentyFiveToFiftySum/twentyFiveToFifty);
printf("Average of float (50, 75]: %f\n", fiftyToSeventyFiveSum/fiftyToSeventyFive);
printf("Average of float (75, 100]: %f\n", seventyFiveToHundredSum/seventyFiveToHundred);
//and to EWA_07.txt. 
fprintf(output, "Average of integer 1-3: %f\n", 1.0*oneThreeSum/oneThree);
fprintf(output, "Average of integer 4-6: %f\n", 1.0*fourSixSum/fourSix);
fprintf(output, "Average of integer 7-9: %f\n", 1.0*sevenNineSum/sevenNine);
fprintf(output, "Average of integer 10-12: %f\n", 1.0*tenTwelveSum/tenTwelve);
fprintf(output, "Average of float [0, 25]: %f\n", zeroToTwentyFiveSum/zeroToTwentyFive);
fprintf(output, "Average of float (25, 50]: %f\n", twentyFiveToFiftySum/twentyFiveToFifty);
fprintf(output, "Average of float (50, 75]: %f\n", fiftyToSeventyFiveSum/fiftyToSeventyFive);
fprintf(output, "Average of float (75, 100]: %f\n", seventyFiveToHundredSum/seventyFiveToHundred);
fclose(output);
//Hint:You will want to use a while loop to read the data from the file. You should look at the slides from the switch-case lecture and consider replacing grade = getchar () with an appropriate fscanf () statement. Additionally, you can look in Chapters 3 and 4 of your text for examples.
//Another hint: Get small pieces of the program working one at a time. Don't try to write the whole thing at once, for example, read the data from the file and count the number of lines of data, before you write the code to determine the averages for each range.
}
int main(){
//In the file EWA_07.cpp, complete the following tasks:
//Open the file EWA_07_random.dat and read in the integer and floating point values.
//Open the file EWA_07.txt for writing.
//Count the number of integer and floating point pairs (i.e.,  the number of lines).
//Uses an if-else if selection structure for floating point values and a switch-case structure for integer values to find the averages over the following ranges:
//Integer 1 – 3 
//4 – 6 
//7 – 9 
//10 – 12 
//Float   0 to <= 25 
//>25 to <= 50 
//>50 to <= 75
//>75 to <= 100
//Write the number of integer and floating point pairs to the screen and to EWA_07.txt. 
//For each range listed above, write the average of the integer values
//and the average of the floating point values to the screen
//and to EWA_07.txt. 
//Hint:You will want to use a while loop to read the data from the file. You should look at the slides from the switch-case lecture and consider replacing grade = getchar () with an appropriate fscanf () statement. Additionally, you can look in Chapters 3 and 4 of your text for examples.
//Another hint: Get small pieces of the program working one at a time. Don't try to write the whole thing at once, for example, read the data from the file and count the number of lines of data, before you write the code to determine the averages for each range.
}

