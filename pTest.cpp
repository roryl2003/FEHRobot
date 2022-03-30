#include "pTest.hpp"
#include "movement.hpp"
#include "utility.hpp"

void pTestOne(FEHMotor left, FEHMotor right, FEHMotor back, AnalogInputPin cds){
    LCD.Clear();
    LCD.WriteLine("Running");
    
    float redMin = 0, redMax = 1, blueMin = 0.850, blueMax = 0.900, clearMin = 2.459, clearMax = 2.550;
    
    // Wait till the light is red
    while(!inRange(cds.Value(), redMin, redMax));

    // Move Forward to Allign with CDS Cell
    left.SetPercent(30);
    right.SetPercent(-30);
    Sleep(1.8);

    // Move Horizontal to be on the CDS Cell
    back.SetPercent(31);
    left.SetPercent(-20);
    right.SetPercent(-19);
    Sleep(5.8);

    back.SetPercent(0);
    right.SetPercent(0);
    left.SetPercent(0);

    if (inRange(cds.Value(), blueMin, blueMax)) {
        LCD.WriteLine("Blue");
    } else {
        LCD.WriteLine("Red");
    }

    Sleep(3.0);

    // Rotate so Bumper is in Front
    back.SetPercent(-20);
    left.SetPercent(-20);
    right.SetPercent(-20);
    Sleep(2.0);    

    // Move Forward to Hit Button
    left.SetPercent(-50);
    right.SetPercent(0);
    back.SetPercent(50);

    Sleep(2.0);

    // Move Backwards to original position
    left.SetPercent(20);
    right.SetPercent(0);
    back.SetPercent(-20);

    Sleep(2.0);

    // Rotate so Bumper is in Front
    back.SetPercent(20);
    left.SetPercent(20);
    right.SetPercent(20);
    Sleep(1.9);    

    // Move Horizontal to allign to ramp
    back.SetPercent(-31);
    left.SetPercent(20);
    right.SetPercent(19);
    Sleep(3.0);

    back.SetPercent(0);
    left.SetPercent(50);
    right.SetPercent(-52);
    Sleep(6.0);

    back.SetPercent(0);
    left.SetPercent(-50);
    right.SetPercent(50);
    Sleep(6.0);

    back.SetPercent(0);
    right.SetPercent(0);
    left.SetPercent(0);

    //Drive toward the jukebox light
    left.SetPercent(30);
    right.SetPercent(-30);
    Sleep(5.6);

    left.SetPercent(0);
    right.SetPercent(0);

    Sleep(1.0);

    rotate(left, right, back, true, 50, 180);
   
    //Read the light value
    if (inRange(cds.Value(), blueMin, blueMax)) {
        LCD.WriteLine("Blue");
       
        left.SetPercent(-30);
        back.SetPercent(30);
        right.SetPercent(0);

        Sleep(5.0);

        left.SetPercent(30);
        back.SetPercent(-30);
        right.SetPercent(0);

        Sleep(1.0);
    }
   
    else {
        LCD.Write("Red");

        right.SetPercent(-30);
        left.SetPercent(10);
        back.SetPercent(10);

        Sleep(2.0);

        left.SetPercent(-30);
        back.SetPercent(30);
        right.SetPercent(0);

        Sleep(5.0);

        left.SetPercent(30);
        back.SetPercent(-30);
        right.SetPercent(0);

        Sleep(1.0);

        right.SetPercent(30);
        left.SetPercent(-10);
        back.SetPercent(-10);

        Sleep(5.0);
    }

   

    //Drive toward button of correct color

    right.SetPercent(0);
    left.SetPercent(50);
    back.SetPercent(-50);

    Sleep(5.0);

    right.SetPercent(0);
    left.SetPercent(-50);
    back.SetPercent(50);

    Sleep(5.0);

    //Drive to ramp

    //Drive up ramp

    //Drive down ramp

    left.SetPercent(0);
    right.SetPercent(0);
    back.SetPercent(0);
}

void pTestTwo(FEHMotor left, FEHMotor right, FEHMotor back, AnalogInputPin cds, FEHServo leftS, FEHServo rightS){
    float redMin = 0, redMax = 1, blueMin = 0.850, blueMax = 0.900, clearMin = 2.459, clearMax = 2.550;
    while(!inRange(cds.Value(), redMin, redMax));
    goForward(left, right, back, false, 0, 2.0, 25);
    moveSideways(left, right, back, false, 6.25, 30);
    goForward(left, right, back, false, 0, 4.5, 25);
    dropCart(left, right, back, leftS, rightS);
    moveSideways(left, right, back, true, 6.75, 30);
    goForward(left, right, back, false, 0, 5.5, 25);
    rotate(left, right, back, true, 20, 15);
    goForward(left, right, back, false, 0, 0.3, 25);
    moveSideways(left, right, back, false, 1.0, 30);
    goForward(left, right, back, true, 0, 2.5, 25);
    moveSideways(left, right, back, false, 3.25, 30);
    rotate(left, right, back, true, 50, 120);
    goForward(left, right, back, false, 2, 8, 75);
}

