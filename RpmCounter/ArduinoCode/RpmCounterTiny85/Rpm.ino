class Rpm
{
  private:
    unsigned int rpmc;
    unsigned long startTime;
    long counter;
    int previous;
    static const int THRESHOLD = 5;
    int signalPin, refPin;

  public:

    Rpm (int signalp, int refp)
    {
      rpmc = 0;
      startTime = 0;
      counter = 0;
      previous = 0;
      signalPin = signalp;
      refPin = refp;
    }

    void update ()
    {
      long adelta = analogRead(signalPin) - analogRead(refPin);
            
      if (abs(adelta) < THRESHOLD) return;
      int dt = millis() - startTime;

      if (dt >= 1000)
      {
        startTime = millis();
        rpmc = counter * 60;
        counter = 0;
        sendTwoBytes(rpmc);

        if (rpmc<=0) digitalWrite(LED, HIGH);
        else digitalWrite(LED, LOW);
        return;
      }

      int v = (adelta < 0) ? 1 : 0;
      if (previous == 0 && v == 1) counter++;
      previous = v;

    }
};






