#include "movement.hpp"

void rotate(FEHMotor left, FEHMotor right, FEHMotor back, bool clockwise, int power, int degree){
    if(!clockwise){
        power *= -1;
    }

    left.SetPercent(power);
    right.SetPercent(power);
    back.SetPercent(power);
    
    if(degree == 180){
        Sleep(2.4);
    } else if(degree == -1){
        Sleep(10.0);
    } else if(degree == 60){
        Sleep(0.6);
    } else if(degree == 75){
        Sleep(0.85);
    } else if(degree == 120){
        Sleep(1.45);
    } else if(degree == 150){
        Sleep(2.0);
    } else if(degree == 45){
        Sleep(0.5);
    } else if(degree == 30){
        Sleep(0.4);
    } else if(degree == 105){
        Sleep(1.35);
    } else if(degree == 5){
        Sleep(0.25);
    } else if(degree == 20){
        Sleep(0.35);
    }


    left.SetPercent(0);
    right.SetPercent(0);
    back.SetPercent(0);
}

void goForward(FEHMotor left, FEHMotor right, FEHMotor back, bool backwards, int direction, float time, int power){
    
    // 0 means left right forward
    // 1 means right back forward
    // 2 means left back forward
    if(direction == 0){
        if(backwards){
            left.SetPercent(-1 * power);
            right.SetPercent(power);
        } else {
            left.SetPercent(power);
            right.SetPercent(-1 * power);

            if(power == 90){
                right.SetPercent(-1 * power + 3);
            }
        }
    } else if(direction == 1){
        if(backwards){
            back.SetPercent(-1 * power);
            right.SetPercent(power);
        } else {
            back.SetPercent(power);
            right.SetPercent(-1 * power);
        }
    } else {
        if(backwards){
            left.SetPercent(power);
            back.SetPercent(-1 * power);
        } else {
            back.SetPercent(power);
            left.SetPercent(-1 * power);
        }
    }

    Sleep(time);

    left.SetPercent(0);
    right.SetPercent(0);
    back.SetPercent(0);
}

void moveSideways(FEHMotor left, FEHMotor right, FEHMotor back, bool positive, float time, int power){
    if(positive){
        back.SetPercent(-1 * power - 4);
        left.SetPercent(power - 10);
        right.SetPercent(power - 11);
    } else {
        back.SetPercent(power + 4);
        left.SetPercent(-1 * (power - 10));
        right.SetPercent(-1 * (power - 10));
    }

    Sleep(time);

    left.SetPercent(0);
    right.SetPercent(0);
    back.SetPercent(0);
}

void goToStartingPoint(FEHMotor left, FEHMotor right, FEHMotor back){
    goForward(left, right, back, false, 0, 2.0, 25);
    rotate(left, right, back, true, 50, 180);
    goForward(left, right, back, true, 0, 5.15, 25);
}

void dropCart(FEHMotor left, FEHMotor right, FEHMotor back, FEHServo leftS, FEHServo rightS){
    leftS.SetDegree(45);
    rightS.SetDegree(45);

    goForward(left, right, back, true, 0, 0.5, 50);

    leftS.SetDegree(90);
    rightS.SetDegree(90);
}

void dropArm(FEHServo leftS, FEHServo rightS){
    leftS.SetDegree(0);
    rightS.SetDegree(0);
}

void flipSwitch(FEHServo leftS, FEHServo rightS){
    leftS.SetDegree(90);
    rightS.SetDegree(90);
}

void sendArm(FEHServo leftS, FEHServo rightS, FEHMotor left, FEHMotor right, FEHMotor back, bool reset){
    leftS.SetDegree(80);
    rightS.SetDegree(80);

    moveSideways(left, right, back, true, 2.0, 30);

    if(reset){
        Sleep(3.0);
        dropArm(leftS, rightS);
    }
}

void hookRotator(FEHServo hook){
    hook.SetDegree(0);

    Sleep(2.0);

    hook.SetDegree(90);
}

void rpsJukeboxLight(FEHMotor left, FEHMotor right, FEHMotor back, float x, float y) {
    rotate(left, right, back, false, 50, 120);
    
    left.SetPercent(-35);
    right.SetPercent(-35);
    back.SetPercent(-35);
    
    while (RPS.Heading() < 270 - 10);


    left.SetPercent(25);
    right.SetPercent(-25);
    back.SetPercent(0);

    //directionalMovementDegrees(left, right, back, 90, 25);

    while (RPS.Y() > y + 0.25 || RPS.Y() < 0);

    LCD.WriteLine(RPS.Y());

    if (RPS.X() < x - 0.5) {
        left.SetPercent(-18);
        right.SetPercent(-18);
        back.SetPercent(25);

        //directionalMovementDegrees(left, right, back, 180, 25);

        while (RPS.X() < x - 0.5);
    }
    else if (RPS.X() > x + 0.5) {
        left.SetPercent(18);
        right.SetPercent(18);
        back.SetPercent(-25);

        //directionalMovementDegrees(left, right, back, 0, 25);

        while (RPS.X() > x + 0.5);
    }

    left.SetPercent(0);
    right.SetPercent(0);
    back.SetPercent(0);

}

