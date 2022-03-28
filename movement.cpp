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
    leftS.SetDegree(90);
    rightS.SetDegree(90);

    goForward(left, right, back, true, 0, 1.5, 50);

    leftS.SetDegree(0);
    rightS.SetDegree(0);
}

void dropArm(FEHServo leftS, FEHServo rightS){
    leftS.SetDegree(60);
    rightS.SetDegree(60);
}

void flipSwitch(FEHServo leftS, FEHServo rightS){
    leftS.SetDegree(150);
    rightS.SetDegree(150);
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