#include "lib/Color.h"

Color color = Color();

void setup() {
    pinMode(Color::R, OUTPUT);
    pinMode(Color::G, OUTPUT);
    pinMode(Color::B, OUTPUT);

    Serial.begin(9600);
    while (!Serial) {}
    Serial.write("Hello Controller");

    color.set(20, 20, 20);
    delay(300);
    color.set(0, 0, 0);
}

void loop() {

}

void serialEvent() {
    switch (Serial.read())
    {
        case 0:
            while (Serial.available() < 3) {}
            color.set(Serial.read(), Serial.read(), Serial.read());
            break;

        case 1:
            while (Serial.available() < 4) {}
            color.fade(Serial.read(), Serial.read(), Serial.read(), Serial.read());
            break;
            
        default:
            color.error();
            break;
    }
}