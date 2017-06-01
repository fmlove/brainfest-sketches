int inputUp = 3;
int inputDown = 4;
int ledPin = 0;
int outPin = 1;

int upVal;
int downVal;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  //upVal = 0;
  //downVal = 0;
}

void loop() 
{
  signed int diff;
  int dimmerVal;
  int outVal;
    
  //auto fade
  /*if(upVal < 1023 && downVal == 0){
    upVal++;
  }
  else if(upVal == 1023 && downVal < 1023){
    downVal++;
  }
  else if(upVal <= 1023 && upVal > 0 && downVal == 1023){
    upVal--;
  }
  else if(upVal == 0 && downVal <= 1023 && downVal > 0){
    downVal--;
  }*/

  upVal = analogRead(inputUp);
  downVal = analogRead(inputDown);
  
  diff = upVal - downVal;//range -1023 to +1023
  delay(1);

  dimmerVal = map(diff, -1023, 1023, -200, 255);//'halfway' point fairly dim; makes increase more visible //flipped to match pot dimmers
  analogWrite(ledPin, dimmerVal);

  outVal = map(diff, -1023, 1023, 0, 1023);//output as another pot //flipped
  analogWrite(outPin, outVal);
}
