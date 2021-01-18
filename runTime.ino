



void setup() {
  // put your setup code here, to run once:
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
  
  tm1637.init();
  Serial.begin(9600);
  //Serial.println("set");
}

void loop() {
  // put your main code here, to run repeatedly: 
  //Serial.println(startPush);
  if(startPush){
    numOfMinutes = TimeUpdate();
    tm1637.display(TimeDisp);
  }
}


int TimeUpdate(void)
{
  if(clockInit){
      startTime = millis();
      clockInit = false;
    }
  unsigned long currentTime = millis() - startTime;
  int _seconds = (currentTime/1000) % 60;
  int _minutes = ((currentTime/1000)/60) % 60;
  TimeDisp[2] = _seconds / 10;
  TimeDisp[3] = _seconds % 10;
  TimeDisp[0] = _minutes / 10;
  TimeDisp[1] = _minutes % 10;

  return _minutes;
}
