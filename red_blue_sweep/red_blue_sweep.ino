int inputUp = A3;
int inputDown = A2;

int redPin = 1;
int bluePin = 0;
//connect green to ground

//int outPin = 11;

int upVal;
int downVal;
int blueOut;
int redOut; 


void setup() 
{
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  //pinMode(outPin, OUTPUT);
}

void loop() 
{  
  upVal = pulseIn(inputUp, HIGH, 50000);
  downVal = pulseIn(inputDown, HIGH, 50000);
  upVal = constrain(upVal, 100, 20000);
  downVal = constrain(downVal, 100, 20000);
  
  if(downVal > 12000){//adjust upVal condition?
    int diff = downVal - 12000;
    blueOut = upVal - diff;
    redOut = downVal;
  }
  else if(upVal > 12000){
    int diff = upVal - 12000;
    redOut = downVal - diff;
    blueOut = upVal;
  }
  else{
    redOut = downVal;
    blueOut = upVal;
  }
  
  blueOut = constrain(blueOut, 0, 20000);
  redOut = constrain(redOut, 0, 20000);
  
  blueOut = map(blueOut, 0, 20000, 0, 254);
  redOut = map(redOut, 0, 20000, 0, 254);

  analogWrite(bluePin, blueOut);
  analogWrite(redPin, redOut);

}
