#include "trafficlightscontroller.h"

TrafficLightsController::TrafficLightsController(QObject *parent)
    : QObject{parent}
{

}

void TrafficLightsController::setRedSwitch(const bool &redSwitch)
{
    if(redSwitch==mRedSwitch){
        return;
    }
    mRedSwitch=redSwitch;
    emit redSwitchIsChanged();
}

void TrafficLightsController::setYellowSwitch(const bool &yellowSwitch)
{
    if(yellowSwitch==mYellowSwitch){
        return;
    }
    mYellowSwitch=yellowSwitch;
    emit yellowSwitchIsChanged();
}

void TrafficLightsController::setGreenSwitch(const bool &greenSwitch)
{
    if(greenSwitch==mGreenSwitch){
        return;
    }
    mGreenSwitch=greenSwitch;
    emit greenSwitchIsChanged();
}

bool TrafficLightsController::redSwitch()
{
    return mRedSwitch;
}

bool TrafficLightsController::greenSwitch()
{
    return mGreenSwitch;
}

void TrafficLightsController::SwitchController(int lightColor)
{
    switch (lightColor)
    {
        case red:
            mRedSwitch=true;
            mYellowSwitch=false;
            mGreenSwitch=false;
            break;
        case yellow:
            mRedSwitch=false;
            mYellowSwitch=true;
            mGreenSwitch=false;
            break;
        case green:
            mRedSwitch=false;
            mYellowSwitch=false;
            mGreenSwitch=true;
            break;
        default:
            mRedSwitch=false;
            mYellowSwitch=false;
            mGreenSwitch=false;
            break;
    }
}

void TrafficLightsController::lightControler(bool isOn)
{
//    isOn=mIsOn;
    while(isOn)
    {
        lightColor=red;
        SwitchController(lightColor);
        std::this_thread::sleep_for(std::chrono::seconds(3));
        lightColor=yellow;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        SwitchController(lightColor);
        lightColor=green;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        SwitchController(lightColor);
    }
}

bool TrafficLightsController::yellowSwitch()
{
    return mYellowSwitch;
}


