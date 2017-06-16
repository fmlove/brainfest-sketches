int sensorPin = A3;    // The potentiometer is connected to A3
int ledPin = 0;      // The LED is connected to pin 0
int outPin = 1;

int sensorValue;
int outValue;

void setup() // this function runs once when the sketch starts up
{
  pinMode(ledPin, OUTPUT);
}

void loop() // this function runs repeatedly after setup() finishes
{
  
  sensorValue = analogRead(sensorPin);

  outValue = map(sensorValue, 0, 1023, 254, 0);//reversed for intuitiveness
  analogWrite(ledPin, outValue);
  analogWrite(outPin, outValue);

}
