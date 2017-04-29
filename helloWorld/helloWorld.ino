#include <LiquidCrystal.h>
#include <dht11.h>

dht11  DHT11;

#define DHTPin A0
int ledPin = 3;
int n = 0;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12, 13);

void setup() 
{
  lcd.begin(16, 2);
  lcd.print("Temperature Monitoring");
  delay(2000);
  for (int positionCounter = 0; positionCounter < 13; positionCounter++)
  {
    lcd.scrollDisplayLeft();
    delay(50);
  }
  lcd.setCursor(14, 1);
  lcd.print("Loading...");

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  delay(3000);
  digitalWrite(ledPin, LOW);

  pinMode(5,INPUT);
  pinMode(6,INPUT);
}

void loop() 
{
  int chk = DHT11.read(DHTPin);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature is ");
  lcd.setCursor(0, 1);
  lcd.print((float)DHT11.temperature, 0);
  lcd.print((char)223);
  lcd.print("C");
  delay(300);

  changeLight();
}

void changeLight ()
{
  int keyVal = analogRead(A1);

  if (keyVal >= 1000 && keyVal <= 1200)
  { 
    n = n + 5;
    if (n >= 255) 
    {
      n = 255;
    }
    analogWrite(3, n);
    delay (100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Light level is");
    lcd.setCursor(0, 1);
    lcd.print((float)n, 0);
    delay(1500);
  }

  if (keyVal >= 700 && keyVal <= 800)
  {
    n = n - 5;
    if (n<=0) 
    {
     n=0;
    }
    analogWrite(3, n);
    delay (100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Light level is");
    lcd.setCursor(0, 1);
    lcd.print((float)n, 0);
    delay(1500);
  }
}


