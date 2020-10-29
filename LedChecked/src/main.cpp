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
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  Serial.begin(9600);
}


void loop()
{
  if (Serial.available())
  {
    int c = Serial.read();
    if (c == '1')
    {
      digitalWrite(A, HIGH);
    }
    else if (c == '0')
    {
      digitalWrite(A, LOW);
    }
    else if (c == '2')
    {
      digitalWrite(B, HIGH);
    }
    else if (c == '3')
    {
      digitalWrite(B, LOW);
    }
    else if (c == '4')
    {
      digitalWrite(C, HIGH);
    }
    else if (c == '5')
    {
      digitalWrite(C, LOW);
    }
    else if (c == '6')
    {
      digitalWrite(D, HIGH);
    }
    else if (c == '7')
    {
      digitalWrite(D, LOW);
    }
  }
  
}