#include "screen.hpp"

void drawBatteryIcon(int batteryLife){
    // Draws Battery Icon Depending On Battery Life
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(1, 222, 40, 16);

    if (batteryLife > 70)
    {
        LCD.SetFontColor(GREEN);
        LCD.FillRectangle(2, 223, 39, 15);
    }
    else if (batteryLife > 30)
    {
        LCD.SetFontColor(YELLOW);
        LCD.FillRectangle(2, 223, 19, 15);
    }
    else
    {
        LCD.SetFontColor(RED);
        LCD.FillRectangle(2, 223, 9, 15);
    }

    LCD.SetFontColor(WHITE);
    LCD.FillRectangle(41, 226, 5, 8);

    // Writes Battery Percentage
    LCD.WriteAt(batteryLife, 47, 222);
}

int BatteryLife()
{
    return round(Battery.Voltage() / 11.7 * 100);
}

int mainMenu(){
    LCD.Clear();

    float x, y;

    FEHIcon::Icon title[1];
    char title_label[1][20] = {"MAIN MENU"};
    FEHIcon::DrawIconArray(title, 1, 1, 1, 201, 1, 1, title_label, WHITE, YELLOW);

    FEHIcon::Icon buttons[8];
    char buttons_label[8][20] = {"Fail Start", "CDS", "", "RPS Read", "", "", "", "Good Start"};
    FEHIcon::DrawIconArray(buttons, 4, 2, 40, 20, 1, 1, buttons_label, WHITE, YELLOW);

    while(1){
        float bLife = BatteryLife();
        drawBatteryIcon(bLife);

        while(!LCD.Touch(&x, &y));

        for(int n = 0; n < 8; n++){
            if(buttons[n].Pressed(x, y, 0)) {
                return n;
            }
        }
    }
}
