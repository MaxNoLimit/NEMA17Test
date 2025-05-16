#ifndef TMC2209_HPP
#define TMC2209_HPP

#include <Arduino.h>
#define TMC_SERIAL_PORT Serial2
namespace TMC2209
{
    void beginPin();
    void setCW_dir();
    void setCCW_dir();
    void spinHowManyStep(int step);
    void enableDriverToSpin(bool confirmation);
    void setFullStep();
    uint8_t calculateCRC(uint8_t datagram[], size_t len);

}
#endif // TMC2209_HPP