#include "lib/Color.h"

void setup() {
    pinMode(Color::R, OUTPUT);
    pinMode(Color::G, OUTPUT);
    pinMode(Color::B, OUTPUT);

    Serial.begin(9600);
    while (!Serial) {}
    Serial.write("Hello Controller");

    Color::set(50, 0, 0);
    delay(300);
    Color::set(0, 50, 0);
    delay(300);
    Color::set(0, 0, 50);
    delay(300);
    Color::set(0,0,0);
}

void loop() {

}

void serialEvent() {
    if (Serial.available() < 4) { return; }
    switch (Serial.read())
    {
        case 0:
            Color::set(Serial.read(), Serial.read(), Serial.read());
            break;
        default:
            Color::error();
            break;
    }
}