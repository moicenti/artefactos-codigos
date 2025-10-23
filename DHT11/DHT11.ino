#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  dht.begin();
  Serial.begin(9600);
}

void mostrarHumedad_Calor(){
  Serial.println();

  Serial.print("Humedad: ");
  Serial.println(dht.readHumidity(), 2);  

  Serial.print("Temperatura: ");
  Serial.println(dht.readTemperature(), 2);  
  
  delay(2000);
}

void loop(){
  mostrarHumedad_Calor();
}