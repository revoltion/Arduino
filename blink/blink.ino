// 翠园中学机器编程社
int ledPin = 13;

void setup ()
{
    pinMode(ledPin, OUTPUT);
}

void loop ()
{
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(500);
}
