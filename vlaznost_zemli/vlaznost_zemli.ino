// Датчик влажности почвы
// http://3d-diy.ru

// контакт подключения аналогового выхода датчика
int aPin=A0;
// переменная для сохранения значения датчика
int avalue=0;
// значение полного полива
int minvalue=220;
// значение критической сухости
int maxvalue=600;

void setup()
{
if(A0<220)
{pinMode(13,1);
delay(1000);
pinMode(13,0);
}
Serial.print(minvalue);
Serial.print(maxvalue);
Serial.println();
delay(1000);
}
