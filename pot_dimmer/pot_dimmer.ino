int sensorPin = A3;    // The potentiometer is connected to A3
int ledPin = 0;      // The LED is connected to pin 0
int outPin = 1;

void setup() // this function runs once when the sketch starts up
{
  pinMode(ledPin, OUTPUT);
}

void loop() // this function runs repeatedly after setup() finishes
{
  int sensorValue;
  int outValue;
  
  sensorValue = analogRead(sensorPin);    
  outValue = map(sensorValue, 0, 1023, 254, 0);//reversed for intuitiveness
  analogWrite(ledPin, outValue);
  analogWrite(outPin, outValue);
  /*digitalWrite(outPin, HIGH);
  delay(map(sensorValue, 0, 1023, 250, 1));
  digitalWrite(outPin, LOW);*/
}
