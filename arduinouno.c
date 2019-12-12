#include "dht.h"
#define dht_apin A0
dht DHT;


//Arduino code
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial s(5, 6);
// MASTER

// Include the required Wire library for I2C<br>#include
int x = 0;
bool estoySentado = false;

// pin
int pirState = LOW;
const int PIRPin = 7;
int val = 0;
void setup() {
  s.begin(9600);
  // Start the I2C Bus as Master
  Serial.begin(9600);
  pinMode(PIRPin, INPUT);

}


String sensorMovimientoLuz() {
  String resultado = "";
  if (analogRead(3) <= 11) {
    estoySentado = true;
    resultado = "OSCURO";


  }
  else {
    estoySentado = false;
    resultado = "HAYLUZ";

  }
  return resultado;
}
String sensorMovimiento() {
  String resultado = "";
  val = digitalRead(PIRPin);

  if (val == HIGH)   //si está activado
  {


    resultado = "MOVIENDO";
    pirState = HIGH;

  }
  else   //si esta desactivado
  {


    resultado = "NO MOVIENDO";
    pirState = LOW;

  }
  return resultado;
}
String sensorTemperatura() {
  String resultado;
  DHT.read11(dht_apin);

  /*Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");

    Serial.println("C  ");*/
  resultado = "TEMP" + String(DHT.temperature);
  return resultado;
}
String todo;




void loop() {

  todo = String(sensorTemperatura() + "   " + sensorMovimiento() + "   " + sensorMovimientoLuz());
  Serial.println(todo);


  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["temperatura"] = sensorTemperatura();
  root["movimiento"] = sensorMovimiento();
  root["luz"] = sensorMovimientoLuz();

  if (s.available() > 0)
  {
    root.printTo(s);
  }


  delay(500);
}