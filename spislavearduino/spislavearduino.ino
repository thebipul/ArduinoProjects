//Arduino as SPI Slave
#include <LiquidCrystal.h>
const int rs =9, en = 8, d4 =7, d5 =6, d6 =5, d7=4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include<SPI.h>
#define LEDpin 3
#define buttonpin 2
volatile boolean received;
volatile byte Slavereceived,Slavesend;
int buttonvalue;
int x;
void setup()

{
  Serial.begin(115200);
  
  pinMode(buttonpin,INPUT);               // Setting pin 2 as INPUT
  pinMode(LEDpin,OUTPUT);                 // Setting pin 3 as OUTPUT
  pinMode(MISO,OUTPUT);                   //Sets MISO as OUTPUT (Have to Send data to Master IN 

  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  received = false;

  SPI.attachInterrupt();                  //Interuupt ON is set for SPI communication
  lcd.begin(16,2);
  
}

ISR (SPI_STC_vect)                        //Inerrrput routine function 
{
  Slavereceived = SPDR;         // Value received from master if store in variable slavereceived
  received = true;                        //Sets received as True 
}

void loop()
{ if(received)                            //Logic to SET LED ON OR OFF depending upon the value recerived from master
   {
      if (Slavereceived==1) 
      {
        digitalWrite(LEDpin,HIGH);         //Sets pin 3 as HIGH LED ON
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Slave LED ON");
      }else
      {
        digitalWrite(LEDpin,LOW);          //Sets pin 3 as LOW LED OFF
        lcd.setCursor(0,1);
        lcd.print("Slave LED OFF");
      }
      
      buttonvalue = digitalRead(buttonpin);  // Reads the status of the pin 2
      
      if (buttonvalue == HIGH)               //Logic to set the value of x to send to master
      {
        x=1;
        lcd.setCursor(0,0);
        lcd.print("Master LED ON ");        
      }else
      {
        x=0;
        lcd.setCursor(0,0);
        lcd.print("Master LED OFF");  
      }
      
  Slavesend=x;                             
  SPDR = Slavesend;                           //Sends the x value to master via SPDR 
  delay(1000);
}
}
