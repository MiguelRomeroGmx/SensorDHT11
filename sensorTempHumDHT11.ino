#include <DHT11.h>

int pin=2;
DHT11 dht11(pin);
const int sensorPin = A0;

void setup()
   {
       Serial.begin(9600);
   }

void loop()
   {
       float humedadT = analogRead(sensorPin);
       float humedad = (1 - (humedadT/1023))*100;
       int err;
       float temp, hum;
       if((err = dht11.read(hum, temp)) == 0)    // Si devuelve 0 es que ha leido bien
          {
             Serial.print("Temperatura: ");
             Serial.print(temp);
             Serial.print("°C ");
             Serial.print(" Humedad Relativa: ");
             Serial.print(hum);
             Serial.print("% ");
             Serial.print(" Humedad Suelo: ");
             Serial.print(humedad);
             Serial.print("% ");
             Serial.println();
          }
       else
          {
             Serial.println();
             Serial.print("Error Num :");
             Serial.print(err);
             Serial.println();
          }
       delay(1000);            // solo lee una vez por segundo
   }