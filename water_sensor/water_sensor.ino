// https://xn--18-6kcdusowgbt1a4b.xn--p1ai/%D0%B4%D0%B0%D1%82%D1%87%D0%B8%D0%BA-%D0%B2%D0%BE%D0%B4%D1%8B-%D0%B0%D1%80%D0%B4%D1%83%D0%B8%D0%BD%D0%BE/#3
int water; // присваиваем имя для значений с аналогового входа A0

void setup() {
   pinMode(A0, INPUT);  // к входу A0 подключим датчик (англ. «intput»)
   Serial.begin(9600);  // подключаем монитор порта
}

void loop() {
   water = analogRead(A0); // переменная "water" находится в интервале от 0 до 1023

   Serial.println(water); // выводим значение датчика на монитор
   delay(1000);           // задержка в одну секунду
}
