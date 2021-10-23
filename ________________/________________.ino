#include <iarduino_RTC.h>
#define PIN_RELAY 5 // Определяем пин, используемый для подключения реле
iarduino_RTC time(RTC_DS1302,6,8,7);  // для модуля DS1302 - RST, CLK, DAT
int a=0;

void setup() {
   pinMode(PIN_RELAY, OUTPUT); // Объявляем пин реле как выход
   digitalWrite(PIN_RELAY, LOW); // Выключаем реле - посылаем высокий сигнал
   Serial.begin(9600);
   time.begin();
   time.settime(0,50,20, 22, 10, 21, 5); // 50  сек, 30 мин, 18 часов, 12, июня, 2020, четверг
}

void loop() {
    time.gettime();
    a=time.Hours;
    Serial.println(time.Hours);
    if(a==9) {
      digitalWrite(PIN_RELAY,HIGH); // Включаем реле - посылаем низкий уровень сигнала
    }
    if(a==21) {
      digitalWrite(PIN_RELAY, LOW); // Отключаем реле - посылаем высокий уровень сигнала
    }    
    delay(1000);
}
