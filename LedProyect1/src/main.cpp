// @since 10/21/2020
// @github adrian273 ( アドリアン )

#include <Arduino.h>

const int LED = 2;

int i;

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  for (i = 1; i < 255; i++)
  {
    analogWrite(LED, i);
    delay(5);
  }

  for (i = 255; i > 0; i--)
  {
    analogWrite(LED, i);
    delay(5);
  }
}