void pTestThree(FEHMotor left, FEHMotor right, FEHMotor back, AnalogInputPin cds, FEHServo leftS, FEHServo rightS){
    float redMin = 0, redMax = 1, blueMin = 0.850, blueMax = 0.900, clearMin = 2.459, clearMax = 2.550;
    while(!inRange(cds.Value(), redMin, redMax));
    dropArm(leftS, rightS);
    goForward(left, right, back, false, 0, 2.0, 25);
    moveSideways(left, right, back, false, 3.25, 30);
    rotate(left, right, back, true, 50, 120);
    goForward(left, right, back, false, 2, 5.0, 75);
    rotate(left, right, back, false, 50, 150);
    goForward(left, right, back, false, 0, 8.00, 30);
    goForward(left, right, back, true, 0, 0.50, 30);
    sendArm(leftS, rightS, left, right, back, false);
    moveSideways(left, right, back, false, 2.0, 30);
    rotate(left, right, back, false, 50, 75);
    goForward(left, right, back, false, 0, 4.00, 30);
    dropArm(leftS, rightS);
}

void pTestFour(FEHMotor left, FEHMotor right, FEHMotor back, AnalogInputPin cds, FEHServo leftS, FEHServo rightS){
    float redMin = 0, redMax = 1, blueMin = 0.850, blueMax = 0.900, clearMin = 2.459, clearMax = 2.550;
    while(!inRange(cds.Value(), redMin, redMax));
    flipSwitch(leftS, rightS);
    goForward(left, right, back, false, 0, 5.0, 25);
    moveSideways(left, right, back, false, 2.75, 30);
    goForward(left, right, back, false, 0, 3.5, 90);
    moveSideways(left, right, back, false, 3.0, 30);
    rotate(left, right, back, false, 50, 45);
    goForward(left, right, back, false, 0, 2.0, 30);
    dropArm(leftS, rightS);
    goForward(left, right, back, true, 0, 3.0, 30);
    Sleep(7.0);
    goForward(left, right, back, false, 0, 3.0, 30);
    flipSwitch(leftS, rightS);
    goForward(left, right, back, true, 0, 3.5, 30);
    rotate(left, right, back, true, 50, 45);
    goForward(left, right, back, true, 0, 7.0, 30);
    rotate(left, right, back, false, 50, 60);
    goForward(left, right, back, true, 0, 10.0, 30);
}

void individualCompetition(FEHMotor left, FEHMotor right, FEHMotor back, AnalogInputPin cds, FEHServo leftS, FEHServo rightS, AnalogInputPin leftO, AnalogInputPin rightO, AnalogInputPin backO){
    // Clear Screen
    LCD.Clear();

    RPS.InitializeTouchMenu();

    // Fetch RPS Values
    FEHFile* fptr = SD.FOpen("RPS_TEST.txt", "r");
    float A_x, A_y, B_x, B_y, C_x, C_y, D_x, D_y, E_x, E_y, F_x, F_y;
    SD.FScanf(fptr, "%f%f", &A_x, &A_y);
    SD.FScanf(fptr, "%f%f", &B_x, &B_y);
    SD.FScanf(fptr, "%f%f", &C_x, &C_y);
    SD.FScanf(fptr, "%f%f", &D_x, &D_y);
    SD.FScanf(fptr, "%f%f", &E_x, &E_y);
    SD.FScanf(fptr, "%f%f", &F_x, &F_y);
    SD.FClose(fptr);
    
    // Start with start light
    float redMin = 0, redMax = 1.5, blueMin = 0.0, blueMax = 1.5, clearMin = 2.459, clearMax = 2.550, startTime = TimeNow();
    while(!inRange(cds.Value(), redMin, redMax));

    // Travel to Drop Cart
    rotate(left, right, back, false, 50, 60);
    goForward(left, right, back, false, 0, 3.7, 50);
    rotate(left, right, back, true, 50, 60);
    goForward(left, right, back, false, 0, 0.5, 50);
    dropCart(left, right, back, leftS, rightS);

    // Printing Out Split
    LCD.Write("Cart Split: ");
    LCD.WriteLine(TimeNow() - startTime);

    // Line Up and Read Juxebox Light
    rpsJukeboxLight(left, right, back, A_x, A_y);
    /*
    rotate(left, right, back, true, 50, 180);
    goForward(left, right, back, false, 0, 3.0, 30);
    */

    // Hit Appropriate Button and Line Up With Ramp

    Sleep(0.5);

    LCD.WriteLine(cds.Value());

    if(inRange(cds.Value(), redMin, redMax)) {
        LCD.WriteLine("Red");
        hitRedButton(left, right, back);
    } else {
        LCD.WriteLine("Blue");
        hitBlueButton(left, right, back);
    }

    LCD.Write("Button Split: ");
    LCD.WriteLine(TimeNow() - startTime);

    prepareForRamp(left, right, back, B_x);

    goUpRamp(left, right, back, C_x, C_y);

    LCD.Write("Ramp Split: ");
    LCD.WriteLine(TimeNow() - startTime);

    prepareForIceCream(left, right, back, D_x, D_y);

    if(RPS.GetIceCream() == 0){
        dropVanilla(left, right, back, leftS, rightS);
    } else if(RPS.GetIceCream() == 1){
        dropMixed(left, right, back, leftS, rightS);
    } else {
        dropChocolate(left, right, back, leftS, rightS);
    }

    prepareBurger(left, right, back, E_x, E_y);

    //goForward(left, right, back, true, 0, 3.0, 50);
    sendArm(leftS, rightS, left, right, back, false);

    slideTicket(left, right, back, F_x, F_y);

    prepareForRamp2(left, right, back, C_x);

    goDownRamp(left, right, back, B_y);

    rotate(left, right, back, true, 50, 60);

    goForward(left, right, back, false, 2, 5.0, 50);

    Sleep(10.0);

    
}