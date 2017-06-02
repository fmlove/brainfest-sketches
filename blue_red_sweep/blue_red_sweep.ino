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

  if(upVal < 20){
      upVal = 20 - downVal;
      if (upVal < 0){
          upVal = 0;
        }
    }

  if(downVal < 20){
      downVal = 20 - upVal;
      if (downVal < 0){
          downVal = 0;
        }
    }

  blueOut = map(downVal, 0, 1023, 0, 255);
  redOut = map(upVal, 0, 1023, 0, 255);

  analogWrite(bluePin, blueOut);
  analogWrite(redPin, redOut);

}
