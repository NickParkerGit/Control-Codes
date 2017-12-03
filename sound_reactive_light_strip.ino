#define LEDstrip 9


void setup()
{
  pinMode(7,INPUT); //SIG of the Parallax Sound Impact Sensor connected to Digital Pin 7
  pinMode(LEDstrip, OUTPUT);

}

//this function will make the LED dim once the Parallax Sound Impact Sensor sends a 1 signal, and then return to it’s original brightness.
void loop()
{
  boolean soundstate = digitalRead(7);
  if (soundstate == 1) {
         analogWrite(LEDstrip, 255);
         delay(10);
  }
  else{
  
    analogWrite(LEDstrip,0);
  }
}
