String inString = "";

int currentColor = 0;
int red, green, blue = 0;

int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int insPin = 13;

void setup ()
{
    Serial.begin(9600);
    while(!Serial)
    {
        ;
    }
    Serial.println("\n\nString toInt()RGB:");

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(insPin, OUTPUT);

    digitalWrite(insPin, HIGH);
}

void loop ()
{
    int inChar;

    if(Serial.available() > 0)
    {
        inChar = Serial.read();
    }

    if(isDigit(inChar))
    {
        inString += (char)inChar;
    }
    if(inChar == ',')
    {
        switch(currentColor)
        {
            case 0:
                red = inString.toInt();
                inString = "";
                break;
            case 1:
                green = inString.toInt();
                inString = "";
                break;
        }
        currentColor++;
    }
    if(inChar == '\r')
    {
        blue = inString.toInt();

        analogWrite(redPin, 255 - red);
        analogWrite(greenPin, 255 - green);
        analogWrite(bluePin, 255 - blue);

        Serial.print("Red:");
        Serial.println(red);
        Serial.print("Green:");
        Serial.println(green);
        Serial.print("Blue:");
        Serial.println(blue);

        inString = "";

        currentColor = 0;
    }
}
