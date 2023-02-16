/*****************************************/
/* Name: Jay Shin    Date: 11/13/2020    */
/* Seat: 29          File: APP_B33_1.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#define COLUMN 2
#define ROW 5
using namespace std;

int main(){
  cout << "*****************************************" << endl;
  cout << "* Name: Jay Shin    Date: 11/16/2020    *" << endl;
  cout << "* Seat: 29          File: APP_B35_1.cpp *" << endl;
  cout << "* Instructor: Brooke Morin  12:40-2:45  *" << endl;
  cout << "*****************************************" << endl;

  //variables
  ifstream input;
  ofstream output;
  float tri[ROW][COLUMN];
  string s;
  int num;
  float perimeter, area, hypotenuse;
  bool cont = true;
  
  //read data from the file APP_B35_1_triangle.dat into a two dimensional array. 
  input.open("APP_B35_1_triangle.dat", fstream::app);
  for(int r = 0; r < ROW; r++){
    for(int c = 0; c < COLUMN; c++){
      input >> tri[r][c];
    }
  }
  
  //print the results to an output file, APP_B35_1_result.txt
  output.open("APP_B35_1_result.txt");
   
  output << "*****************************************" << endl;
  output << "* Name: Jay Shin    Date: 11/16/2020    *" << endl;
  output << "* Seat: 29          File: APP_B35_1.cpp *" << endl;
  output << "* Instructor: Brooke Morin  12:40-2:45  *" << endl;
  output << "*****************************************" << endl;

  //repeat the program until the user decides to quit
  while(cont){
    //prompt the user to select which calculation is to be performed by entering P for Perimeter, A for Area, or H for Hypotenuse.
    cout << "Enter p for perimeter, a for area, h for hypotenuse, or q to quit: ";
    cin >> s;
    //display an error message if the user makes an invalid entry.
    if(s[0] != 'p' && s[0] != 'P' && s[0] != 'a' && s[0] != 'A' && s[0] != 'h' && s[0] != 'H' && s[0] != 'q' && s[0] != 'Q'){
      cout << "Invalid Entry" << endl;
      output << "Invalid Entry" << endl;
    }  
    else if(s[0] == 'q' || s[0] == 'Q'){
      cout << "Quitting..." << endl;
      output << "Quitting..." << endl;
      cont = false;
    }
    else{
      //prompt the user to enter the triangle number in the data file to perform the computation on. 
      cout << "Triangle Number?: ";
      cin >> num;
      //display only the requested parameter along with the triangle base and height. 
      if(num > 0 && num <= 5){
        cout << "Base of Triangle " << num << ": " << tri[num-1][0] << " mm" << endl;
        cout << "Height of Triangle " << num << ": " << tri[num-1][1] << " mm" << endl;

        output << "Base of Triangle " << num << ": " << tri[num-1][0] << " mm" << endl;
        output << "Height of Triangle " << num << ": " << tri[num-1][1] << " mm" << endl;
        //use only the first letter of each parameter. 
        //accept either upper or lower case letters for the selected parameter (i.e., p, P or a,  A  or h, H).
        if(s[0] == 'p' || s[0] == 'P'){
          perimeter = (tri[num-1][0] + tri[num-1][1]) * 2;
          //label all values descriptively and with units.
          //make the display to the screen and file well formatted and neat.
          cout << "Perimeter of Triangle"  << num << ": " << perimeter << " mm" << endl;
          output << "Perimeter of Triangle"  << num << ": " << perimeter << " mm" << endl;
        }
        else if(s[0] == 'a' || s[0] == 'a'){
          area = tri[num-1][0] * tri[num-1][1] / 2;
          cout << "Area of Triangle " << num << ": " << area << " mm^2" << endl;
          output << "Area of Triangle " << num << ": " << area << " mm^2" << endl;
        }  
        else if(s[0] == 'h' || s[0] == 'H'){
          hypotenuse = sqrt(pow(tri[num-1][0], 2) + pow(tri[num-1][1], 2));
          cout << "Hypotenuse of Triangle " << num << ": " << hypotenuse << " mm" << endl;
          output << "Hypotenuse of Triangle " << num << ": " << hypotenuse << " mm" << endl;
        }
      }
      //display an error message if the user makes an invalid entry.
      else{
        cout << "Invalid Entry" << endl;
        output << "Invalid Entry" << endl;
      }    
    }
  }
  input.close();
  output.close();
  
  return 0;
}

