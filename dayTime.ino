

void setup() {
  daytime = false;
  sessionNumber = 0;
  for(int i = 0; i < 14; i++) { // start with segments off
    sessionValues[i] = 0;
  }
  
  numOfMinutes = 0;
  startPush = false;
  clockStart = false;
  clockInit = true;
  pushCount = 0; 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(daytime){
    // check for nightime
    int lightValue = analogRead(LightSensor);
    if (lightValue < lightThreshold){
      daytime = false;
    }

    // allow user to browse programs
    int dialNumber = analogRead(dial);
    int programNumber = rotaryToDigit(dialNumber);

    // allow user to choose a program
    int startCondition = digitalRead(startButton);
    int sessionVal = 0;
    if(startCondition){
      switch (programNumber) {
        case 0:    
          Serial.println("You Have Chosen Routine 0");
          startPush = true;
          pushCount = 0;
          sessionVal = pushupRoutine();
          sessionValues[sessionNumber] = sessionVal;
          sessionNumber++;
          break;
        case 1:    
          Serial.println("You Have Chosen Routine 1");
          break;
        case 2:    
          Serial.println("You Have Chosen Routine 2");
          break;
        default:
          Serial.println("default");
          break;
      }
    } 
  }
}

int pushupRoutine(void)
{
  int routineLength = 1;
  
  int threshold = 10;
  int resetAmount = 100;
  bool run = true;
  while(run){
    
    if(numOfMinutes == routineLength){
      run = false;
    }

    int stopCondition = digitalRead(stopButton);
    if(stopCondition){
      Serial.println("end");
      run = false;
    }

    long distance = (ultrasonic.MeasureInInches()*2.54);
    //Serial.println(distance);
    if(distance < threshold){
      pushCount++;
      playTone(1014, 300);
      delay(resetAmount);
    }
    delay(1); // delay in between reads for stability
  }
  startPush = false;
  clockInit = true;
  tm1637.clearDisplay();
  return pushCount;
}
