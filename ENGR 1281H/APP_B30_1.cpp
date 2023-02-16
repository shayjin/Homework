/*****************************************/
/* Name: Jay Shin    Date: 11/08/2020    */
/* Seat: 00          File: APP_B30_1.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
printf("*****************************************\n");
printf("* Name: Jay Shin    Date: 11/08/2020    *\n");
printf("* Seat: 00          File: APP_B30_1.cpp *\n");
printf("* Instructor: Brooke Morin 12:40-2:45   *\n");
printf("*****************************************\n");
//Complete APP_B30_1.cpp to:−Read the names into a two-dimensional array of characters.
FILE *input, *output;
char *nameptr[30];
char name2d[30][30];
int index = 0;
char n[30];
//Assign the address of the beginning of each row in the two-dimensional character array to the corresponding element in the one-dimensional pointer to character array
input = fopen("APP_B30_1_names.dat", "r");

while(feof(input) == 0){
	fgets(name2d[index], 30, input);
	if(feof(input) == 0){
		nameptr[index] = name2d[index];
		index++;
	}
}
fclose(input);
//Print out the list of names in the original order using the one-dimensional pointer to character array
printf("Using 1D pointer to character array: \n");
for(int i = 0; i < index; i++){
	printf("%s", nameptr[i]);
}
//For comparison, print out the list of names in the original order using the two-dimensional character array
printf("\nUsing original 2D array: \n");
for(int k = 0; k < index; k++){
	printf("%s", name2d[k]);
}
//Using a pointer to character array, the strcmp() function, and the bubble sort algorithm, sort the names into alphabetical order.
for(int x = 0; x < index; x++){
	for(int g = 0; g < index-1; g++){
		if(strcmp(nameptr[g+1], nameptr[g]) < 0){
			char *temp = nameptr[g+1];
			nameptr[g+1] = nameptr[g];
			nameptr[g] = temp;
		}
	}
} 
//Print out the list of names in alphabetical order using the one-dimensional pointer to character array
printf("\nAlphabetical Order using 1D pointer array: \n");
for(int y = 0; y < index; y++){
	printf("%s", nameptr[y]);
}
//For comparison, print out the list of names in the original order using the two-dimensional character array again
printf("\nAlphabetical Order using 2D character array: \n");
for(int z = 0; z < index; z++){
	printf("%s", nameptr[z]);
}
//Open an output file, APP_B30_1_result.txt, and write everything to the file that is being written to the screen.
output = fopen("APP_B30_1_result.txt", "w");
index = 0;
input = fopen("APP_B30_1_names.dat", "r");
while(feof(input) == 0){
	fgets(name2d[index], 30, input);
	if(feof(input) == 0){
		nameptr[index] = name2d[index];
		index++;
	}
}
fclose(input);
fprintf(output, "Using 1D pointer to character array: \n");
for(int i = 0; i < index; i++){
	fprintf(output, "%s", nameptr[i]);
}
fprintf(output, "\nUsing original 2D array: \n");
for(int k = 0; k < index; k++){
	fprintf(output, "%s", name2d[k]);
}
for(int x = 0; x < index; x++){
	for(int g = 0; g < index-1; g++){
		if(strcmp(nameptr[g+1], nameptr[g]) < 0){
			char *temp = nameptr[g+1];
			nameptr[g+1] = nameptr[g];
			nameptr[g] = temp;
		}
	}
} 
fprintf(output, "\nAlphabetical Order using 1D pointer array: \n");
for(int y = 0; y < index; y++){
	fprintf(output, "%s", nameptr[y]);
}
fprintf(output, "\nAlphabetical Order using 2D character array: \n");
for(int z = 0; z < index; z++){
	fprintf(output, "%s", nameptr[z]);
}
fclose(output);
//Compile, link, and run your program.
}

