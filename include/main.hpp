#ifndef MAIN_HPP
#define MAIN_HPP

#include <Arduino.h>

#define EN_PIN GPIO_NUM_19
#define STEP_PIN GPIO_NUM_18
#define DIR_PIN GPIO_NUM_5

namespace A4988
{
    void beginPin();
    void setCW_dir();
    void setCCW_dir();
    void spinHowManyStep(int step);
    void enableDriverToSpin(bool confirmation);
}

#endif // MAIN_HPP