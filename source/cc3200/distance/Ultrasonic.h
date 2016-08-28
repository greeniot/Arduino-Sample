#pragma once

// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// GitHub: https://github.com/JRodrigoTech/Ultrasonic-HC-SR04
//
// This code is licensed under Creative Commons Share alike 
// and Attribution by J.Rodrigo ( http://www.jrodrigo.net ).

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define CM  (1)
#define INC (0)

class Ultrasonic {
  public:
    Ultrasonic(int TP, int EP);
	  Ultrasonic(int TP, int EP, long TO);
    long Timing();
    float Ranging(int sys);

  private:
    int Trig_pin;
    int Echo_pin;
	  long Time_out;
    long duration;
    float distance_cm;
    float distance_inc;
};
