
#include <GyverOLED.h>
#include <Adafruit_MLX90614.h>#include <Adafruit_MLX90614.h>
#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"
MAX30105 particleSensor;


//const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
//byte rates[RATE_SIZE]; //Array of heart rates
//byte rateSpot = 0;
//long lastBeat = 0; //Time at which the last beat occurred
//
//float beatsPerMinute;
//int beatAvg;


GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;
//Adafruit_MLX90614 mlx = Adafruit_MLX90614();



void setup() {
    Serial.begin(115200);
//
//    if (particleSensor.begin(Wire, I2C_SPEED_FAST) == false) //Use default I2C port, 400kHz speed
//    {
//        Serial.println("MAX30105 was not found. Please check wiring/power. ");
//        while (1);
//    }



//    particleSensor.setup(); //Configure sensor with these settings
//    particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
//    particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED

  oled.init();
  mlx.begin();

  oled.clear();
  oled.update();

  oled.home();

  oled.setScale(2);
  oled.autoPrintln(false);
  oled.print("Temperatur");
  oled.setScale(2);
  oled.print("e");
  oled.update();
}

void loop() {
//  oled.setCursor(0, 4);
//  oled.setScale(3);
//  oled.print(String((int)(mlx.readObjectTempC()*100)/100 ) +"."+String((int)(mlx.readObjectTempC()*100)/10%10));
//  oled.update();
//    long irValue = particleSensor.getIR();
//
//    if (checkForBeat(irValue) == true)
//    {
//        //We sensed a beat!
//        long delta = millis() - lastBeat;
//        lastBeat = millis();
//
//        beatsPerMinute = 60 / (delta / 1000.0);
//
//        if (beatsPerMinute < 255 && beatsPerMinute > 20)
//        {
//            rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
//            rateSpot %= RATE_SIZE; //Wrap variable
//
//            //Take average of readings
//            beatAvg = 0;
//            for (byte x = 0 ; x < RATE_SIZE ; x++)
//                beatAvg += rates[x];
//            beatAvg /= RATE_SIZE;
//        }
    }

}