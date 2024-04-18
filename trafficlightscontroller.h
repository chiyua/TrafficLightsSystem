#ifndef TRAFFICLIGHTSCONTROLLER_H
#define TRAFFICLIGHTSCONTROLLER_H

#include <QObject>
#include <qqml.h>
#include <chrono>
#include <thread>
class TrafficLightsController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool redSwitch READ redSwitch WRITE setRedSwitch NOTIFY redSwitchIsChanged)
    Q_PROPERTY(bool yellowSwitch READ yellowSwitch WRITE setYellowSwitch NOTIFY yellowSwitchIsChanged)
    Q_PROPERTY(bool greenSwitch READ greenSwitch WRITE setGreenSwitch NOTIFY greenSwitchIsChanged)
    QML_ELEMENT
public:
    explicit TrafficLightsController(QObject *parent = nullptr);

    void setRedSwitch(const bool &redSwitch);
    void setYellowSwitch(const bool &yellowSwitch);
    void setGreenSwitch(const bool &greenSwitch);

    bool redSwitch();
    bool yellowSwitch();
    bool greenSwitch();

    Q_INVOKABLE void lightControler(bool isOn);
    void SwitchController(int lightColor);

    bool mIsOn;

    enum Color{red,green,yellow};
signals:
    void redSwitchIsChanged();
    void yellowSwitchIsChanged();
    void greenSwitchIsChanged();
private:
    bool mRedSwitch;
    bool mYellowSwitch;
    bool mGreenSwitch;
    int lightColor=-1;
};

#endif // TRAFFICLIGHTSCONTROLLER_H
