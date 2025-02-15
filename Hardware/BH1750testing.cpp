#include <Arduino.h>
#include <WiFiMulti.h>
#include <Wire.h>
#include <BH1750_WE.h>


// put function declarations here:
//int myFunction(int, int);

#define LED_BUILTIN 2
#define WIFI_SSID "Dialog 4G"
#define WIFI_PASSWORD "J63E5AH8Q2B"

#define BH1750_I2C_ADDRESS 0x23  //I2C address of BH1750

//Wifi instance
WiFiMulti wifiMulti;

//BH1750 sensor object
TwoWire I2Cwire = TwoWire(0);
BH1750_WE lightMeter(&I2Cwire, BH1750_I2C_ADDRESS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(921600);

  I2Cwire.begin(21, 22); //SDA, SCL I2C pins
  // Initialize BH1750 Sensor
  if(!lightMeter.init()){
    Serial.println("BH1750 Sensor not found!");
    while (1);
  }
  Serial.println("BH1750 Sensor Initialized!");
  //lightMeter.setMode();
  pinMode(LED_BUILTIN, OUTPUT);
  

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

  float lux = lightMeter.getLux();
  Serial.print("Light Intensity: ");
  Serial.print(lux);
  Serial.println(" lx");

  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

// put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }