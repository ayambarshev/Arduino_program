#include <IRremote.h>  // подключаем библиотеку IRremote

int RECV_PIN = 11; // S к 11-му пину
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
Serial.begin(9600);
irrecv.enableIRIn(); // начинаем прием
}

void loop() {
if (irrecv.decode(&results)) {
Serial.println(results.value, HEX);
irrecv.resume(); // принимаем следующее значение
}
}
