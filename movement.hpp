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
void rpsJukeboxLight(FEHMotor left, FEHMotor right, FEHMotor back, float A_x, float A_y);
void hitRedButton(FEHMotor left, FEHMotor right, FEHMotor back);
void hitBlueButton(FEHMotor left, FEHMotor right, FEHMotor back);
void prepareForRamp(FEHMotor left, FEHMotor right, FEHMotor back, float x, float y);
void goUpRamp(FEHMotor left, FEHMotor right, FEHMotor back, float x, float y);
void prepareForIceCream(FEHMotor left, FEHMotor right, FEHMotor back, float x, float y);
void directionalMovementDegrees(FEHMotor left, FEHMotor right, FEHMotor back, int degree, int power);
void directionalMovement(FEHMotor left, FEHMotor right, FEHMotor back, float rads, int power);
void directionalMovement(FEHMotor left, FEHMotor right, FEHMotor back, int degree, int power, double time);
void directionalMovement(FEHMotor left, FEHMotor right, FEHMotor back, int degree, int power, int counts);
void dropVanilla(FEHMotor left, FEHMotor right, FEHMotor back, FEHServo leftS, FEHServo rightS);
void dropMixed(FEHMotor left, FEHMotor right, FEHMotor back, FEHServo leftS, FEHServo rightS);
void dropChocolate(FEHMotor left, FEHMotor right, FEHMotor back, FEHServo leftS, FEHServo rightS);
void prepareBurger(FEHMotor left, FEHMotor right, FEHMotor back, float x, float y);
void slideTicket(FEHMotor left, FEHMotor right, FEHMotor back, float x, float y);
void prepareForRamp2(FEHMotor left, FEHMotor right, FEHMotor back, float x);
void goDownRamp(FEHMotor left, FEHMotor right, FEHMotor back, float y);

#endif