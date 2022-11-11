//#include <Config.h>
#include <Firebase.h>
//#include "SD.h"
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


// conexion a firebase
#define FIREBASE_HOST "encendido-bombillo-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "kJddNlaPUUB1xp2qfFVWCXictvVrbbZORel8qNHt"
#define WIFI_SSID "SERGIOTOBAR"
#define WIFI_PASSWORD "SergioTobar"

void setup() {
  Serial.begin(9600);

  // conexion al wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);

  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  
}

int n = 0;
boolean estado = false;

void loop(){
   estado=Firebase.getBool("led");
  // handle error
  if(Firebase.failed()){
      Serial.print("no Conectado:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(500);
   // get value 
  if(estado){
    digitalWrite(2, LOW);
    Serial.print(1);  
  }
  else{
    digitalWrite(2, HIGH);
    Serial.print(0);
  }

  delay(500);
}
