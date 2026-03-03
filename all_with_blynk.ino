#define BLYNK_TEMPLATE_ID "TMPL6jwMhGCRh"
#define BLYNK_TEMPLATE_NAME "Greenhouse Monitor"
#define BLYNK_AUTH_TOKEN "Y-ByxBmAd_QqPvRcUTstTLfUSRyknMZJ"  // Your Auth Token

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// ✅ WiFi Credentials (Update with your WiFi details)
char ssid[] = "UOC Staff";  
char pass[] = "admin106";

// ✅ Define DHT11 Sensor Pins
#define DHTPIN1 18  
#define DHTPIN2 5   
#define DHTTYPE DHT11
DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);

// ✅ Define LDR Sensor Pin
#define LDR_PIN 34  

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n✅ ESP32 is Starting...");

  // ✅ Connect to WiFi & Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // ✅ Start Sensors
  dht1.begin();
  dht2.begin();
}

void loop() {
  Blynk.run();  // ✅ Keep Blynk Connected

  // ✅ Read DHT11 Sensors
  float temp1 = dht1.readTemperature();
  float hum1 = dht1.readHumidity();
  float temp2 = dht2.readTemperature();
  float hum2 = dht2.readHumidity();

  // ✅ Read LDR Sensor
  int lightRaw = analogRead(LDR_PIN);
  int lightValue = 4095 - lightRaw;  // Inverted for better readability

  // ✅ Handle Sensor Errors
  if (isnan(temp1) || isnan(hum1)) { temp1 = 0.0; hum1 = 0.0; }
  if (isnan(temp2) || isnan(hum2)) { temp2 = 0.0; hum2 = 0.0; }

  // ✅ Send Data to Blynk
  Blynk.virtualWrite(V1, temp1);   // GH1 Temp
  Blynk.virtualWrite(V2, hum1);    // GH1 Humidity
  Blynk.virtualWrite(V3, lightValue); // LDR Light

  Serial.print("GH1 Temp: "); Serial.print(temp1);
  Serial.print("C  GH1 Hum: "); Serial.print(hum1);
  Serial.print("%  GH1 Light: "); Serial.print(lightValue);
  Serial.print(" | GH2 Temp: "); Serial.print(temp2);
  Serial.print("C  GH2 Hum: "); Serial.print(hum2);
  Serial.println("%");

  delay(2000);  // Wait before next update
}
