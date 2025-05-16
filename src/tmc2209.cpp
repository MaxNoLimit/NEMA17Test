#include "main.hpp"
#include "tmc2209.hpp"

void TMC2209::beginPin()
{
    pinMode(EN_PIN, OUTPUT);
    digitalWrite(EN_PIN, HIGH);
    pinMode(STEP_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);

    // TMC2209::setFullStep();

    Serial.println(F("\nDone begining all pins!"));
}

void TMC2209::spinHowManyStep(int step)
{
    // enabling driver to spin
    TMC2209::enableDriverToSpin(true);
    for (int i = 0; i < step; i++)
    {
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(200);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(200);
    }
    // disabling driver to spin
    TMC2209::enableDriverToSpin(false);
}

void TMC2209::enableDriverToSpin(bool confirmation)
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

void TMC2209::setCCW_dir()
{
    Serial.println(F("Counter Clockwise spin"));
    digitalWrite(DIR_PIN, HIGH);
}

void TMC2209::setCW_dir()
{
    Serial.println(F("Clockwise spin"));
    digitalWrite(DIR_PIN, LOW);
}

void TMC2209::setFullStep()
{
    // Using UART Control mode
    TMC_SERIAL_PORT.begin(115200);

    // declaring block datagram
    uint8_t datagram[9];

    datagram[0] = 0x05;                                   // Sync Byte
    datagram[1] = 0x00;                                   // Master Address
    datagram[2] = 0x01;                                   // Slave Address
    datagram[3] = 0x6c | 0x80;                            // Register Address with Write Bit
    datagram[4] = (0x08000000 | 0x00000540 >> 24) & 0xFF; // Data Byte 3 (MSB)
    datagram[5] = (0x08000000 | 0x00000540 >> 16) & 0xFF; // Data Byte 2
    datagram[6] = (0x08000000 | 0x00000540 >> 8) & 0xFF;  // Data Byte 1
    datagram[7] = 0x08000000 | 0x00000540 & 0xFF;         // Data Byte 0 (LSB)
    datagram[8] = calculateCRC(datagram, 8);              // Calculate CRC over first 8 bytes

    // Send the datagram
    TMC_SERIAL_PORT.write(datagram, 9);
    TMC_SERIAL_PORT.flush(); // Wait for transmission to complete
    delay(1);                // Small delay to allow TMC to process (might be needed)
    Serial.println("\nFull step mode!");
}

// --- CRC Calculation Function (from earlier) ---
uint8_t TMC2209::calculateCRC(uint8_t datagram[], size_t len)
{
    uint8_t crc = 0;
    for (size_t i = 0; i < len; i++)
    {
        crc ^= datagram[i];
        for (int j = 0; j < 8; j++)
        {
            if (crc & 0x80)
            {
                crc = (crc << 1) ^ 0x07;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}