rr#include <LiquidCrystal.h>
#include <IRremote.h>
#define IR_PIN 3
#define zero 0xE916FF00
#define one 0xF30CFF00
#define two 0xE718FF00
#define three 0xA15EFF00
#define four 0xF708FF00
#define five 0xE31CFF00
#define six 0xA55AFF00
#define seven 0xBD42FF00
#define eight 0xAD52FF00
#define nine 0xB54AFF00
#define proceed 0xBC43FF00
#define back 0xBB44FF00

LiquidCrystal myLCD(7,8,9,10,11,12);

String questions[3][6] = {{"I wish yesterday", "was tomorrow", "Then today would", "be Friday", "What day is", "today?"}, {"Evaluate", "sin(x)/n = ?"}, {"2+2+2+2+2+2+2+2+2+", "2+2*0+2+2 = ?"}};
String ansChoices[3][4] = {{"Fri", "Sat", "Sun", "Mon"}, {"0", "6", "7", "8"}, {"0", "22", "4", "24"}};
String ans[3] = {ansChoices[0][2], ansChoices[1][1], ansChoices[2][3]};
int qSizes[3] = {6, 2, 2};
int guess[4];
int index = 0;
bool a = false;
bool cont = true;
bool inst = true;
bool ques = true;
int q = 0;
String str = "";

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
  myLCD.begin(16,2);
}
void clearLCD(String q1){
  for(int i = 0; i < q1.length(); i++){
    myLCD.clear();
    myLCD.setCursor(0,0);
    myLCD.print(q1.substring(0, q1.length()-i));
    delay(25);
  }
  myLCD.clear();
}


void timer(){
  for(int i = 3; i > 0; i--){
    myLCD.setCursor(0,0);
    myLCD.print("NO GUESSING!!!");
    myLCD.setCursor(0,1);
    myLCD.print("Try Again In:");
    myLCD.print(i);
    delay(1000);
    myLCD.clear();
  }
}

void correctMsg(){
  for(int i = 0; i < 5; i++){
    myLCD.clear();
    myLCD.print("CORRECT!");
    delay(250);
  }
}

void correct(){
  myLCD.clear();
  myLCD.print("CORRECT");
  delay(2000);
  ques = true;
  cont = true;
  q++;
}

void loop() {
  while(cont){
    while(ques){
      myLCD.clear();
      str = "QUESTION " + String(q+1);
      myLCD.print(str);
      delay(250);
      clearLCD(str); 
      ques = false;
    }
      for(int i = 0; i < qSizes[q]; i += 2){
        for(int j = 0; j < 3; j++){
          myLCD.setCursor(0,0);
          myLCD.print(questions[q][i]);
          myLCD.setCursor(0,1);
          str = questions[q][i+1];
          myLCD.print(str);
          delay(100);
          for(int i = 0; i < 4; i++){
            str += ".";
            myLCD.print(".");
            delay(100);
          } 
          myLCD.setCursor(0,0);
          myLCD.clear(); 
          myLCD.setCursor(0,1);
          myLCD.clear(); 
          if(IrReceiver.decode()){
            cont = false;
            break;
          }
       }
       if(i == qSizes[q]-1){
        i = 0;
       }       
     } 
  }
  myLCD.setCursor(0,0);
  myLCD.print("1. " + ansChoices[q][0]);
  myLCD.print("   2. " + ansChoices[q][1]);
  myLCD.setCursor(0,1);
  myLCD.print("3. " + ansChoices[q][2]);
  myLCD.print("   4. " + ansChoices[q][3]);
  while(!IrReceiver.decode()){}
  bool ac = false;
  if(IrReceiver.decode()){
    switch(IrReceiver.decodedIRData.decodedRawData){
      case back:
        myLCD.clear();
        delay(500);
        cont = true;
        ques = true;
        break;
      case one:
        if (ansChoices[q][0] == ans[q]){
            correct();
            break;
        } else{
          myLCD.clear();
          timer();
          break;
        }
      case two:
        if (ansChoices[q][1] == ans[q]){
            correct();
            break;
        } else{
          myLCD.clear();
          timer();
          break;
        }
        case three:
        if (ansChoices[q][2] == ans[q]){
            correct();
            break;
        } else{
          myLCD.clear();
          timer();
          break;
        }
      case four:
        if (ansChoices[q][3] == ans[q]){
            correct();
            break;
        } else{
          myLCD.clear();
          timer();
          break;
        }
  }
  while(q == 3){
    myLCD.clear();
    cont = false;
    ques = false;
    myLCD.print("DC motor thing");
    delay(1000);
  }
  IrReceiver.resume();
  }
}
  
