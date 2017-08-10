Rpm rpm (2, 3);

void setup()
{
  TinyWireM.begin();
  delay (1000);
}

void loop()
{
  rpm.update();  
}





