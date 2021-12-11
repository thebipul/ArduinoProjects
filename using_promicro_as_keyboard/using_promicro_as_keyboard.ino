#include "Keyboard.h"

#define Button5 9

void setup() {
  Keyboard.begin();
  pinMode(Button5, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(Button5) == LOW){
    Keyboard.print("testid"); //ID
    Keyboard.write(KEY_TAB);
    delay(100);
    Keyboard.print("test"); //password
    Keyboard.write(KEY_TAB);
    Keyboard.write(KEY_RETURN);

    while(digitalRead(Button5) == LOW);
  }

  delay(100);
}
