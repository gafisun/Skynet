// =================== ДРУГОЕ =================

#include <Adafruit_MLX90614.h>
#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

MAX30105 particleSensor;
#include <Adafruit_MLX90614.h>
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
//const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
//byte rates[RATE_SIZE]; //Array of heart rates
//byte rateSpot = 0;
//long lastBeat = 0; //Time at which the last beat occurred
//
//float beatsPerMinute;
//int beatAvg;
//Adafruit_MLX90614 mlx = Adafruit_MLX90614();
//  =============== ДРУГОЕ ==================

// ============ OLED =============
#include <GyverOLED.h>
GyverOLED<SSD1306_128x64, OLED_BUFFER> oled; // Настройка OLED экрана
// ============ OLED =============

// ================== RFID ================
#include <EEPROM.h>     // We are going to read and write PICC's UIDs from/to EEPROM
#include <MFRC522.h> // Подключение библиотеки под  RFID модуль
#include <SPI.h>

constexpr uint8_t RST_PIN = 0;          // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = 2;         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

byte storedCard[4];   // Stores an ID read from EEPROM
byte readCard[4];   // Stores scanned ID read from RFID Module
byte masterCard[4];   // Stores master card's ID read from EEPROM
// ============ RFID =============

///////////////////////////////////////// Setup ///////////////////////////////////
void setup() {
// ============== Protocol Configuration =============
    Serial.begin(9600); // Старт монитора
// ============== Protocol Configuration =============

// ====================== RFID-модуль ==================
    SPI.begin();      // Init SPI bus. MFRC522 Hardware uses SPI protocol
    mfrc522.PCD_Init();    // Initialize MFRC522 Hardware
    mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
    Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
// ====================== RFID-модуль ================== 
 
// ================= СИСТЕМА ИНДЕНТИФИКАЦИИ =============
   Serial.println(F("Access Control Example v0.1"));   // For debugging purposes
   ShowReaderDetails();  // Show details of PCD - MFRC522 Card Reader details
// ================= СИСТЕМА ИНДЕНТИФИКАЦИИ ==============

// ================= ДАТЧИК ПУЛЬСА  =================
  //  mlx.begin();
//
//    if (particleSensor.begin(Wire, I2C_SPEED_FAST) == false) //Use default I2C port, 400kHz speed
//    {
//        Serial.println("MAX30105 was not found. Please check wiring/power. ");
//        while (1);
//    }



//    particleSensor.setup(); //Configure sensor with these settings
//    particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
//    particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
// ================= ДАТЧИК ПУЛЬСА ================= 

// ======================= ДИСПЛЕЙ ===================================
  oled.init(); // Инициализация олед дисплея


  oled.clear(); // Очистка OLED-дисплея
  oled.update(); // Отправка сигнала на oled дисплей

  oled.home();

  oled.setScale(2);
  oled.autoPrintln(false);
  oled.print("Temperat");
  oled.update();
// ======================= ДИСПЛЕЙ ===================================

}

///////////////////////////////////////// Main Loop ///////////////////////////////////
void loop() {
  
// =============== ВЫВОД ТЕМПЕРАТУРЫ =========================
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
// =============== ВЫВОД ТЕМПЕРАТУРЫ =========================

// ====================== RFID-модуль ==================  
// Look for new cards Поиск новых карт
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  
// Select one of the cards Выбор карты
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
    // Dump debug info about the card; PICC_HaltA() is automatically called 
   mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
 // ====================== RFID-модуль ==================
 
}
