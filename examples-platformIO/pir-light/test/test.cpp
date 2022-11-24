#include "../lib/ArduinoUnit/src/ArduinoUnit.h"

class SirLightSystemTests : public SystemTests
{
public:
    SirLightSystemTests(){};
    void enter(String name)
    {
        Serial.println(name);
        delay(3000);
        pirLight.loop();
    };

    void exit()
    {
        history->list->clear();
    };

    void run()
    {
        Test::run();
    }
};

SirLightSystemTests systemTests = SirLightSystemTests();

test(testLightOn)
{
    systemTests.enter("testLightOn");

    assertTrue(!pirLight.pir->behavior->isSensorHigh());

    assertTrue(pirLight.light->behavior->isActuatorHigh());

    assertTrue(history->proceedTime(4 * 1000));

    systemTests.exit();
}

test(testLightOff)
{
    systemTests.enter("testLightOff");

    assertTrue(pirLight.pir->behavior->isSensorLow());

    assertTrue(pirLight.light->behavior->isActuatorLow());

    assertTrue(history->proceedTime(4 * 1000));

    systemTests.exit();
}