void hitRedButton(FEHMotor left, FEHMotor right, FEHMotor back){
    moveSideways(left, right, back, true, 0.2, 50);
    rotate(left, right, back, true, 50, 105);
    goForward(left, right, back, false, 2, 2.0, 50);
    goForward(left, right, back, true, 2, 1.7, 50);
    rotate(left, right, back, true, 50, 60);
}

void hitBlueButton(FEHMotor left, FEHMotor right, FEHMotor back){
    moveSideways(left, right, back, false, 0.2, 50);
    rotate(left, right, back, true, 50, 120);
    goForward(left, right, back, false, 2, 2.0, 50);
    goForward(left, right, back, true, 2, 1.7, 50);
    rotate(left, right, back, true, 50, 60);
}

void prepareForRamp(FEHMotor left, FEHMotor right, FEHMotor back, float x, float y) {
    left.SetPercent(20);
    right.SetPercent(20);
    back.SetPercent(20);

    while (RPS.Heading() > 100);
    
    left.SetPercent(20);
    right.SetPercent(-20);
    back.SetPercent(0);

    while(RPS.Y() < y - 1.2);

    back.SetPercent(-48);
    right.SetPercent(26);
    left.SetPercent(26);

    while (RPS.X() < x - 2.0);

    // Rotation
    /*left.SetPercent(20);
    right.SetPercent(20);
    back.SetPercent(20);

    while (RPS.Heading() > 90 + 5);*/

    left.SetPercent(-20);
    right.SetPercent(-20);
    back.SetPercent(-20);

    while (RPS.Heading() < 95);
    
    /*else if (RPS.Heading() < 85) {
        left.SetPercent(-20);
        right.SetPercent(-20);
        back.SetPercent(-20);

        while (RPS.Heading() < 85);
    }*/

    left.SetPercent(0);
    right.SetPercent(0);
    back.SetPercent(0);
}

void prepareForRamp2(FEHMotor left, FEHMotor right, FEHMotor back, float x){
    back.SetPercent(-36);
    left.SetPercent(20);
    right.SetPercent(20);

    while (RPS.X() > x + 0.5);

    if (RPS.Heading() > 275) {
        left.SetPercent(20);
        right.SetPercent(20);
        back.SetPercent(20);

        while (RPS.Heading() > 275);
    }
    else if (RPS.Heading() < 265) {
        left.SetPercent(-20);
        right.SetPercent(-20);
        back.SetPercent(-20);

        while (RPS.Heading() < 265);
    }

    left.SetPercent(0);
    right.SetPercent(0);
    back.SetPercent(0);
} 

void goDownRamp(FEHMotor left, FEHMotor right, FEHMotor back, float y) {
    left.SetPercent(75);
    right.SetPercent(-75);
    back.SetPercent(0);

    while (RPS.Y() > y - 1);
}

void goUpRamp(FEHMotor left, FEHMotor right, FEHMotor back, float x, float y) {
    //directionalMovementDegrees(left, right, back, 90, 90);
    left.SetPercent(90);
    right.SetPercent(-93);
    back.SetPercent(0);

    while (RPS.Y() < y - 0.5);

    if (RPS.Heading() > 95) {
        left.SetPercent(20);
        right.SetPercent(20);
        back.SetPercent(20);

        while (RPS.Heading() > 95);
    }
    else if (RPS.Heading() < 85) {
        left.SetPercent(-20);
        right.SetPercent(-20);
        back.SetPercent(-20);

        while (RPS.Heading() < 85);
    }
}

void prepareForIceCream(FEHMotor left, FEHMotor right, FEHMotor back, float x, float y) {
    /*float rads = ((y - RPS.Y()) / (x - RPS.X()));

    if(rads < 0) {
        rads += M_PI;
    }

    directionalMovement(left, right, back, rads, 20);*/
    left.SetPercent(35);
    right.SetPercent(-35);
    back.SetPercent(0);

    while (RPS.Y() < y - 2.5);

    /*left.SetPercent(-10);
    right.SetPercent(-10);
    back.SetPercent(17);
    while (RPS.X() > x + 0.5);*/

    LCD.WriteLine(RPS.Heading());

    if (RPS.Heading() < 130){
        left.SetPercent(-20);
        right.SetPercent(-20);
        back.SetPercent(-20);

        while(RPS.Heading() < 130);
    } else if(RPS.Heading() > 140){
        left.SetPercent(20);
        right.SetPercent(20);
        back.SetPercent(20);

        while(RPS.Heading() > 140);
    }

    left.SetPercent(0);
    right.SetPercent(0);
    back.SetPercent(0);
}

void directionalMovementDegrees(FEHMotor left, FEHMotor right, FEHMotor back, int degree, int power) {
    double a1 = M_PI / 6.0;
    double a2 = 5.0 *  M_PI / 6.0;
    double a3 = 3.0 * M_PI / 2.0;
    double rads = degree * M_PI / 180.0;

    right.SetPercent(power * sin(a1 - rads));
    left.SetPercent(power * sin(a2 - rads));
    back.SetPercent(power * sin(a3 - rads));
}

