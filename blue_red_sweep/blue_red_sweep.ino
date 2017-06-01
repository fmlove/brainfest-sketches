int inputUp = 0;
int inputDown = 2;

int redPin = 9;
int bluePin = 10;
//connect green to ground

//int outPin = 11;

int upVal;
int downVal;

void setup() 
{
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  //pinMode(outPin, OUTPUT);
}

void loop() 
{  
  int blueOut;
  int redOut;     

  upVal = analogRead(inputUp);
  downVal = analogRead(inputDown);
  
  /*outVal = map(diff, -1023, 1023, 0, 1023);//output as another pot
  analogWrite(outPin, outVal);*/

  blueOut = map(downVal, 0, 1023, 0, 255);
  redOut = map(upVal, 0, 1023, 0, 255);

  analogWrite(bluePin, blueOut);
  analogWrite(redPin, redOut);
  delay(1);
}
