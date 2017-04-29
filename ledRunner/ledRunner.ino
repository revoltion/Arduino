//翠园中学机器编程社
void setup()
{
    for (int i = 11; i < 14; i ++)
    {
        pinMode(i, OUTPUT);
    }
}

void loop()
{
    for (int i =11; i < 14; i ++)
    {
        digitalWrite(i, LOW);
        delay(200);
    }
    for (int i = 11; i < 14; i ++)
    {
        digitalWrite(i, HIGH);
        delay(200);
    }
}
