/*****************************************/
/* Name: Jay Shin    Date: 11/17/2020    */
/* Seat: 29          File: APP_B36_1.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string.h>
//Use the io stream header file and the standard name space in your program.
using namespace std;
class Student
{
  //Note that the member functions must be public.
  public:
    //Contain the function prototypes:
    Student(char n[3], long int i, float g);
    Student();
      void fillStudent(char n[30], long int i, float g);
      void showdata();
    
  //Make the variables Name,ID and GPA private.
  private:
    char Name[30];
    long int ID;
    float GPA;
};
int main (){   
  cout << "*****************************************" << endl;
  cout << "* Name: Jay Shin    Date: 11/17/2020    *" << endl;
  cout << "* Seat: 29          File: APP_B36_1.cpp *" << endl;
  cout << "* Instructor: Brooke Morin  12:40-2:45  *" << endl;
  cout << "*****************************************" << endl;
  //variables
  char Name[30];
  long int ID;
  float GPA;

  Student oEng1, oEng2("My Name", 54321, 4.0);
  oEng1.showdata();    
  oEng2.showdata();    
  cout << "Enter the following data for the unknown student:" << endl;  

  //Also, use cin rather than scanf(), and cout rather than printf().
  cout << "Name (No Spaces)?: ";
  cin >> Name;
  cout << "ID (No Spaces)?: ";
  cin >> ID;
  cout << "GPA (No Spaces)?: ";
  cin >> GPA;     
  cout << endl;          

  oEng1.fillStudent(Name, ID, GPA);    
  oEng1.showdata();   
  oEng2.showdata(); 
  //Compile, link, and run your program.
} 
//a) a constructor member function Student() which will initialize the data members of an object in this class to the input arguments given
Student::Student(char n[30], long int i, float g){
  strcpy(Name, n);
  ID = i;
  GPA = g;
}
//if none are given, to appropriate default values (“Unknown” and zero are suggested)
Student::Student(){
  strcpy(Name, "Unknown");
  ID = 0;
  GPA = 0.0;
}
//b) a member function fillStudent() that will input a name, ID number, and GPA from the keyboard and assign them to the Name,ID,and GPA data members. 
void Student::fillStudent(char n[30], long int i, float g){
  strcpy(Name, n);
  ID = i;
  GPA = g;
}
//c) a member function showdata () which will output to the screen the values of the Name, ID, and GPA data members, 
void Student::showdata(){
  cout << "Name: " << Name << endl;
  cout << "ID: " << ID << endl;
  cout << "GPA: " << GPA << endl;
  cout << endl;
}

