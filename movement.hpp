#ifndef MOVEMENT_DOT_H
#define MOVEMENT_DOT_H

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

void moveSideways(FEHMotor left, FEHMotor right, FEHMotor back, bool positive, float time, int power);
void goForward(FEHMotor left, FEHMotor right, FEHMotor back, bool backwards, int direction, float time, int power);
void rotate(FEHMotor left, FEHMotor right, FEHMotor back, bool clockwise, int power, int degree);
void goToStartingPoint(FEHMotor left, FEHMotor right, FEHMotor back);
void dropCart(FEHMotor left, FEHMotor right, FEHMotor back, FEHServo leftS, FEHServo rightS);
void dropArm(FEHServo leftS, FEHServo rightS);
void sendArm(FEHServo leftS, FEHServo rightS, FEHMotor left, FEHMotor right, FEHMotor back, bool reset);
void flipSwitch(FEHServo leftS, FEHServo rightS);
void hookRotator(FEHServo hook);
void hitRedButton(FEHMotor left, FEHMotor right, FEHMotor back);
void hitBlueButton(FEHMotor left, FEHMotor right, FEHMotor back);

#endif