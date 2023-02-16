/*****************************************/
/* Name: Jay Shin    Date: 11/20/2020    */
/* Seat: 29          File: APP_B37_1.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string.h>
//Write the class definition and member functions necessary to process the data. 
//Write a complete C/C++ program, APP_B37_1.cpp which includes a class called Year which contains the data members: 
using namespace std;
class Year{
  public:
    //a)Year(int y) – a constructor, which initializes max_index, year_avg and all elements of the array monthly_avg to zero and sets current_year to the year entered by the user, y.
    Year(int y);
    //b)GetData() – which reads the monthly values that correspond to the current_year from the data file and stores them in monthly_avg
    void GetData();
    //c)FindMax() – which finds the maximum value in monthly_avg and stores the index of that element in max_index. 
    void FindMax();
    //d)Average() – which determines the average of the values in monthly_avg for current_year and stores the result in year_avg. 
    void Average();
    //e)DisplayValues() – which displays the current_year, the average CO2 concentration for current_year, the month with the highest CO2 concentration, and the concentration for that month.  
    void DisplayValues();
   //int current_year, max_index; float year_avg, monthly_avg[12]
  private:
    int current_year;
    int max_index;
    float year_avg;
    float monthly_avg[12];
};
//The main() function and sample output are shown below.  
int main(){ 
  //Modify the main() function to read in and compute data for three years simultaneously
  int a;    
  cout << endl << "Enter any year between 1980 and 2007: ";    
  cin >> a;    
  Year y1(a);    
  y1.GetData();    
  y1.FindMax();      
  y1.Average();    
  y1.DisplayValues(); 
  //Compile, link, and run your program.
}

Year::Year(int y){
  max_index = 0;
  year_avg = 0;
  for(int i = 0; i < 12; i++){
    monthly_avg[i] = 0;
  }
  current_year = y;
}
void Year::GetData(){ 
  ifstream file;
  file.open("APP_B37_1_co2data.txt");
  
  int fileIndex = (current_year-1980)*12;
  int arrIndex = 0;
  float trash[(2007-1980+1)*12];

  for(int i = 0; i <= fileIndex+12; i++){
    if(i >= fileIndex && i <= fileIndex+12){
      file >> monthly_avg[arrIndex];
      arrIndex++;
    }
    else{
      file >> trash[i];
    }
  }
  file.close();
}
void Year::FindMax(){
  int max = 0;
  for(int i = 0; i < 12; i++){
    if(monthly_avg[i] > max){
      max = monthly_avg[i];
      max_index = i;
    }  
  }
}
 
