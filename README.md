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
* an Arduino Mega, and
* two logic-level n-channel MOSFET.

## Ultrasonic Transducer
The ultrasonic transducer is the main component of the setup. It works exactly the same way like the orientation system of bats. It emits ultrasound which is reflected back by an object. The time between the emission and the reception of the reflection can then be used to calculate the distance to the reflecting object.

The ultrasonic transducer provides four different pins. Two pins for the power supply, GND and VCC, a pin for triggering an ultrasound emission, and a pin which signals when the reflection has been received.

![Utrasonic Transducer](/images/transducer_labeled.png)

For convenience we are not going to drive the ultrasonic transducer with hand-written code but rather use [this library](https://github.com/JRodrigoTech/Ultrasonic-HC-SR04).

## Seven-Segment Display
There are several kinds of seven-segment displays. Their main difference is whether they provide a common cathode or anode. The seven-segment displays we used have a common cathode, that is, all the segments share a common connection to GND. Seven-segment displays provide in addition to the common pin a dedicated pin for each segment. Which pin belongs to which segment is also type-specific, you can look up the assignment in the data-sheet of your display.

![Seven-Segment Display](/images/seven_segment.jpg)

To save pins on the Arduino we decided to connect both seven-segment displays to the same pins and switch between them at a high rate using n-channel MOSFETs. This comes in handy if you try to recreate this setup with a smaller physical computing platform like the Arduino Nano. However it is unnecessary for the Arduino Mega since it provides more than enough pins.

![MOSFET-Symbols](/images/n_channel_mosfet.svg)


---

#### Licenses
* [Seven-Segment Display](https://commons.wikimedia.org/wiki/File:Seven_segment_05_Pengo.jpg): CC BY-SA 3.0
* [MOSFET-Symbols](https://commons.wikimedia.org/wiki/File:MISFET-Transistor_Symbole.svg): CC BY-SA 3.0
