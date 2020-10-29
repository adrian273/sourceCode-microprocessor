/**
 * @since 10/25/2020
 * @GitHub adrian273
 * 
 * */

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 13, 5, 4, 3, 2);
const int SIGNAL = 7;


void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);

}

void loop()
{
  int volumen = analogRead(A0);
  lcd.println(volumen);
  Serial.println(volumen);
  delay(50);
}