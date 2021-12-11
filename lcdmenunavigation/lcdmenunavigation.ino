// This helps in menu navigation between 6 menus in esp32
#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 23, 5, 18, 19, 21);  //LCD ports in Esp32
char *Opt[] = {"MenuA","MenuB","MenuC","MenuD","MenuE","MenuF"};
int i = 1 ;
#define Switch1 25                  //switch port to go down
#define Switch2 35                  //switch port to return to top
int switch1val = 0;                 //digitalRead value of switch1
int switch2val = 0;                 //digitalRead value of switch2
//byte selection[8] = {             //selection option
//  0b10000,
//  0b11000,
//  0b11100,
//  0b11110,
//  0b11111,
//  0b11110,
//  0b11100,
//  0b11000
//};

void setup() {
  pinMode(Switch1,INPUT);
  pinMode(Switch2,INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(Opt[0]);
  lcd.setCursor(0, 1);
  lcd.print(Opt[1]);
  
  //    lcd.createChar(0,selection);
  //    lcd.setCursor(7,1);
  //    lcd.write((byte)0);
  
}

void loop() {
  
  switch1val = digitalRead(Switch1);
  if (switch1val == HIGH &&i<5){
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(Opt[i]);
    lcd.setCursor(0, 1);
    lcd.print(Opt[i+1]); 
    i++;
  }
  switch2val = digitalRead(Switch2);
  if (switch2val == HIGH){
    i = 0;
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(Opt[i]);
    lcd.setCursor(0, 1);
    lcd.print(Opt[i+1]);
   }
}
