int sensorPin = A5;    // подключаем датчик к 5 аналоговому входу
int ledPin =10;       // светодиод
int sensorValue= 0;   // данные с датчика

void setup () {
pinMode (ledPin, OUTPUT);
Serial.begin (9600);
}

void loop () {
sensorValue = analogRead (sensorPin);
digitalWrite (ledPin, HIGH);
delay (100);
digitalWrite (ledPin, LOW);
delay (100);
Serial.println (sensorValue, DEC);//выводим данные с датчика
}
