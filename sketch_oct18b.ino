#include "LowPower.h"
int t=1;

int S1=6;
int S2=6;
int S3=6;
int S4=6;
 
void setup()
{// The following saves some extra power by disabling some 
//q peripherals I am not using.

// Disable the ADC by setting the ADEN bit (bit 7)  of the
// ADCSRA register to zero.
  ADCSRA = ADCSRA & B01111111;

// Disable the analog comparator by setting the ACD bit
// (bit 7) of the ACSR register to one.
  ACSR = B10000000;

// Disable digital input buffers on all analog input pins
// by setting bits 0-5 of the DIDR0 register to one.
// Of course, only do this if you are not using the analog 
// inputs for your project.
  DIDR0 = DIDR0 | B00111111;

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
}
 
void loop()
{
  for(int i=0; i<t ;i++){
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    }
    digitalWrite(S1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(700);                       // wait for a second
    digitalWrite(S1, LOW);    // turn the LED off by making the voltage LOW 

for(int i=0; i<t ;i++){
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    }
    digitalWrite(S2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(700);                       // wait for a second
    digitalWrite(S2, LOW);    // turn the LED off by making the voltage LOW

for(int i=0; i<t ;i++){
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    }
    digitalWrite(S3, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(700);                       // wait for a second
    digitalWrite(S3, LOW);    // turn the LED off by making the voltage LOW
    
for(int i=0; i<t ;i++){
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    }
    digitalWrite(S4, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(700);                       // wait for a second
    digitalWrite(S4, LOW);    // turn the LED off by making the voltage LOW
}
