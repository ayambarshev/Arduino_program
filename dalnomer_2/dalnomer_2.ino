// URL: https://arduinomaster.ru/datchiki-arduino/ultrazvukovoj-dalnomer-hc-sr04/

#define PIN_TRIG 12
#define PIN_ECHO 11
long duration, cm;
void setup() {
  // Инициализируем взаимодействие по последовательному порту
  Serial.begin (9600);
  //Определяем вводы и выводы
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(10,OUTPUT);
}
void loop() {
  // Сначала генерируем короткий импульс длительностью 2-5 микросекунд.
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);
  // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц.
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  //  Время задержки акустического сигнала на эхолокаторе.
  duration = pulseIn(PIN_ECHO, HIGH);
  // Теперь осталось преобразовать время в расстояние
  cm = (duration / 2 / 29.1);
  Serial.print(cm);
  Serial.print("до предмета");
  if(cm<20){
    digitalWrite(10,1);
    delay(10);
    digitalWrite(10,0);
  }
  // Задержка между измерениями для корректной работы скеча
  delay(0);
}
  
