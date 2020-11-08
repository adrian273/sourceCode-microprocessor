// @since 10/28/2020
// @github adrian273 ( アドリアン )
// 10/29/2020


#include <Arduino.h>


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int i = analogRead(A1);
  int pos = map(i, 0, 1023, 0, 100);
  Serial.println(pos);
  delay(1000);
}