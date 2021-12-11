// This displays smiley and love emoji in LCD 16*2
#include <LiquidCrystal.h>
LiquidCrystal lcd(22,23,5,18,19,21);
byte emoji[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b10000
};
byte heart[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b10101,
  0b10001,
  0b01010,
  0b00100,
  0b00000
};
void setup(){
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Hello, world!");
    lcd.setCursor(0,1); 
    lcd.print ("emoji");
    
    lcd.createChar(0,emoji);
    
    lcd.createChar(1,heart);
    lcd.setCursor(7,1);
    lcd.write((byte)0);
    lcd.setCursor(8,1);
    lcd.write((byte)1);
}
void loop(){
}
