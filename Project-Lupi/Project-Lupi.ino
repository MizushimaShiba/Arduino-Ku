#define DHTPIN 4
#define DHTTYPE DHT22
#include <DHT.h>
#include <ArduinoJson.h>
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  StaticJsonDocument<200> object;
  object["humidity"] = String(dht.readHumidity()) + " %";
  object["temperature"] = String(dht.readTemperature()) + " °C";

  serializeJsonPretty(object, Serial);

  delay(1000);

}
