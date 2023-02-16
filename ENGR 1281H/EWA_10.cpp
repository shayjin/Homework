/*****************************************/
/* Name: Jay Shin    Date: 11/27/2020    */
/* Seat: 29          File: EWA_10.cpp    */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#define PI 3.141592653589793238
class sphere{
  private:  
    float radius;  
    float surface_area;  
    float volume;  
    char name[];  
  public: 
    sphere(float r= 0, float sa= 0, float v= 0, char name[] = "yoda");  
      void set();  
      void calc();  
      void show();  
};  
class cube  {  
  private: 
    float side;  
    float face_area;  
    float surface_area;  
    float volume;  
    char name[50];   
  public: 
    cube(float = 0, float = 0, float = 0, float = 0, char [] = "obiwan");  
    void set();  
    void calc();  
    void show();  
}; 

class regtet{  
private:
float side;  
float face_area;  
float surface_area;  
float volume;  
char name[50];  
public:
regtet(float = 0, float = 0, float = 0, float = 0, char[] = "anakin");
void set();
void calc();
void show();
};
using namespace std;
int main(){
  cout << "*****************************************" << endl;
  cout << "* Name: Jay Shin    Date: 11/27/2020    *" << endl;
  cout << "* Seat: 29          File: EWA_10.cpp    *" << endl;
  cout << "* Instructor: Brooke Morin  12:40-2:45  *" << endl;
  cout << "*****************************************" << endl;
  //In a file called EWA_09.cpp create a program that will run indefinitely and prompt the user with the following commands to perform the corresponding tasks.
  sphere s;
  cube c;
  regtet r;
  
  char ans;
  while(!(ans == 'q' || ans == 'Q')){
  cout << "Enter a to set sphere, b to calculate sphere, c to display sphere, d to set cube, e to calculate cube, f to display cube, g to set regtet, h to calculate regtet, i to display regtet, and q to quit: " << endl;
  cin >> ans;
    //1. a, A -- Set sphere radius and name
    if(ans == 'a' || ans == 'A'){
      s.set();
    }
    //2. b, B -- Calculate sphere surface area and volume
    else if(ans == 'b' || ans == 'B'){
      s.calc();
    }
    //3. c, C -- Display sphere radius, surface area, volume, and name 
    else if(ans == 'c' || ans == 'C'){
      s.show();
    }
    //4. d, D -- Set cube side length and name 
    else if(ans == 'd' || ans == 'D'){
      c.set();
    }
    //5. e, E -- Calculate cube face area, surface area, and volume 
    else if(ans == 'e' || ans == 'E'){
      c.calc();
    }
    //6. f, F -- Display cube side length, face area, surface area, volume, and name 
    else if(ans == 'f' || ans == 'F'){
      c.show();
    }
    //7. g, G -- Set regular tetrahedron side length and name 
    else if(ans == 'g' || ans == 'G'){
      r.set();
    }
    //8. h, H -- Calculate tetrahedron face area, surface area, and volume 
    else if(ans == 'h' || ans == 'H'){
      r.calc();
    }
    //9. i, I -- Display tetrahedron side length, face area, surface area, volume, and name  
    else if(ans == 'i' || ans == 'I'){
      r.show();
    }
    //10. q, Q -- Quit
    else if(ans == 'q' || ans == 'Q'){
      ans = 'q';
    }
  }   
}
sphere::sphere(float r, float sa, float v, char na[])
{
radius = r;
surface_area = sa;
volume = v;
strcpy(name, na);
}
void sphere::set()
{
  cout << "Enter sphere name: ", cin >> name;
  cout << "Enter sphere radius: ", cin >> radius;
}
void sphere::calc()
{
  surface_area = 4*PI*pow(radius, 2);
  volume = 4/3*PI*pow(radius, 3);
}
void sphere::show()
{
  cout << sphere::name;
  cout << "Sphere name: " << name << endl;
  cout << "Sphere radius: " << radius << " unit^2" << endl;
  cout << "Sphere surface area: " << surface_area << " unit^2" << endl;
  cout << "Sphere volume: " << volume << " unit^3" << endl;
}
cube::cube(float s, float fa, float sa, float v, char na[])
{
side = s;
face_area = fa;  
surface_area = sa;
volume = v;
strcpy(name, na);
}
void cube::set()
{
  cout << "Enter cube name: ", cin >> name;
  cout << "Enter cube side length: ", cin >> side;
}
void cube::calc()
{
  face_area = pow(side, 2);
  surface_area = face_area*6;
  volume = pow(side, 3);
}
void cube::show()
{
  cout << "Cube name: " << name << endl;
  cout << "Cube side length: " << side << " unit" << endl;
  cout << "Cube face area: " << face_area << " unit^2" << endl;
  cout << "Cube surface area: " << surface_area << " unit^2" << endl;
  cout << "Cube volume: " << volume << " unit^3" << endl;
}
regtet::regtet(float s, float fa, float sa, float v, char na[])
{
side = s;
face_area = fa;  
surface_area = sa;
volume = v;
strcpy(name, na);
}
void regtet::set()
{
  cout << "Enter regtet naame: ", cin >> name;
  cout << "Enter regtet side length: ", cin >> side;
}
void regtet::calc()
{
  face_area = pow(3, 0.5)*pow(side, 2)/4;
  surface_area = face_area*4;
  volume = pow(side, 3)/(6*pow(2, 0.5));
}
void regtet::show()
{
  cout << "Regtet name: " << name << endl;
  cout << "Regtet side length: " << side << " unit" << endl;
  cout << "Regtet face area: " << face_area << " unit^2" << endl;
  cout << "Regtet surface area: " << surface_area << " unit^2" << endl;
  cout << "Regtet volume: " << volume << " unit^3" << endl;
}

