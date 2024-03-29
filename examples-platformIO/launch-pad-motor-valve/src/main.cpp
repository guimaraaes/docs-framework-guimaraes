#include <Arduino.h>

// #define CREATE_ENVIROMENT
// #define COMPONENT_TESTS_ENVIROMENT
#define SYSTEM_TESTS_ENVIROMENT

#include "../lib/FrameworkGuimaraes/FrameworkGuimaraes.h"

#include "../EmbeddedSystem/EmbeddedSystem.cpp"

#ifdef SYSTEM_TESTS_ENVIROMENT
#include "../test/SystemTests.cpp"
#endif
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  embeddedSystem.setupES();
}

void loop()
{
// put your main code here, to run repeatedly:
#ifdef CREATE_ENVIROMENT
  embeddedSystem.loopES();
#endif

#ifdef COMPONENT_TESTS_ENVIROMENT
  embeddedSystem.runComponentTests();
#endif

#ifdef SYSTEM_TESTS_ENVIROMENT
  systemTests.run();
#endif
}