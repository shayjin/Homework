/*****************************************/
/* Name: Jay Shin    Date: 11/10/2020    */
/* Seat: 29          File: APP_B33_1.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float mydot (float [], float []);
void mycross(float u[], float v[], float *);
int main()
{
	printf ("********************************************\n");
	printf ("* Name: Jay Shin          Date: 11/10/2020 *\n");
	printf ("* Seat: 29     File: APP_B32_1.cpp         *\n");
	printf ("* Instructor: Brooke Morin  12:40-2:45     *\n");
	printf ("********************************************\n\n");
	//declaring variables
	int i, j = 1;
	char k;
	float u[3], v[3], r[3], dot;
	FILE *ptr;
	//Writes the results to a file APP_B32_1_result.txt
	ptr = fopen("APP_B32_1_results.txt", "w");
	//Prompts the user to input two vectors, component by component
	//for loops allows user to enter vector values until they quit
	while (j == 1){
		//Reads the values entered by the user into the vector arrays
		//prompts user for values of first vector
		for (i = 0; i <=2; i++){
			printf("Enter a value for component #%i of vector 1: \n", i+1);
			scanf("%f", &u[i]);
		}
		//prompts user for values of second vector
		for (i = 0; i <=2; i++){
			printf("Enter a value for component #%i of vector 2: \n", i+1);
			//scan into vector component
			scanf("%f", &v[i]);
		}

		//prompt user to calculate dot or cross product
		printf("To find the dot product, press d. To find the cross product, press c. To quit, press anything else.\n");
		//scan into variable for condition
		scanf("%s", &k);

		//Allows the user to choose to calculate either the dot product (‘d’/’D’) or the cross product (‘c’/’C’) 
		//Passes the vectors to mydot()and mycross()in the format specified by the function prototypes above.
		//if user presses d, or D, calculate dot product with mydot function
		if (k == 'd' || k == 'D'){
			dot = mydot(u, v);
			//Displays the original vectors and either the resultant dot or cross product, depending on the user’s selection
			//print results to screen and text file
			printf("The dot product of vector 1 (<%f, %f, %f>) and vector 2 (<%f, %f, %f>) is %f\n", u[0], u[1], u[2], v[0], v[1], v[2], dot);
			fprintf(ptr, "The dot product of vector 1 (%f, %f, %f) and vector 2 (%f, %f, %f) is %f\n", u[0], u[1], u[2], v[0], v[1], v[2], dot);
			printf("Press 1 to play again.\n");
			scanf("%i", &j);
		}
		//if user preses c or C, calculate cross product with mycross function
		else if(k == 'C' || k == 'c'){
			mycross(u, v, r);
			//print results to screen and text file
			printf("The cross product of vector 1 (<%f, %f, %f>) and vector 2 (<%f, %f, %f>) is <%f, %f, %f>\n", u[0], u[1], u[2], v[0], v[1], v[2], *r, *(r+1), *(r+2));
			fprintf(ptr, "The cross product of vector 1 (<%f, %f, %f>) and vector 2 (<%f, %f, %f>) is <%f, %f, %f>\n", u[0], u[1], u[2], v[0], v[1], v[2], *r, *(r+1), *(r+2));
			printf("Press 1 to play again.\n");
			scanf("%i", &j);	
		}
		//for loops allows user to enter vector values until they quit
		//if user presses any other char, quit
		else{
			printf("Program quitting...");
			fprintf(ptr, "Program quitting...");
			j = 0;
		}
	}
	fclose(ptr);
}

float mydot(float u[3], float v[3])
{
	float vector3[3], dot;
	vector3[0] = u[0]*v[0];
	vector3[1] = u[1]*v[1];
	vector3[2] = u[2]*v[2];
	dot = vector3[0] + vector3[1] + vector3[2];
	return dot;
}
void mycross(float u[], float v[], float *r){	
	*r = u[1]*v[2]-u[2]*v[1];
	*(r+1) = u[2]*v[0]-u[0]*v[2];
	*(r+2) = u[0]*v[1]-u[1]*v[0];
}

	
	
/*
int main(){
	printf ("********************************************\n");
	printf ("* Name: Jay Shin          Date: 11/10/2020 *\n");
	printf ("* Seat: 29     File: APP_B32_1.cpp         *\n");
	printf ("* Instructor: Brooke Morin  12:40-2:45     *\n");
	printf ("********************************************\n\n");
	bool cont = true; 
	float ux, uy, uz, vx, vy, vz;

	printf("Input x-coordinate of vector u: ");
	scanf("%f", &ux);
	printf("Input y-coordinate of vector u: ");
	scanf("%f", &uy);
	printf("Input z-coordinate of vector u: ");
	scanf("%f", &uz);
	printf("Input x-coordinate of vector v: ");
	scanf("%f", &vx);
	printf("Input y-coordinate of vector v: ");
	scanf("%f", &vy);
	printf("Input z-coordinate of vector v: ");
	scanf("%f", &vz);

	float u[3] = {ux, uy, uz};
	float v[3] = {vx, vy, vz};
	float r[3];

	while(cont){
		char choice; 
		printf("dot product (enter d) or cross product (enter c)?: ");
		scanf("%s", &choice);
		//Allows the user to choose to calculate either the dot product (‘d’/’D’) or the cross product (‘c’/’C’) 
		//Displays the original vectors and either the resultant dot or cross product, depending on the user’s selection
		switch(choice){
			case 'd':
			case 'D':
				printf("vector u: <%f, %f, %f>\n", ux, uy, uz);
				printf("vector v: <%f, %f, %f>\n", vx, vy, vz);
				printf("resultant vector: %f\n", mydot(u,v));
				break;
			case 'c':
			case 'C':
				printf("vector u: <%f, %f, %f>\n", ux, uy, uz);
				printf("vector v: <%f, %f, %f>\n", vx, vy, vz);
				mycross(u, v, r);
				printf("cross product: <%f, %f, %f>\n",  *r, *(r+1), *(r+2));
				break;
			default:
				printf("program quitting...");
				cont = false;
				break;
		}
	}

	return 0;
}*/





