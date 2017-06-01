int inputUp = A3;
int inputDown = A2;
int ledPin = 0;
int outPin = 1;

int upVal;
int downVal;

void setup() 
{
  pinMode(ledPin, OUTPUT);  
}

void loop() 
{
  int diff;
  int dimmerVal;

  upVal = analogRead(inputUp);//0 to 1023
  downVal = analogRead(inputDown);

  diff = upVal - downVal;//range -1023 to +1023
  if(diff < -50){diff = -50;}
  
  dimmerVal = map(diff, -50, 1023, 0, 255);//'halfway' point dim; makes increase more visible
  analogWrite(ledPin, dimmerVal);

  analogWrite(outPin, dimmerVal);
}
