#include "../Component.h"
#include "../units-behaviors/HighLow.h"

class SensorDigital : public Component
{
public:
    HighLow *behavior;
    SensorDigital(int pin)
    {
        this->pin = pin;
        this->behavior = new HighLow();
        pinMode(pin, INPUT);
    };

    int read()
    {
        int value = digitalRead(this->pin);
        this->behavior->addStore(this->pin, value);
        Serial.println(value);
        return value;
    };
};
