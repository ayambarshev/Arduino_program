#include <iarduino_RTC.h>
uint32_t myTimer1;
unsigned long td1=0;
unsigned long td2=0;
unsigned long ta1=0;
unsigned long ta2=0;

iarduino_RTC time(RTC_DS1302,6,8,7);  // для модуля DS1302 - RST, CLK, DAT

void setup() {
  Serial.begin(9600);
  time.begin();
  time.settime(0, 30, 22, 24, 10, 21, 0); // 0  сек, 30 мин, 18 часов, 12, июня, 2020, четверг
}

void loop() {
  myTimer1=millis();
  

}
