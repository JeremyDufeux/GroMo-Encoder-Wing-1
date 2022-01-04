void encoderAction()
{
  if (newPos1 != oldPos1) 
  {
    if(newPos1 > oldPos1)
    {
      Serial.print("Encoder 1: Clockwise ");
      Serial.println(newPos1); 
      if(BEnc1Pushed)
      {
        horizontalScrollValue+=1;
        AbsMouse.move(x1+horizontalScrollValue, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollValue);   
      }     
      else
      {
        AbsMouse.move(x1, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollValue);  
      }
    }
    else
    {
      Serial.print("Encoder 1: Anticlockwise ");
      Serial.println(newPos1);  
      if(BEnc1Pushed)
      {
        horizontalScrollValue-=1;
        AbsMouse.move(x1+horizontalScrollValue, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollBackValue);   
      }     
      else
      {
        AbsMouse.move(x1, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollBackValue);  
      }
      
    }
    oldPos1 = newPos1;
  }
  if (newPos2 != oldPos2) 
  {
    if(newPos2 > oldPos2)
    {
      Serial.print("Encoder 2: Clockwise ");
      Serial.println(newPos2);    
      if(BEnc2Pushed)
      {
        horizontalScrollValue+=1;
        AbsMouse.move(x2+horizontalScrollValue, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollValue);   
      }     
      else
      {
        AbsMouse.move(x2, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollValue);  
      }
    }
    else
    {
      Serial.print("Encoder 2: Anticlockwise ");
      Serial.println(newPos2);   
      if(BEnc2Pushed)
      {
        horizontalScrollValue-=1;
        AbsMouse.move(x2+horizontalScrollValue, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollBackValue);   
      }     
      else
      {
        AbsMouse.move(x2, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollBackValue);  
      }
    }
    oldPos2 = newPos2;
  }
  if (newPos3 != oldPos3) 
  {
    if(newPos3 > oldPos3)
    {
      Serial.print("Encoder 3: Clockwise ");
      Serial.println(newPos3);  
      if(BEnc3Pushed)
      {
        horizontalScrollValue+=1;
        AbsMouse.move(x3+horizontalScrollValue, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollValue);   
      }     
      else
      {
        AbsMouse.move(x3, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollValue);  
      }  
    }
    else
    {
      Serial.print("Encoder 3: Anticlockwise ");
      Serial.println(newPos3);   
      if(BEnc3Pushed)
      {
        horizontalScrollValue-=1;
        AbsMouse.move(x3+horizontalScrollValue, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollBackValue);   
      }     
      else
      {
        AbsMouse.move(x3, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollBackValue);  
      }
    }
    oldPos3 = newPos3;
  }
  if (newPos4 != oldPos4) 
  {
    if(newPos4 > oldPos4)
    {
      Serial.print("Encoder 4: Clockwise ");
      Serial.println(newPos4);   
      if(BEnc4Pushed)
      {
        horizontalScrollValue+=1;
        AbsMouse.move(x4+horizontalScrollValue, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollValue);   
      }     
      else
      {
        AbsMouse.move(x4, y);
        delay(delayAmount);
        AbsMouse.scroll(scrollValue);  
      } 
    }
    else
    {
      Serial.print("Encoder 4: Anticlockwise ");
      Serial.println(newPos4);  
      if(BEnc4Pushed)
      {
        horizontalScrollValue-=1;
        AbsMouse.move(x4+horizontalScrollValue, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollBackValue);   
      }     
      else
      {
        AbsMouse.move(x4, y); 
        delay(delayAmount);
        AbsMouse.scroll(scrollBackValue);  
      }
    }
    oldPos4 = newPos4;
  }
}

