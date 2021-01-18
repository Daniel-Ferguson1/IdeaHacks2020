



void setup() {
  // put your setup code here, to run once:
  pinMode(LightSensor, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(startButton, INPUT);
  pinMode(stopButton, INPUT_PULLDOWN);
  pinMode(dial, INPUT);

  pinMode(segA, OUTPUT); // set segment A as output
  pinMode(segB, OUTPUT); // set segment B as output
  pinMode(segC, OUTPUT); // set segment C as output
  pinMode(segD, OUTPUT); // set segment D as output
  pinMode(segE, OUTPUT); // set segment E as output
  pinMode(segF, OUTPUT); // set segment F as output
  pinMode(segG, OUTPUT); // set segment G as output
  pinMode(segDot, OUTPUT); // set dot as output
  for(int i = segA; i < segG+1; i++) { // start with segments off
    digitalWrite(i, HIGH);
  }
  digitalWrite(segDot, HIGH);  // start with the dot off

  
  Serial.begin(9600);
  //Serial.println("set1");
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if(!daytime){
    
    int lightValue = analogRead(LightSensor);
    //Serial.println(lightValue);
    if (lightValue > lightThreshold){
      Serial.println("day");
      daytime = true;
      playTone(1700, 300);
    }
     
    int pin = segA;
    byte centerLine[7] = {1,1,1,1,1,1,0};
    for (int segCount = 0; segCount < 7; segCount++) {
      digitalWrite(pin, centerLine[segCount]);
      pin++;
    }
  }
  
  delay(1); 
}

//////////////////////////////

void playTone(int tone, int duration)
{
  
  for(long i = 0; i < duration * 1000L; i += tone*2)
  {
    
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(tone);
    
  }
}

int rotaryToDigit(int val)
{
  int maxVal = 1023;
  int numDigits = 10;
  int biasedVal = maxVal - val; 
  int outInt = biasedVal/(maxVal/(numDigits-1));
  displayDigit(outInt);
  return outInt;
}

void displayDigit(int val)
{
  int pin = segA;
  for (int segCount = 0; segCount < 7; segCount++) {
    digitalWrite(pin, seven_segment_digits[val][segCount]);
    pin++;
  }
}
