#include <iarduino_RTC.h>

iarduino_RTC time(RTC_DS1302,6,8,7);  // для модуля DS1302 - RST, CLK, DAT
// iarduino_RTC time(RTC_DS1307);       // для модуля DS1307 с i2C
// iarduino_RTC timeRTC_DS3231);        // для модуля DS3231 с i2C

void setup() {
   delay(300);
   Serial.begin(9600);
   time.begin();
   time.settime(0, 30, 18, 12, 6, 20, 5); // 0  сек, 30 мин, 18 часов, 12, июня, 2020, четверг
}

void loop() {
   // если прошла 1 секунда выводим время
   if (millis() % 1000 == 0) {
      Serial.println(time.gettime("d-m-Y, H:i:s, D"));
      delay(500);
   }
}
