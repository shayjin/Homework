#include <LiquidCrystal.h>
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

LiquidCrystal myLCD(7,8,9,10,11,12);
int guess[4];
int password[4] = {1, 2, 3, 4};
int index = 0;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
  myLCD.begin(16,2);
}

void loop() {
  bool result = true;
  while(index < 4){
    if (IrReceiver.decode()){
      switch(IrReceiver.decodedIRData.decodedRawData){
        case zero:
          myLCD.print(0);
          guess[index] = 0;
          index += 1;
          delay(1000);
          break;
        case one:
          myLCD.print(1);
          guess[index] = 1;
          index += 1;
          delay(1000);
          break;
        case two:
          myLCD.print(2);
          guess[index] = 2;
          index += 1;
          delay(1000);
          break;
        case three:
          myLCD.print(3);
          guess[index] = 3;
          index += 1;
          delay(1000);
          break;
        case four:
          myLCD.print(4);
          guess[index] = 4;
          index += 1;
          delay(1000);
          break;
        case five:
          myLCD.print(5);
          guess[index] = 5;
          index += 1;
          delay(1000);
          break;
        case six:
          myLCD.print(6);
          guess[index] = 6;
          index += 1;
          delay(1000);
          break;
        case seven:
          myLCD.print(7);
          guess[index] = 7;
          index += 1;
          delay(1000);
          break;
        case eight:
          myLCD.print(8);
          guess[index] = 8;
          index += 1;
          delay(1000);
          break;
        case nine:
          myLCD.print(9);
          guess[index] = 9;
          index += 1;
          delay(1000);
          break;
      }
    IrReceiver.resume();
    }
  }
  for(int i = 0; i < 4; i++){
    if(password[i] != guess[i]){
      result = false;
    }
  }
  while(true){
    myLCD.setCursor(0,1);
    if(result){
      myLCD.print("Correct!");
    } else{
      myLCD.print("Incorrect!");
    }
  }
}
