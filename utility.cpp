#include "utility.hpp"

bool inRange(float value, float min, float max){
    return (value > min) && (value < max);
}

void optoSensorValue(AnalogInputPin optoSensor){
    while(1){
        LCD.Write(optoSensor.Value());
        Sleep(0.1);
        LCD.Clear();
    }   
}