int inputUp = 3;
int inputDown = 4;
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
  signed int diff;
  int dimmerVal;
  int outVal;   

  upVal = map(analogRead(inputUp), 0, 1023, 1023, 0);//flip to match pot dimmers
  downVal = map(analogRead(inputDown), 0, 1023, 1023, 0);
  
  diff = upVal - downVal;//range -1023 to +1023
  delay(1);

  dimmerVal = map(diff, -1023, 1023, -200, 255);//'halfway' point fairly dim; makes increase more visible
  analogWrite(ledPin, dimmerVal);

  outVal = map(diff, -1023, 1023, 0, 1023);//output as another pot
  analogWrite(outPin, outVal);
}
