#include "explorations.hpp"

void getRange(AnalogInputPin cds)
{
    float max = cds.Value();
    float min = cds.Value();
    float cTime = TimeNow(), oTime = TimeNow();

    while (cTime < oTime + 10)
    {
        float value = cds.Value();
        if (value > max)
        {
            max = value;
        }
        else if (value < min)
        {
            min = value;
        }
        cTime = TimeNow();
    }

    LCD.WriteLine(max);
    LCD.WriteLine(min);
}

void getMinAndMax()
{
    AnalogEncoder left_encoder(FEHIO::P2_2);
    AnalogEncoder middle_encoder(FEHIO::P2_1);
    AnalogEncoder right_encoder(FEHIO::P2_0);
    float leftMax = 0, rightMax = 0, middleMax = 0;
    float leftMin = 3.3, rightMin = 3.3, middleMin = 3.3;
    float originalTime = TimeNow();
    float currentTime = TimeNow();

    while (currentTime < originalTime + 10)
    {
        currentTime = TimeNow();

        if (left_encoder.Value() > leftMax)
        {
            leftMax = left_encoder.Value();
        }

        if (left_encoder.Value() < leftMin)
        {
            leftMin = left_encoder.Value();
        }

        if (middle_encoder.Value() > middleMax)
        {
            middleMax = middle_encoder.Value();
        }

        if (middle_encoder.Value() < middleMin)
        {
            middleMin = middle_encoder.Value();
        }

        if (right_encoder.Value() > rightMax)
        {
            rightMax = right_encoder.Value();
        }

        if (right_encoder.Value() < rightMin)
        {
            rightMin = right_encoder.Value();
        }
    }

    LCD.Write("Left Max: ");
    LCD.WriteLine(leftMax);

    LCD.Write("Left Min: ");
    LCD.WriteLine(leftMin);

    LCD.Write("Middle Max: ");
    LCD.WriteLine(middleMax);

    LCD.Write("Middle Min: ");
    LCD.WriteLine(middleMin);

    LCD.Write("Right Max: ");
    LCD.WriteLine(rightMax);

    LCD.Write("Right Min: ");
    LCD.WriteLine(rightMin);
}

void lineFollowing(){
    AnalogEncoder left_encoder(FEHIO::P2_2);
    AnalogEncoder middle_encoder(FEHIO::P2_1);
    AnalogEncoder right_encoder(FEHIO::P2_0);
    FEHMotor left(FEHMotor::Motor2, 9.0);
    FEHMotor right(FEHMotor::Motor3, 9.0);

    int state = ON_LINE;

    while (1)
    {
        switch (state)
        {
            case LINE_ON_LEFT:
                left.SetPercent(15);
                right.SetPercent(25);
                if (left_encoder.Value() < 1)
                {
                    state = ON_LINE;
                }
                break;
            case LINE_ON_RIGHT:
                left.SetPercent(30);
                right.SetPercent(15);
                if (right_encoder.Value() < 1.2)
                {
                    state = ON_LINE;
                }
                break;
            case ON_LINE:
                left.SetPercent(15);
                right.SetPercent(15);
                if (left_encoder.Value() > 2)
                {
                    state = LINE_ON_LEFT;
                }
                if (right_encoder.Value() > 2)
                {
                    state = LINE_ON_RIGHT;
                }
                break;
            default:
                break;
        }
    }
}