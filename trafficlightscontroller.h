#ifndef TRAFFICLIGHTSCONTROLLER_H
#define TRAFFICLIGHTSCONTROLLER_H

#include <QObject>
#include <qqml.h>

class TrafficLightsController : public QObject
{
    Q_OBJECT
public:
    explicit TrafficLightsController(QObject *parent = nullptr);
    Q_PROPERTY(bool redSwitch READ redSwitch WRITE setRedSwitch NOTIFY redSwitchIsChanged)
    Q_PROPERTY(bool yellowSwitch READ yellowSwitch WRITE setYellowSwitch NOTIFY yellowSwitchIsChanged)
    Q_PROPERTY(bool greenSwitch READ greenSwitch WRITE setGreenSwitch NOTIFY greenSwitchIsChanged)

    void setRedSwitch(const bool &redSwitch);
    void setYellowSwitch(const bool &yellowSwitch);
    void setGreenSwitch(const bool &greenSwitch);

    bool redSwitch();
    bool yellowSwitch();
    bool greenSwitch();

    void trafficLightsController();

signals:
    void redSwitchIsChanged();
    void yellowSwitchIsChanged();
    void greenSwitchIsChanged();
private:
    bool mRedSwitch;
    bool mYellowSwitch;
    bool mGreenSwitch;
};

#endif // TRAFFICLIGHTSCONTROLLER_H
