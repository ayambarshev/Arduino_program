#include <iarduino_RTC.h>

iarduino_RTC time(RTC_DS1302,6,8,7);  // для модуля DS1302 - RST, CLK, DAT

void setup() {
   delay(300);
   Serial.begin(9600);
   time.begin();
   //time.settime(0, 30, 22, 24, 10, 21, 0); // 0  сек, 30 мин, 18 часов, 12, июня, 2020, четверг
}

void loop() {
   // если прошла 1 секунда выводим время
   if (millis() % 1000 == 0) {
      Serial.println(time.gettime("d-m-Y, H:i:s, D"));
      delay(5);
   }
}
