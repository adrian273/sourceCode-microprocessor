/**
 * Adrian Verdugo ( アドリアン )
 * @github adrian273 
 * @since 11/3/2020
 * 
 * */

#include <Arduino.h>

int LED = 13;
int BUTTON = 7;
int reset = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  int signal = digitalRead(BUTTON);

  if (signal == HIGH)
  {
    digitalWrite(LED, HIGH);
    Serial.println("1");
  } else {
    digitalWrite(LED, LOW);
    Serial.println("0");
  }
}