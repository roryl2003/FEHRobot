#ifndef EXPLORATIONS_DOT_H
#define EXPLORATIONS_DOT_H

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

#define LINE_ON_RIGHT 0
#define ON_LINE 1
#define LINE_ON_LEFT 2

void lineFollowing();
void getMinAndMax();
void getRange(AnalogInputPin cds);

#endif