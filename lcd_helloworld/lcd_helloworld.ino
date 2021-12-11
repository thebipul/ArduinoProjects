#include <LiquidCrystal.h>
LiquidCrystal lcd(22,23,5,18,19,21);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(20,4);
  lcd.clear();
  lcd.print("Hello World!");
  lcd.setCursor(0,1);
  lcd.print("Good Morning");
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
