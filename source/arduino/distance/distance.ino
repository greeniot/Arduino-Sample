#include "Ultrasonic.h"

#define TRIGGER         11
#define ECHO            12

Ultrasonic ultrasonic(TRIGGER, ECHO);

int ports[7] = {2, 3, 4, 5, 6, 7, 8};

int leds[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                   {0, 1, 1, 0, 0, 0, 0},
                   {1, 1, 0, 1, 1, 0, 1},
                   {1, 1, 1, 1, 0, 0, 1},
                   {0, 1, 1, 0, 0, 1, 1},
                   {1, 0, 1, 1, 0, 1, 1},
                   {1, 0, 1, 1, 1, 1, 1},
                   {1, 1, 1, 0, 0, 0, 0},
                   {1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 0, 1, 1}};

void setup() {
    for (int i = 0; i < 7; i++) {
        pinMode(ports[i], OUTPUT);
    }

    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);

    Serial.begin(9600);
}

void show(int x) {
    for (int i = 0; i < 7; i++) {
        digitalWrite(ports[i], leds[x][i] ? HIGH : LOW);
    }
}


int select = 0;

void loop() {
    int dist = ultrasonic.Ranging(CM);

    Serial.println(dist);

    for (int i = 0; i < 10; i++) {
        if (select) {
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            show(dist / 10);
        } else {
            digitalWrite(9, LOW);
            digitalWrite(10, HIGH);
            show(dist % 10);
        }
        select = !select;
        delay(10);
    }
}

