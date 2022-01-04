void setupMode()
{
  if (newPos1 != oldPos1) 
  {
    if(newPos1 > oldPos1)
    {
      setupX+=10;
    }
    else if (newPos1 < oldPos1)
    {
      setupX-=10; 
    }
    Serial.print("X : ");
    Serial.println(setupX);
    AbsMouse.move(setupX, setupY); 
    oldPos1 = newPos1;
  }
  
  if (newPos2 != oldPos2) 
  {
    if(newPos2 > oldPos2)
    {
      setupY+=10;
    }
    else if (newPos2 < oldPos2)
    {
      setupY-=10; 
    }
    Serial.print("Y : ");
    Serial.println(setupY);
    AbsMouse.move(setupX, setupY); 
    oldPos2 = newPos2;
  }

  if(BEnc1Pushed && !setupX1)
  {
    x1 = setupX;
    y = setupY;
    EEPROM.write(0, 127);
    EEPROMwritelong(1, x1);
    EEPROMwritelong(9, y);
    setupX1 = true;
    Serial.println("X1 Recorded");
    if(setupX4)
    {
      Serial.println("Exit SetupMode");
      updateX2X3();
      isSetupMode = false;
    }
    Serial.print("x1 : ");
    Serial.println(EEPROMReadlong(1));
    Serial.print("x4 : ");
    Serial.println(EEPROMReadlong(5));
    Serial.print("y : ");
    Serial.println(EEPROMReadlong(9));
  }
  if(BEnc4Pushed && !setupX4)
  {
    x4 = setupX;
    y = setupY;
    EEPROM.write(0, 127);
    EEPROMwritelong(5, x4);
    EEPROMwritelong(9, y);
    setupX4 = true;
    Serial.println("X4 Recorded");
    if(setupX1)
    {
      Serial.println("Exit SetupMode");
      updateX2X3();
      isSetupMode = false;
    }
    Serial.print("x1 : ");
    Serial.println(EEPROMReadlong(1));
    Serial.print("x4 : ");
    Serial.println(EEPROMReadlong(5));
    Serial.print("y : ");
    Serial.println(EEPROMReadlong(9));
  }
}

