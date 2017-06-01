int inputUp = A3;
int inputDown = A2;

int redPin = 1;
int bluePin = 0;
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

  blueOut = map(upVal, 0, 1023, 0, 255);
  redOut = map(downVal, 0, 1023, 0, 255);

  analogWrite(bluePin, blueOut);
  analogWrite(redPin, redOut);

}
