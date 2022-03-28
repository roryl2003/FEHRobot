#ifndef UTILITY_DOT_H
#define UTILITY_DOT_H

#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include <FEHAccel.h>
#include <FEHBattery.h>
#include <FEHBuzzer.h>
#include <FEHRPS.h>
#include <FEHSD.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

bool inRange(float value, float min, float max);
void optoSensorValue(AnalogInputPin optoSensor);

#endif