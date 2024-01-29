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

bool TrafficLightsController::yellowSwitch()
{
    return mYellowSwitch;
}

void TrafficLightsController::trafficLightsController()
{

}
