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
        Sleep(0.65);
    } else if(degree == 75){
        Sleep(1.0);
    } else if(degree == 120){
        Sleep(1.6);
    } else if(degree == 150){
        Sleep(2.0);
    } else if(degree == 45){
        Sleep(0.5);
    } else if(degree == 30){
        Sleep(0.4);
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
            back.SetPercent(1 * power);
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
    leftS.SetDegree(60);
    rightS.SetDegree(60);

    goForward(left, right, back, true, 0, 0.5, 50);

    leftS.SetDegree(90);
    rightS.SetDegree(90);
}

void dropArm(FEHServo leftS, FEHServo rightS){
    leftS.SetDegree(30);
    rightS.SetDegree(30);
}

void flipSwitch(FEHServo leftS, FEHServo rightS){
    leftS.SetDegree(90);
    rightS.SetDegree(90);
}

void sendArm(FEHServo leftS, FEHServo rightS, FEHMotor left, FEHMotor right, FEHMotor back, bool reset){
    leftS.SetDegree(125);
    rightS.SetDegree(125);

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
    left.SetPercent(-20);
    right.SetPercent(-20);
    back.SetPercent(-20);
    
    while (RPS.Heading() < 270 - 5);


    left.SetPercent(25);
    right.SetPercent(-25);
    back.SetPercent(0);

    //directionalMovement(left, right, back, 90, 25);

    while (RPS.Y() > y + 0.5);

    if (RPS.X() < x - 0.5) {
        left.SetPercent(-18);
        right.SetPercent(-18);
        back.SetPercent(25);

        //directionalMovement(left, right, back, 180, 25);

        while (RPS.X() < x - 0.5);
    }
    else if (RPS.X() > x + 0.5) {
        left.SetPercent(18);
        right.SetPercent(18);
        back.SetPercent(-25);

        //directionalMovement(left, right, back, 0, 25);

        while (RPS.X() > x + 0.5);
    }

    left.SetPercent(0);
    right.SetPercent(0);
    back.SetPercent(0);

}

void hitRedButton(FEHMotor left, FEHMotor right, FEHMotor back){
    moveSideways(left, right, back, true, 0.2, 50);
    rotate(left, right, back, true, 50, 120);
    goForward(left, right, back, false, 2, 1.7, 50);
    goForward(left, right, back, true, 2, 1.7, 50);
}

void hitBlueButton(FEHMotor left, FEHMotor right, FEHMotor back){
    moveSideways(left, right, back, false, 0.2, 50);
    rotate(left, right, back, true, 50, 120);
    goForward(left, right, back, false, 2, 1.7, 50);
    goForward(left, right, back, true, 2, 1.7, 50);
}

void prepareForRamp(FEHMotor left, FEHMotor right, FEHMotor back, float x) {
    directionalMovement(left, right, back, 330, 50);

    while (RPS.X() < x - 0.5);

    // Rotation
    left.SetPercent(20);
    right.SetPercent(20);
    back.SetPercent(20);

    while (RPS.Heading() > 90 + 5);

    directionalMovement(left, right, back, 0, 0);
}

void goUpRamp(FEHMotor left, FEHMotor right, FEHMotor back, float x, float y) {
    directionalMovement(left, right, back, 90, 90);

    while (RPS.Y() < y - 0.5);
}

void directionalMovement(FEHMotor left, FEHMotor right, FEHMotor back, int degree, int power) {
    double a1 = M_PI / 6;
    double a2 = 5 *  M_PI / 6;
    double a3 = 3 * M_PI / 2;
    double rads = degree * M_PI / 180;

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