void directionalMovement(FEHMotor left, FEHMotor right, FEHMotor back, float rads, int power) {
    double a1 = M_PI / 6;
    double a2 = 5 *  M_PI / 6;
    double a3 = 3 * M_PI / 2;

    right.SetPercent(power * sin(a1 - rads));
    left.SetPercent(power * sin(a2 - rads));
    back.SetPercent(power * sin(a3 - rads));
}

void directionalMovement(FEHMotor left, FEHMotor right, FEHMotor back, int degree, int power, double time) {
    double a1 = M_PI / 6;
    double a2 = 5 *  M_PI / 6;
    double a3 = 3 * M_PI / 2;
    double rads = degree * M_PI / 180;

    right.SetPercent(power * sin(a1 - rads));
    left.SetPercent(power * sin(a2 - rads));
    back.SetPercent(power * sin(a3 - rads));

    Sleep(time);
}

void directionalMovement(FEHMotor left, FEHMotor right, FEHMotor back, int degree, int power, int counts) {
    double a1 = M_PI / 6;
    double a2 = 5 *  M_PI / 6;
    double a3 = 3 * M_PI / 2;
    double rads = degree * M_PI / 180;

    right.SetPercent(power * sin(a1 - rads));
    left.SetPercent(power * sin(a2 - rads));
    back.SetPercent(power * sin(a3 - rads));
}

void dropChocolate(FEHMotor left, FEHMotor right, FEHMotor back, FEHServo leftS, FEHServo rightS){
    flipSwitch(leftS, rightS);
    goForward(left, right, back, false, 0, 1.7, 50);
    rotate(left, right, back, true, 50, 20);
    dropArm(leftS, rightS);
    goForward(left, right, back, true, 0, 1.0, 50);
    Sleep(5.25);
    goForward(left, right, back, false, 0, 1.0, 50);
    flipSwitch(leftS, rightS);
    rotate(left, right, back, true, 50, 20);
    goForward(left, right, back, true, 0, 1.0, 50);
    dropArm(leftS, rightS);
}

void dropMixed(FEHMotor left, FEHMotor right, FEHMotor back, FEHServo leftS, FEHServo rightS){
    flipSwitch(leftS, rightS);
    goForward(left, right, back, false, 0, 1.7, 50);
    rotate(left, right, back, false, 50, 20);
    dropArm(leftS, rightS);
    goForward(left, right, back, true, 0, 1.0, 50);
    Sleep(5.25);
    goForward(left, right, back, false, 0, 1.0, 50);
    flipSwitch(leftS, rightS);
    goForward(left, right, back, true, 0, 1.7, 50);
    dropArm(leftS, rightS);
}

void dropVanilla(FEHMotor left, FEHMotor right, FEHMotor back, FEHServo leftS, FEHServo rightS){
    flipSwitch(leftS, rightS);
    goForward(left, right, back, false, 0, 1.7, 50);
    rotate(left, right, back, false, 50, 20);
    dropArm(leftS, rightS);
    goForward(left, right, back, true, 0, 1.0, 50);
    Sleep(5.25);
    goForward(left, right, back, false, 0, 1.0, 50);
    flipSwitch(leftS, rightS);
    goForward(left, right, back, true, 0, 1.7, 50);
    dropArm(leftS, rightS);
}

void prepareBurger(FEHMotor left, FEHMotor right, FEHMotor back, float x, float y) {
    left.SetPercent(-35);
    right.SetPercent(35);
    back.SetPercent(0);

    while (RPS.X() < x - 0.75);

    left.SetPercent(0);
    right.SetPercent(0);
    Sleep(0.5);

    left.SetPercent(20);
    right.SetPercent(20);
    back.SetPercent(20);

    while(RPS.Heading() > 95);

    left.SetPercent(0);
    right.SetPercent(0);
    back.SetPercent(0);
    Sleep(0.5);

    left.SetPercent(50);
    right.SetPercent(-50);

    while(RPS.Y() < y - 2.0);

    left.SetPercent(0);
    right.SetPercent(0);
}

void slideTicket(FEHMotor left, FEHMotor right, FEHMotor back, float x, float y) {
    left.SetPercent(-35);
    right.SetPercent(-35);
    back.SetPercent(-35);

    while (RPS.Heading() < 260);

    //directionalMovementDegrees(left, right, back, 180, 20);

    back.SetPercent(20);
    right.SetPercent(-14);
    left.SetPercent(-14);

    while (RPS.X() < x - 0.5);

    left.SetPercent(50);
    right.SetPercent(-50);
    back.SetPercent(0);

    while (RPS.Y() > y + 2.5);
        
    moveSideways(left, right, back, false, 0.5, 30);

    //directionalMovementDegrees(left, right, back, 0, 50);

    left.SetPercent(28);
    right.SetPercent(28);
    back.SetPercent(-40);

    Sleep(1.0);

    //directionalMovementDegrees(left, right, back, 270, 50);
    back.SetPercent(0);
    left.SetPercent(-50);
    right.SetPercent(50);

    Sleep(1.0);
}