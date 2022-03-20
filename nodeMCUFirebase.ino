#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

#define FIREBASE_HOST "" 
#define FIREBASE_AUTH "" 
#define WIFI_SSID "" 
#define WIFI_PASSWORD "" 

void setup() { 
  // Debug console
 Serial.begin(9600); 
 
 // connect to wifi. 
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
 Serial.print("connecting"); 
 while (WiFi.status() != WL_CONNECTED) { 
   Serial.print("."); 
   delay(500); 
 } 
 Serial.println(); 
 Serial.print("connected: "); 
 Serial.println(WiFi.localIP()); 
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 

 if(Firebase.failed()){
  Serial.print(Firebase.error());
 }
 else{
  Serial.print("Firebase connected");
  Firebase.setString("Senura/Value","0");
 }
} 

void loop() { 
 for(int i = 0; i <= 100; i++)
 { 
    Firebase.setInt("/Senura/Value",i);
    delay(1000);
 }
} 
