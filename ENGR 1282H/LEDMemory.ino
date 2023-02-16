#include <Servo.h>
#include <LiquidCrystal.h>
#define Button1 13
#define Button2 3
#define Button3 2
#define LED1 4
#define LED2 5
#define LED3 6
LiquidCrystal myLCD(7,8,9,10,11,12);
Servo myservo;
const int pCell = A0;

int ans[6];
int ansSize = 6;
int userAns[6];
int numOfLED = 3;
int i = 0;
bool start = false;
bool newGame = true; 
bool show = true; 
String failMsg = "TRY AGAIN!";

void setup() {
  Serial.begin(9600);
  myservo.attach(1);
  myLCD.begin(16,2);
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void puzzleStart(){
  while(!start){
    if(digitalRead(Button1) == LOW || digitalRead(Button2) == LOW || digitalRead(Button3) == LOW){
      delay(300);
      start = true;
    } else{
      myLCD.print("PRESS A BUTTON");
      myLCD.setCursor(0, 1);
      myLCD.print("TO START");
      delay(500);
    }
    myLCD.clear();
    delay(500);
  }  
}

void random(bool b){
  if(b){
    for(int j = 0; j < 6; j++){
      ans[j] = random(1, numOfLED + 1);
    }
  }
}

void play(){
  if(newGame){
    myLCD.print("PATTERN: ");
  }
  newGame = false;
  if(digitalRead(Button1) == LOW){
    myLCD.print(1);
    delay(300);
    userAns[i] = 1;
    i += 1;
  } else if(digitalRead(Button2) == LOW){
      myLCD.print(2);
      delay(300);
      userAns[i] = 2;
      i+= 1;
    } else if(digitalRead(Button3) == LOW){
      myLCD.print(3);
      delay(300);
      userAns[i] = 3;
      i+= 1;
    }
}

void failMessage(){
  myLCD.clear();
  for(int i = 0; i < failMsg.length(); i++){
    myLCD.print(failMsg.substring(i, i+1));
    delay(100);
  }
  delay(500);
  for(int i = 0; i < failMsg.length(); i++){
    myLCD.clear();
    myLCD.print(failMsg.substring(0, failMsg.length()-i));
    delay(100);
  }
  myLCD.clear();
  delay(500);
}

void checkResult(){
  if(i == 6){
    bool correct = true;
    for(int j = 0; j < 6; j++){
      if(userAns[j] != ans[j]){
        correct = false; 
        i = 0;
        break;
      }
    }
    while(correct){ 
      myLCD.clear();
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      int value = analogRead(pCell);
      value = map(value, 0, 1023, 0, 179);
      myservo.write(value+90);
      delay(1000);
      myLCD.print("GRAB THE CHARACTER");
      delay(1000);
    }

    digitalWrite(LED1, HIGH);
    int value = analogRead(pCell);
    value = map(value, 0, 1023, 0, 179);
    myservo.write(value+90);
    delay(1000);
    digitalWrite(LED1, LOW);
    value = analogRead(pCell);
    value = map(value, 0, 1023, 0, 179);
    myservo.write(value+90);
    delay(1000);
    failMessage();
    newGame = true; 
    show = true;
  }
}

void display(){
  if(show){
    for(int j = 0; j < 6; j++){
        myLCD.clear();
        myLCD.print("PATTERN");
        myLCD.setCursor(0, 1);
        myLCD.print("DISPLAYING...");
        if(ans[j] == 1){
          digitalWrite(LED1, HIGH);
          delay(100);
          digitalWrite(LED1, LOW);
          delay(100);
        } else if(ans[j] == 2){
          digitalWrite(LED2, HIGH);
          delay(100);
          digitalWrite(LED2, LOW);
          delay(100);
        } else{
          digitalWrite(LED3, HIGH);
          delay(100);
          digitalWrite(LED3, LOW);
          delay(100);
        }
        delay(500);
    }
    show = false;
    myLCD.clear();
  }
}
void loop() {
  puzzleStart();
  random(newGame);
  display();
  play();
  checkResult();
}
