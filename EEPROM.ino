/*
0  = EEPROM intitalised
1  = X1 byte 4
2  = X1 byte 3
3  = X1 byte 2
4  = X1 byte 1

5  = X4 byte 4
6  = X4 byte 3
7  = X4 byte 2
8  = X4 byte 1

9  = Y  byte 4
10 = Y  byte 3
11 = Y  byte 2
12 = Y  byte 1
*/

void checkEEPROM()
{
  if(EEPROM.read(0)==127)
  {
    x1 = EEPROMReadlong(1);
    x4 = EEPROMReadlong(5);
    y =  EEPROMReadlong(9);
    
    Serial.print("x1 : ");
    Serial.println(x1);
    Serial.print("x4 : ");
    Serial.println(x4);
    Serial.print("y : ");
    Serial.println(y);
    Serial.println("EEPROM readed");
  }
  else
  {
    x4 = 500;
    Serial.println("EEPROM not readed");
  }
  setupX = x1;
  setupY = y;
  updateX2X3();
}

long EEPROMReadlong(long address)
{
  long four = EEPROM.read(address);
  long three = EEPROM.read(address + 1);
  long two = EEPROM.read(address + 2);
  long one = EEPROM.read(address + 3);
  
  return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}

void EEPROMwritelong(int address, long value)
{
  byte four = (value & 0xFF);
  byte three = ((value >> 8) & 0xFF);
  byte two = ((value >> 16) & 0xFF);
  byte one = ((value >> 24) & 0xFF);
  
  EEPROM.write(address, four);
  EEPROM.write(address + 1, three);
  EEPROM.write(address + 2, two);
  EEPROM.write(address + 3, one);
}
