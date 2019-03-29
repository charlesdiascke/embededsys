#include "Seeed_BME280.h"
#include <Wire.h>

BME280 bme280;
int seuil=40; // switch on the led of the Arduino if the Humidity is under the 'seuil'
int seuilWaterLvl=100;
int index=1;  // index for the abscissa of the graph


void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  while (!Serial) ;

  Serial.print("Temp");
  Serial.print(",");
  Serial.print("Humidity");
  Serial.print(",");
  Serial.println("WaterLvl");
  
  if(!bme280.init()){
    Serial.println("Device error!");
  }

  
  
  
  
}

void loop()
{
  int humidity;

  //x index of the graph
  Serial.print(index);
  Serial.print(",");
  index++;

  
  //get and print temperatures
  Serial.print(bme280.getTemperature());
  Serial.print(",");


  //get, print humidity data and switch on the led of the Arduino if the Humidity is under the 'seuil'
  humidity=bme280.getHumidity();
  Serial.print(humidity);
  Serial.print(",");
   if(humidity < seuil)
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  }

  //get and print water lvl data and switch on the led of the Arduino if the water lvl is under the 'seuil'
  int sensor=analogRead(A0); // Incoming analog signal read and appointed sensor
  Serial.println(sensor);   //Wrote serial port
  
  if(sensor < seuilWaterLvl)
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  }
 


  delay(1000);
}
