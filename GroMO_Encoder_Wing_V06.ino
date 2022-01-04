/**
GroMO Encoder Wing V06
Arduino/Genuino Micro
Writed by Jeremy Dufeux
Licence Creative Commons (CC BY-SA 4.0)
https://creativecommons.org/licenses/by-sa/4.0/
**/

#include <Encoder.h>
#include <AbsMouse.h>
#include <EEPROM.h>

Encoder enc1(0, 1);
Encoder enc2(2, 3);
Encoder enc3(4, 5);
Encoder enc4(6, 7);

int pinBEnc1 = 15;
int pinBEnc2 = 14;
int pinBEnc3 = 16;
int pinBEnc4 = 10;

bool BEnc1Pushed = false;
bool BEnc2Pushed = false;
bool BEnc3Pushed = false;
bool BEnc4Pushed = false;

long oldPos1  = -999;
long oldPos2  = -999;
long oldPos3  = -999;
long oldPos4  = -999;

long newPos1 = 0;
long newPos2 = 0;
long newPos3 = 0;
long newPos4 = 0;

int x1 = 0;
int x2 = 0;
int x3 = 0;
int x4 = 0;
int y = 0;

bool enterSetupMode = false;
bool isSetupMode = false;
bool setupX1 = false;
bool setupX4 = false;

int setupX = 0;
int setupY = 0;

int scrollValue = -255;
int scrollBackValue = 255;

int horizontalScrollValue = 0;

int delayAmount = 30;

void setup() 
{
  Serial.begin(9600);
  //while (!Serial) ;
  Serial.println("GroMO Encoder Wing started!");
  AbsMouse.init(1920, 1080);

  pinMode(pinBEnc1, INPUT_PULLUP);  
  pinMode(pinBEnc2, INPUT_PULLUP);  
  pinMode(pinBEnc3, INPUT_PULLUP);  
  pinMode(pinBEnc4, INPUT_PULLUP);  

  checkEEPROM();
}

void loop() 
{
  newPos1 = enc1.read()/4;
  newPos2 = enc2.read()/4;
  newPos3 = enc3.read()/4;
  newPos4 = enc4.read()/4;

  if(isSetupMode)
  {
    setupMode();
  }
  else
  {
    encoderAction();
  }
  
  checkButtons();
}

void updateX2X3()
{
  x2 = x1+((x4-x1)/3);
  x3 = x1+(2*((x4-x1)/3));
}
