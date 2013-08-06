/*
  Hand Motion Sensor
  Turns on a LED when hand is within 1-2 inches from the photocell
  
  Reads an analog input on pin A0 that is pulled down through a 10K resistor. 
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
  The LED is connected to a PWM pin, such as pin11 on the Arduino Uno. 
 */

int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from photocell
int LEDpin = 11;          // connect LED to a PWM pin
int LEDbrightness;        

void setup(void) {
  Serial.begin(9600);   
}
 
void loop(void) {
  //the analog reading of the photocell
  //ranges from 0 to 1023
  //ranges from 350 covering directly with hand, 500 hovering hand above, and 850 in an indoor room
  photocellReading = analogRead(photocellPin);  
 
  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  //invertedPhotocellReading is now ~200 when bright and ~700 when dark
  //inverted range is 100 - 750

  //
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  if (photocellReading < 800)
  {
    //photo reading 600 - 0; 50 - 550
    LEDbrightness = map(800-photocellReading, 0, 800, 20, 255);
  }
  else
  {
    LEDbrightness = 0;
  }
  Serial.print("LED brightness = ");
  Serial.println(LEDbrightness);

  analogWrite(LEDpin, LEDbrightness);
 
  delay(100);
}
