Rpm rpm (2, 3);


void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  TinyWireM.begin();
  delay (1000);
}

void loop()
{
  rpm.update();  
}





