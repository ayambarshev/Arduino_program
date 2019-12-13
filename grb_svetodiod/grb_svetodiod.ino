const byte rPin = 5;
const byte gPin = 3;
const byte bPin = 2;
const int dela = 2000;

void setup() {
    pinMode( rPin, OUTPUT );
    pinMode( gPin, OUTPUT );
    pinMode( bPin, OUTPUT );
}

void loop() {
    // красный
    digitalWrite( rPin, HIGH );
    delay( dela );
    // красно-зеленый
    digitalWrite( gPin, HIGH );
    delay( dela );
    // зеленый
    digitalWrite( rPin, LOW );
    delay( dela );
    // сине-зеленый
    digitalWrite( bPin, HIGH );
    delay( dela );
    // белый
    digitalWrite( rPin, HIGH );
    delay( dela );
    // красно-синий
    digitalWrite( gPin, LOW );
    delay( dela );
    // синий
    digitalWrite( rPin, LOW );
    delay( dela );
    // выключены все
    digitalWrite( bPin, LOW );
    delay( dela );
}
