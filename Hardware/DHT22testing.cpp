#include <Arduino.h>
#include <WiFiMulti.h>
#include <DHT.h>

// put function declarations here:
//int myFunction(int, int);

#define LED_BUILTIN 2
#define WIFI_SSID "Dialog 4G"
#define WIFI_PASSWORD "J63E5AH8Q2B"

#define DHTPIN 26
#define DHTTYPE DHT22

//Wifi instance
WiFiMulti wifiMulti;

//DHT sensor instance
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(921600);
  Serial.println("DHT22 Sensor Reading!");
  pinMode(LED_BUILTIN, OUTPUT);
  dht.begin();
  delay(2000);

  //Connect to WiFi 
  // wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);
  // while(wifiMulti.run() != WL_CONNECTED){
  //   delay(100);
  // }
  // Serial.println("WiFi connected");
}

void loop() {
  // put your main code here, to run repeatedly:
  // delay(100);
  // digitalWrite(LED_BUILTIN, WiFi.status() == WL_CONNECTED); // LED on if wifi is connected
  //Serial.println("Hello, World loop!");

  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  if(isnan(temp) || isnan(humidity)){
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("C, Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

// put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }