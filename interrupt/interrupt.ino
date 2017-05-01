int ptPin = 0;
int ledPin = A5;

volatile int state = LOW;

void setup()
{
  pinMode(ledPin, OUTPUT);
  attachInterrupt(ptPin, stateChange, CHANGE);
}

void loop()
{
}

void stateChange()
{
  state = !state;
  digitalWrite(ledPin, state);
}

