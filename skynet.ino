 // =================== ДРУГОЕ =================
#include "heartRate.h"
//  =============== ДРУГОЕ ==================

// ============================================ САТУРАЦИЯ ============================================
#include <Wire.h> // Подключение библиотеки проводов
#include "MAX30105.h" // Подключение библиотеки для датчика сатурации
MAX30105 particleSensor; // Создания объекта "датчик температуры"
// ============================================ САТУРАЦИЯ ============================================

// ============== ТЕМПЕРАТУРА =================
#include <Adafruit_MLX90614.h> // Подключение библиотеки для датчика температуры
Adafruit_MLX90614 ml = Adafruit_MLX90614();
// ============== ТЕМПЕРАТУРА =================

// ============ OLED =============
#include <GyverOLED.h> // Подключение Библиотеки для OLED дисплея
GyverOLED<SSD1306_128x64, OLED_BUFFER> oled; // Создания объекта дисплея с нужынми характеристиками
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
if (!ml.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };

// ====================== RFID-модуль ==================
    SPI.begin();      // Init SPI bus. MFRC522 Hardware uses SPI protocol
    mfrc522.PCD_Init();    // Initialize MFRC522 Hardware 
    mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
    Serial.println("Scan PICC to see UID, SAK, type, and data blocks..."); // Печать в мониторе строки готовности RFID модуля к считыванию данных
// ====================== RFID-модуль ================== 
 
// ================= СИСТЕМА ИНДЕНТИФИКАЦИИ =============
Serial.println("Access Control Example v0.1");   // For debugging purposes
//   ShowReaderDetails();  // Show details of PCD - MFRC522 Card Reader details
// ================= СИСТЕМА ИНДЕНТИФИКАЦИИ ==============

// ======================= ДИСПЛЕЙ ===================================
  oled.init(); // Старт OLED дисплея

  oled.clear(); // Очистка OLED дисплея от прошлых команд
  oled.update(); // Обновление OLED дисплея
  
  oled.home(); // Возвращение дисплея в точку (0, 0)

  oled.setScale(2); // Размер Шрифта равен 2 единицам
  oled.autoPrintln(false); // Отключение автоматического переноса строки
  oled.print("Прив"); // Печать пробного текста
  oled.update(); // Обновление OLED дисплеяы
// ======================= ДИСПЛЕЙ ===================================

// ============================================ САТУРАЦИЯ ============================================

  //Setup to sense up to 18 inches, max LED brightness Основные константы, необходимые для подключения датчика
//  byte ledBrightness = 0xFF; //Options: 0=Off to 255=50mA Яркость светоидиода 
// byte sampleAverage = 4; //Options: 1, 2, 4, 8, 16, 32 Количество измерений, из которого выводится среднее значение
//  byte ledMode = 2; //Options: 1 = Red only, 2 = Red + IR, 3 = Red + IR + Green Режим работы датчика
// int sampleRate = 400; //Options: 50, 100, 200, 400, 800, 1000, 1600, 3200 Тестовы
//  int pulseWidth = 411; //Options: 69, 118, 215, 411 
//  int adcRange = 2048; //Options: 2048, 4096, 8192, 16384

//  particleSensor.setup(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange); //Configure sensor with these settings
// ============================================ САТУРАЦИЯ ============================================
}

///////////////////////////////////////// Main Loop ///////////////////////////////////
void loop() {
  
// =============== ВЫВОД ТЕМПЕРАТУРЫ =========================
  oled.setCursor(0, 4);
  oled.setScale(3);
oled.print(String((int)ml.readObjectTempC()));
  oled.update();
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

// ============================================ САТУРАЦИЯ ============================================

// ============================================ САТУРАЦИЯ ============================================
 
}
