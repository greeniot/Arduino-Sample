#include "Ultrasonic.h"

#define TRIGGER         12
#define ECHO            11

#define DISPLAY_A       8
#define DISPLAY_B       7
#define DISPLAY_C       6
#define DISPLAY_D       5
#define DISPLAY_E       4
#define DISPLAY_F       3
#define DISPLAY_G       2

#define DISPLAY_LEFT    9
#define DISPLAY_RIGHT   10

Ultrasonic ultrasonic(TRIGGER, ECHO);

int ports[7] = {DISPLAY_A, DISPLAY_B, DISPLAY_C, DISPLAY_D,
                DISPLAY_E, DISPLAY_F, DISPLAY_G};

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

    pinMode(DISPLAY_LEFT, OUTPUT);
    pinMode(DISPLAY_RIGHT, OUTPUT);

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
            digitalWrite(DISPLAY_LEFT, HIGH);
            digitalWrite(DISPLAY_RIGHT, LOW);
            show(dist / 10);
        } else {
            digitalWrite(DISPLAY_LEFT, LOW);
            digitalWrite(DISPLAY_RIGHT, HIGH);
            show(dist % 10);
        }
        select = !select;
        delay(10);
    }
}

