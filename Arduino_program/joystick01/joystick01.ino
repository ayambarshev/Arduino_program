// ### Демонстрация роботы модуля KY-018###

// Номер пина на плате к которому будет подключен вывод "S" модуля
#define ButtonPin 2
#define SensorPin0 A0
#define SensorPin1 A1

// Переменная для хранения полученых данных с модуля
int BtnVal = 0;
int SensorVal0 = 511;
int SensorVal1 = 511;

void setup() 
  {
    // Инициализация SerialPort
    Serial.begin(9600);
    Serial.println("Start Serial Port");
  }
void loop() 
  {
    // Получаем данные с модуля
    BtnVal = digitalRead(ButtonPin);
    SensorVal0 = analogRead(SensorPin0);
    SensorVal1 = analogRead(SensorPin1);
 
    // Выводим значение полученное с модуля
    Serial.println(SensorVal0, DEC);
    Serial.println(SensorVal1, DEC);
    if (BtnVal == HIGH) {
      Serial.println("Кнопка не нажата");
    } else {
      Serial.println("Кнопка нажата");
    }
    Serial.println();
    
    // Задержка
    delay(1000);
  }
