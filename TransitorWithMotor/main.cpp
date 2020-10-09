void setup()
{
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop()
{
    if (digitalRead(13) == HIGH)
    {
        turnLeft();
    }
    else if (digitalRead(12) == HIGH)
    {
        turnRight();
    }
}

void turnLeft()
{
    digitalWrite(13, HIGH);
    delay(10000); // Wait for 10000 millisecond(s)
    digitalWrite(13, LOW);
}

void turnRight()
{
    digitalWrite(12, HIGH);
    delay(10000); // Wait for 10000 millisecond(s)
    digitalWrite(12, LOW);
}