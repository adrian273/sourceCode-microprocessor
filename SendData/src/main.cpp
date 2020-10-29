// @since 10/28/2020
// @github adrian273 ( アドリアン )

#include <Arduino.h>

const int A = 4, B = 7, C = 12, D = 13;

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  Serial.begin(9600);
}

void loop()
{
  String ONMESSAGE = "ON";
  String OFFMESSAGE = "OFF";
 
  
  Serial.println("4");
}