#ifndef A4988_HPP
#define A4988_HPP

#include <Arduino.h>

namespace A4988
{
    void beginPin();
    void setCW_dir();
    void setCCW_dir();
    void spinHowManyStep(int step);
    void enableDriverToSpin(bool confirmation);
}
#endif // A4988_HPP