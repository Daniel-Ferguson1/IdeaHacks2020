#include "Ultrasonic.h"
#include "TM1637.h"


byte seven_segment_digits[10][7] = { { 0,0,0,0,0,0,1 }, // display '0'
                                     { 1,0,0,1,1,1,1 }, // display '1'
                                     { 0,0,1,0,0,1,0 }, // display '2'
                                     { 0,0,0,0,1,1,0 }, // display '3'
                                     { 1,0,0,1,1,0,0 }, // display '4'
                                     { 0,1,0,0,1,0,0 }, // display '5'
                                     { 0,1,0,0,0,0,0 }, // display '6'
                                     { 0,0,0,1,1,1,1 }, // display '7'
                                     { 0,0,0,0,0,0,0 }, // display '8'
                                     { 0,0,0,1,1,0,0 }  // display '9'
                                   };



/////// Pins ////////////                                  
int ULTRASONIC_PIN = 39;
int LightSensor = 23;
int buzzerPin = 40;
int startButton = 13;
int stopButton = 17;
int dial = 24;
int segA = 31;int segB = 32;int segC = 33;int segD = 34;
int segE = 35;int segF = 36;int segG = 37;int segDot = 38;
#define CLK 9 //pins definitions for TM1637 and can be changed to other ports
#define DIO 10
Ultrasonic ultrasonic(ULTRASONIC_PIN); 


int pushCount = 0; 

int incomingByte = 0;
int lightThreshold = 400;
bool clockStart = false;
bool clockInit = true;
unsigned long startTime = 0;
int8_t TimeDisp[] = {0x00,0x00,0x00,0x00};


TM1637 tm1637(CLK,DIO);

bool daytime = false;
int sessionNumber = 0;
int sessionValues[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int numOfMinutes = 0;
bool startPush = false;

void setup() {
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

//////////////////////////////
