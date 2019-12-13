byte knop;
void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() >0) {
    knop=Serial.read();
    if (knop=='1') {
      digitalWrite(13,1);  
    }
    if (knop=='0') {
      digitalWrite(13,0);  
    }
  }
  delay(5);
}
