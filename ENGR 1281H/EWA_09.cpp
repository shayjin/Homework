/*****************************************/
/* Name: Jay Shin    Date: 11/21/2020    */
/* Seat: 29          File: EWA_09.cpp */
/* Instructor: Brooke Morin 12:40-2:45   */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string.h>
#define PI 3.141592653589793238
struct sphere{  
float radius;  
float surface_area; 
float volume;  
char name[50];   
};
struct cube{  
float side;  
float face_area;  
float surface_area;  
float volume;  
char name[50];  
};
struct regtet{  
float side;  
float face_area;  
float surface_area;  
float volume;  
char name[50];  
};
void SetSphere(struct sphere *);  
void CalcSphere(struct sphere *);  
void DispSphere(struct sphere *);  
void SetCube(struct cube *);  
void CalcCube(struct cube *);  
void DispCube(struct cube *);  
void SetRegtet(struct regtet *);  
void CalcRegtet(struct regtet *);  
void DispRegtet(struct regtet *);
using namespace std;
typedef struct sphere Kirk; 
typedef struct cube Scotty; 
typedef struct regtet Spock; 
int main(){
  cout << "*****************************************" << endl;
  cout << "* Name: Jay Shin    Date: 11/21/2020    *" << endl;
  cout << "* Seat: 29          File: EWA_09.cpp    *" << endl;
  cout << "* Instructor: Brooke Morin  12:40-2:45  *" << endl;
  cout << "*****************************************" << endl;
  //In a file called EWA_09.cpp create a program that will run indefinitely and prompt the user with the following commands to perform the corresponding tasks
  struct sphere *s;
  struct cube *c;
  struct regtet *r;
  
  char ans;
  while(!(ans == 'q' || ans == 'Q')){
  cout << "Enter a to set sphere, b to calculate sphere, c to display sphere, d to set cube, e to calculate cube, f to display cube, g to set regtet, h to calculate regtet, i to display regtet, and q to quit: " << endl;
  cin >> ans;
    //1. a, A -- Set sphere radius and name
    if(ans == 'a' || ans == 'A'){
      SetSphere(s);
    }
    //2. b, B -- Calculate sphere surface area and volume
    else if(ans == 'b' || ans == 'B'){
      CalcSphere(s);
    }
    //3. c, C -- Display sphere radius, surface area, volume, and name 
    else if(ans == 'c' || ans == 'C'){
      DispSphere(s);
    }
    //4. d, D -- Set cube side length and name 
    else if(ans == 'd' || ans == 'D'){
      SetCube(c);
    }
    //5. e, E -- Calculate cube face area, surface area, and volume 
    else if(ans == 'e' || ans == 'E'){
      CalcCube(c);
    }
    //6. f, F -- Display cube side length, face area, surface area, volume, and name 
    else if(ans == 'f' || ans == 'F'){
      DispCube(c);
    }
    //7. g, G -- Set regular tetrahedron side length and name 
    else if(ans == 'g' || ans == 'G'){
      SetRegtet(r);
    }
    //8. h, H -- Calculate tetrahedron face area, surface area, and volume 
    else if(ans == 'h' || ans == 'H'){
      CalcRegtet(r);
    }
    //9. i, I -- Display tetrahedron side length, face area, surface area, volume, and name  
    else if(ans == 'i' || ans == 'I'){
      DispRegtet(r);
    }
    //10. q, Q -- Quit
    else if(ans == 'q' || ans == 'Q'){
      ans = 'q';
    }
  }   
}
void SetSphere(struct sphere *s){
  cout << "Enter sphere name: ", cin >> s->name;
  cout << "Enter sphere radius: ", cin >> s->radius;
}
void CalcSphere(struct sphere *s){
  s->surface_area = 4*PI*pow(s->radius, 2);
  s->volume = 4/3*PI*pow(s->radius, 3);
}
void DispSphere(struct sphere *s){
  cout << "Sphere name: " << s->name << " unit" << endl;
  cout << "Sphere radius: " << s->radius << " unit^2" << endl;
  cout << "Sphere surface area: " << s->surface_area << " unit^2" << endl;
  cout << "Sphere volume: " << s->volume << " unit^3" << endl;
}
void SetCube(struct cube *c){
  cout << "Enter cube name: ", cin >> c->name;
  cout << "Enter cube side length: ", cin >> c->side;
}
void CalcCube(struct cube *c){
  c->face_area = pow(c->side, 2);
  c->surface_area = c->face_area*6;
  c->volume = pow(c->side, 3);
}
void DispCube(struct cube *c){
  cout << "Cube name: " << c->name << endl;
  cout << "Cube side length: " << c->side << " unit" << endl;
  cout << "Cube face area: " << c->face_area << " unit^2" << endl;
  cout << "Cube surface area: " << c->surface_area << " unit^2" << endl;
  cout << "Cube volume: " << c->volume << " unit^3" << endl;
}
void SetRegtet(struct regtet *r){
  cout << "Enter regtet name: ", cin >> r->name;
  cout << "Enter regtet side length: ", cin >> r->side;
}
void CalcRegtet(struct regtet *r){
  r->face_area = pow(3, 0.5)*pow(r->side, 2)/4;
  r->surface_area = r->face_area*4;
  r->volume = pow(r->side, 3)/(6*pow(2, 0.5));
}
void DispRegtet(struct regtet *r){
  cout << "Regtet name: " << r->name << endl;
  cout << "Regtet side length: " << r->side << " unit" << endl;
  cout << "Regtet face area: " << r->face_area << " unit^2" << endl;
  cout << "Regtet surface area: " << r->surface_area << " unit^2" << endl;
  cout << "Regtet volume: " << r->volume << " unit^3" << endl;
}
