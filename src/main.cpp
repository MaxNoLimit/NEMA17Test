#include "main.hpp"
#include "a4988.hpp"
#include "tmc2209.hpp"

void setup()
{
  // begin serial
  Serial.begin(115200);

  // begin pins
  // A4988::beginPin();
  TMC2209::beginPin();

  // just once
  // A4988::setCW_dir();
  TMC2209::setCW_dir();

  // A4988::spinHowManyStep(1500);
  TMC2209::spinHowManyStep(14000);

  // A4988::setCCW_dir();
  TMC2209::setCCW_dir();

  // A4988::spinHowManyStep(1500);
  TMC2209::spinHowManyStep(14000);

  Serial.println("Done!!");
}

void loop()
{
  // do nothing
}
