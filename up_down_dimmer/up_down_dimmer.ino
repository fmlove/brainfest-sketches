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

  upVal = pulseIn(inputUp, HIGH, 50000);//100 to 16000ish with PWM output running on battery pack; 0 if timeout
  downVal = pulseIn(inputDown, HIGH, 50000);

  diff = upVal - downVal;//range -16000 to +16000
  if(diff < -6500){diff = -6500;}
  
  dimmerVal = map(diff, -6500, 20000, 0, 254);//'halfway' point dim; makes increase more visible
  analogWrite(ledPin, dimmerVal);

  analogWrite(outPin, dimmerVal);
}
