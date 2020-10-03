//  Датчик уровня воды
//  http://3d-diy.ru

// контакт подключения аналогового выхода датчика
int aPin=A0;
// контакт  подключения вывода реле
int soundPin=11;
// частота звукового сигнала
int freq[3]={587,366,193};
// переменная для сохранения значения датчика
int avalue=0;
// значение уровней
int levels[3]={700,600,300};
// текущий уровень
int level=0;

void setup()
{
// инициализация последовательного порта
Serial.begin(9600);
// настройка выводов индикации светодиодов
// в режим OUTPUT
pinMode(soundPin,OUTPUT);
}

void loop()
{
// получение значения с аналогового вывода датчика
avalue=analogRead(aPin);
// вывод значения в монитор последовательного порта Arduino
Serial.print("avalue=");Serial.println(avalue);
// вывод звука различной частоты для разных уровней погружения
if(avalue>levels[0])
tone(soundPin,freq[0],2000);
else if(avalue>levels[1])
tone(soundPin,freq[1],2000);
else if(avalue>levels[2])
tone(soundPin,freq[2],2000);
else
noTone(soundPin);
// пауза перед следующим получением значения 1000 мс
delay(1000);
}
