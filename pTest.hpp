#ifndef PTEST_DOT_H
#define PTEST_DOT_H

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

void pTestOne(FEHMotor left, FEHMotor right, FEHMotor back, AnalogInputPin cds);
void pTestTwo(FEHMotor left, FEHMotor right, FEHMotor back, AnalogInputPin cds, FEHServo leftS, FEHServo rightS);
void pTestThree(FEHMotor left, FEHMotor right, FEHMotor back, AnalogInputPin cds, FEHServo leftS, FEHServo rightS);
void pTestFour(FEHMotor left, FEHMotor right, FEHMotor back, AnalogInputPin cds, FEHServo leftS, FEHServo rightS);
void individualCompetition(FEHMotor left, FEHMotor right, FEHMotor back, AnalogInputPin cds, FEHServo leftS, FEHServo rightS, AnalogInputPin leftO, AnalogInputPin rightO, AnalogInputPin backO);


#endif