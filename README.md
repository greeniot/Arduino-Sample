# Arduino-Sample
:car: The car distance sensor using the Arduino with an ultrasonic transducer.

![CC3200 with Utrasonic Transducer](/images/cc3200_side_labeled.jpg)

* [CC3200 Code](/source/cc3200/distance/distance.ino)
* [Arduino Code](/source/arduino/distance/distance.ino)

# Introduction
In this tutorial you will learn how to built a distance sensor with the Arduino and an ultrasonic transducer.

# Parts
You will need the following parts for this tutorial:
* An ultrasonic transducer,
* two seven-segment displays,
* an Arduino Nano,
* two logic-level n-channel MOSFETs, and
* two 220Ω resistors.

#### Ultrasonic Transducer
The ultrasonic transducer is the main component of the setup. It works exactly the same way like the orientation system of bats. It emits ultrasound which is reflected back by an object. The time between the emission and the reception of the reflection can then be used to calculate the distance to the reflecting object.

The ultrasonic transducer provides four different pins. Two pins for the power supply, GND and VCC, a pin for triggering an ultrasound emission, and a pin which signals when the reflection has been received.

![Utrasonic Transducer](/images/transducer_labeled.png)

For convenience we are not going to drive the ultrasonic transducer with hand-written code but rather use [this library](https://github.com/JRodrigoTech/Ultrasonic-HC-SR04).

#### Seven-Segment Display
There are several kinds of seven-segment displays. Their main difference is whether they provide a common cathode or anode. The seven-segment displays we are using have a common cathode, that is, all the segments share a common connection to GND. Seven-segment displays provide in addition to the common pin a dedicated pin for each segment. Which pin belongs to which segment is also type-specific. You can look up the assignment in the data-sheet of your display. The segments of a display are labeled with the letters from A to G.

![Seven-Segment Display](/images/seven_segment_labeled.png)

Since the Arduino Nano does not provide enough pins to drive two seven-segment displays independently we are using two MOSFETs to switch between them with high rate. This allows us to use only one pin for each segment of both displays.

![MOSFET-Symbols](/images/n_channel_mosfet.png)

Each MOSFET provides three pins, the gate pin (G), the source pin (S), and the drain pin (D). When their is no voltage applied to the gate pin then the MOSFET is in blocking state, that is the resistance between the source and the drain pin is very high such that no current flows between those two pins. When applying a voltage above the threshold voltage of the MOSFET – since we are using logic-level MOSFETS the threshold voltage should be below 5V – the MOSFET becomes conducting. The source and drain pins are now connected with each other and current can flow freely between those two pins.

# Wiring
Let us start with the wiring of all components.

![Wiring](/images/wiring.png)


# Software
First of all we need to include the header file of the ultrasonic transducer library. 
```c++
#include "Ultrasonic.h"
```

For convenience we define the pin numbers.
```c++
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
```

```c++

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
```

```c++
void setup() {
    for (int i = 0; i < 7; i++) {
        pinMode(ports[i], OUTPUT);
    }

    pinMode(DISPLAY_LEFT, OUTPUT);
    pinMode(DISPLAY_RIGHT, OUTPUT);

    Serial.begin(9600);
}
```

```c++
void show(int x) {
    for (int i = 0; i < 7; i++) {
        digitalWrite(ports[i], leds[x][i] ? HIGH : LOW);
    }
}
```

```c++
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
```



---

#### Licenses
* [Seven-Segment Display](https://commons.wikimedia.org/wiki/File:Seven_segment_05_Pengo.jpg): CC BY-SA 3.0
* [MOSFET-Symbols](https://commons.wikimedia.org/wiki/File:MISFET-Transistor_Symbole.svg): CC BY-SA 3.0
* [Seven-Segment Labeled](https://commons.wikimedia.org/wiki/File:7_segment_display_labeled.svg): CC BY-SA 3.0
