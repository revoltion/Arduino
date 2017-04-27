#include <Ethernet.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <dht11.h>

dht11 DHT11;

#define DHT11PIN 2

byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress server_addr(192,168,1,104);
char user[] = "root";
char password[] = "raspberry";

char query[128];

EthernetClient client;
MySQL_Connection conn((Client *)&client);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  outputTemperature();
  writeData();
}

void outputTemperature()
{
  int chk = DHT11.read(DHT11PIN);

  Serial.print("Temperature (oC): ");
  Serial.println((float)DHT11.temperature, 0);
}

void writeData()
{
  while (!Serial);
  Ethernet.begin(mac_addr);
  Serial.println("Connecting...");
  if (conn.connect(server_addr, 3306, user, password))
  {
    delay(1000);

    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);

//  dtostrf(50.125, 1, 1, temperature);
    sprintf(query, "INSERT INTO arduino.test VALUES (NULL, %hi, %hi, NULL)", DHT11.temperature, DHT11.humidity);

    cur_mem->execute(query);

    delete cur_mem;
    Serial.println("Data recorded.");
  }
  else
  {
    Serial.println("Connection failed.");
  }
  conn.close();
}

