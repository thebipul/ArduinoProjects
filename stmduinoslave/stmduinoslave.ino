#include<SPI.h>

const int ledPin = 13;
const int buttonPin = 6;

volatile boolean received;
volatile int slaveReceive, slaveSend;

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT);
pinMode(MISO, OUTPUT);

digitalWrite(ledPin, LOW);
/* Turn on SPI in Slave Mode */
SPCR |= _BV(SPE);
received = false;
/* Interupt ON is set for SPI Commnunication */
SPI.attachInterrupt();
}

/* SPI ISR */
ISR (SPI_STC_vect)
{
/* Value received from master STM32F103C8T6 is stored in variable slaveReceive */
slaveReceive = SPDR;
received = true;
}

void loop()
{
slaveSend = digitalRead(buttonPin);
/* Send the slaveSend value to master STM32F103C8T6 via SPDR */
SPDR = slaveSend;

if(received == true)
{
if(slaveReceive == HIGH)
{
digitalWrite(ledPin, HIGH);
}

else
{
digitalWrite(ledPin, LOW);
}
}
}
