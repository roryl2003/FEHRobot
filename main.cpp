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

/* Include Classes */
#include "screen.hpp"
#include "pTest.hpp"
#include "movement.hpp"

using namespace std;

/*
Main Menu:
1. Calibrate the motors, the servos, the CDS cell, etc. to make sure everything is plugged in correctly
2. Have something that keep track of when you accomplish tasks
*/

/* Main function to control menu system */

int main()
{
    FEHMotor leftM(FEHMotor::Motor1, 7.2); 
    FEHMotor rightM(FEHMotor::Motor2, 7.2);
    FEHMotor backM(FEHMotor::Motor0, 7.2);

    FEHServo leftS(FEHServo::Servo0);
    FEHServo rightS(FEHServo::Servo7);
    FEHServo torqueS(FEHServo::Servo3);

    AnalogInputPin cds(FEHIO::P0_0);

    DigitalInputPin microswitch(FEHIO::P0_1);

    leftS.SetMin(500);
    leftS.SetMax(2279);

    rightS.SetMin(500);
    rightS.SetMax(2308);

    while(1){
        int option = mainMenu();

        switch(option){
            case 0:
                break;
            case 1:
                rotate(leftM, rightM, backM, true, 50, -1);
                break;
            case 2:
                break;
            case 3:
                goToStartingPoint(leftM, rightM, backM);
                break;
            case 4:
                pTestThree(leftM, rightM, backM, cds, leftS, rightS);
                break;
            case 5:
                dropCart(leftM, rightM, backM, leftS, rightS);
                break;
            case 6:
                sendArm(leftS, rightS, leftM, rightM, backM, true);
                break;
            case 7:
                rotateArm(torqueS);
                break;
            default:
                LCD.WriteLine("ERROR. OPTION VALUE IS: ");
                LCD.Write(option);
        }
    }
}
