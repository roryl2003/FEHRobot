/* Include preprocessor directives */
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
#include <vector>
#include <string>

/* Include Classes */
#include "screen.hpp"
#include "pTest.hpp"
#include "movement.hpp"
#include "utility.hpp"

using namespace std;

/*
Main Menu:
1. Calibrate the motors, the servos, the CDS cell, etc. to make sure everything is plugged in correctly
2. Have something that keep track of when you accomplish tasks
*/

/* Main function to control menu system */

int main()
{
    FEHMotor leftM(FEHMotor::Motor0, 7.2); 
    FEHMotor rightM(FEHMotor::Motor2, 7.2);
    FEHMotor backM(FEHMotor::Motor1, 7.2);

    FEHServo leftS(FEHServo::Servo0);
    FEHServo rightS(FEHServo::Servo7);

    AnalogInputPin cds(FEHIO::P0_0);

    DigitalInputPin microswitch(FEHIO::P0_1);

    AnalogInputPin leftOptoSensor(FEHIO::P3_7);
    AnalogInputPin backOptoSensor(FEHIO::P2_0);
    AnalogInputPin rightOptoSensor(FEHIO::P1_0);

    leftS.SetMin(809);
    leftS.SetMax(2500);

    leftS.SetDegree(65);

    while(1){
        int option = mainMenu();

        switch(option){
            case 0:
                individualCompetition(leftM, rightM, backM, cds, leftS, rightS, leftOptoSensor, rightOptoSensor, backOptoSensor, true);
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                readRPSVals();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                individualCompetition(leftM, rightM, backM, cds, leftS, rightS, leftOptoSensor, rightOptoSensor, backOptoSensor, false);
                break;
            default:
                LCD.WriteLine("ERROR. OPTION VALUE IS: ");
                LCD.Write(option);
        }
    }
}
