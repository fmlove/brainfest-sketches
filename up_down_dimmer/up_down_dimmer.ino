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
  int outVal;

  upVal = pulseIn(inputUp, HIGH, 50000);//100 to 16000ish with PWM output running on battery pack; 0 if timeout
  downVal = pulseIn(inputDown, HIGH, 50000);

  diff = upVal - downVal;//range -16000 to +16000
  if(diff < 0){
    if(diff < -15000){ diff = -15000; }//make sure LED turns off when 'down' input is near max
    dimmerVal = map(diff, -15000, 0, 0, 40);
  }
  else{
    dimmerVal = map(diff, 0, 20000, 40, 254);
  }
  
  outVal = map(diff, -20000, 20000, 0, 254);//baseline output so colour sweeps can distinguish between no connection and low signal
  
  analogWrite(ledPin, dimmerVal);
  analogWrite(outPin, outVal);
}
