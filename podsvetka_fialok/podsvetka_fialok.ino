#include <iarduino_RTC.h>
#define PIN_RELAY 5 // Определяем пин, используемый для подключения реле
iarduino_RTC time(RTC_DS1302,6,8,7);  // для модуля DS1302 - RST, CLK, DAT
int a=0;
int b=0;
int c=0;
unsigned long t1=0;
unsigned long t2=0;
bool dbg=false;


void setup() {
  pinMode(PIN_RELAY, OUTPUT); // Объявляем пин реле как выход
  digitalWrite(PIN_RELAY, LOW); // Выключаем реле - посылаем высокий сигнал
  Serial.begin(9600);
  time.begin();
  //time.settime(00, 44, 13, 24, 10, 21, 0); // 50  сек, 30 мин, 18 часов, 12, июня, 2020, четверг
}


void debugprint(String x) {
  if (dbg) {
    Serial.println(x);
  } else {
    return;
  }
}


void loop() {
    time.gettime();
    a=time.Hours;
    b=time.minutes;
    c=time.seconds;
    t1=((long(a)*60+b)*60+c)*1000;
    debugprint("Сейчас " + String(a) + " часов");
    if(a>=8 and a<19) {
      digitalWrite(PIN_RELAY,HIGH); // Включаем реле - посылаем низкий уровень сигнала
      t2=19*3600000;
      debugprint(String(t2-t1));
      delay(t2-t1);
    } else {
      digitalWrite(PIN_RELAY, LOW); // Отключаем реле - посылаем высокий уровень сигнала
      if (a<8) {
        t2=8*3600000;
        debugprint(String(t2-t1));
      } else {
        t2=32*3600000;
        debugprint(String(t2-t1));
      }
      delay(t2-t1);
    }
}
