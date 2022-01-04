void checkButtons()
{
  if(!digitalRead(pinBEnc1) && !BEnc1Pushed)
  {
    Serial.println("Encoder 1 pushed");
    BEnc1Pushed = true;
    if(!isSetupMode)
    {
      AbsMouse.move(x1, y); 
      AbsMouse.press(); 
    }
  }
  else if(digitalRead(pinBEnc1) && BEnc1Pushed)
  {
    Serial.println("Encoder 1 released");
    BEnc1Pushed = false;
    if(!isSetupMode)
    {
      AbsMouse.move(x1, y); 
      AbsMouse.press(); 
      AbsMouse.release(); 
      horizontalScrollValue = 0;
    }
  }
  if(!digitalRead(pinBEnc2) && !BEnc2Pushed)
  {
    Serial.println("Encoder 2 pushed");
    BEnc2Pushed = true;
    if(!isSetupMode)
    {
      AbsMouse.move(x2, y); 
      AbsMouse.press(); 
    }
  }
  else if(digitalRead(pinBEnc2) && BEnc2Pushed)
  {
    Serial.println("Encoder 2 released");
    BEnc2Pushed = false;
    if(!isSetupMode)
    {    
      AbsMouse.move(x2, y); 
      AbsMouse.press(); 
      AbsMouse.release(); 
      horizontalScrollValue = 0;
    }
  }
  if(!digitalRead(pinBEnc3) && !BEnc3Pushed)
  {
    Serial.println("Encoder 3 pushed");
    BEnc3Pushed = true;
    if(!isSetupMode)
    {
      AbsMouse.move(x3, y); 
      AbsMouse.press(); 
    }
  }
  else if(digitalRead(pinBEnc3) && BEnc3Pushed)
  {
    Serial.println("Encoder 3 released");
    BEnc3Pushed = false;
    if(!isSetupMode)
    {
      AbsMouse.move(x3, y); 
      AbsMouse.press(); 
      AbsMouse.release(); 
      horizontalScrollValue = 0;
    }
  }
  if(!digitalRead(pinBEnc4) && !BEnc4Pushed)
  {
    Serial.println("Encoder 4 pushed");
    BEnc4Pushed = true;
    if(!isSetupMode)
    {
      AbsMouse.move(x4, y); 
      AbsMouse.press(); 
    }
  }
  else if(digitalRead(pinBEnc4) && BEnc4Pushed)
  {
    Serial.println("Encoder 4 released");
    BEnc4Pushed = false;
    if(!isSetupMode)
    {
      AbsMouse.move(x4, y); 
      AbsMouse.press(); 
      AbsMouse.release(); 
      horizontalScrollValue = 0;
    }
  }

  if(BEnc1Pushed && BEnc2Pushed && BEnc3Pushed && BEnc4Pushed && !isSetupMode && !enterSetupMode)
  {
    AbsMouse.release(); 
    Serial.println("Mouse released");
    enterSetupMode = true;
    setupX1 = false;
    setupX4 = false;
    Serial.println("Enter setupMode");
  }
  if(!BEnc1Pushed && !BEnc2Pushed && !BEnc3Pushed && !BEnc4Pushed && enterSetupMode)
  {
    isSetupMode = true;
    enterSetupMode = false;
    Serial.println("Is setupMode");
  }
}
