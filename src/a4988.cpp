#include "main.hpp"
#include "a4988.hpp"

void A4988::beginPin()
{
    pinMode(EN_PIN, OUTPUT);
    digitalWrite(EN_PIN, HIGH);
    pinMode(STEP_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);

    Serial.println(F("Done begining all pins!"));
}

void A4988::setCW_dir()
{
    Serial.println(F("Clockwise spin"));
    digitalWrite(DIR_PIN, HIGH);
}

void A4988::setCCW_dir()
{
    Serial.println(F("Counter Clockwise spin"));
    digitalWrite(DIR_PIN, LOW);
}

void A4988::enableDriverToSpin(bool confirmation)
{
    if (confirmation)
    {
        digitalWrite(EN_PIN, LOW);
    }
    else
    {
        digitalWrite(EN_PIN, HIGH);
    }
}

void A4988::spinHowManyStep(int step)
{
    // enabling driver to spin
    A4988::enableDriverToSpin(true);
    for (int i = 0; i < step; i++)
    {
        digitalWrite(STEP_PIN, HIGH);
        delay(3);
        digitalWrite(STEP_PIN, LOW);
        delay(3);
    }
    // disabling driver to spin
    A4988::enableDriverToSpin(false);
}