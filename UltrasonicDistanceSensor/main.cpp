/**
 * 
 * @author Adrian Verdugo
 * @github adrian273
 * @since 10/8/2020
 * 
 * */

const int SIGNAL = 7;
const int LEFT = 13;
const int RIGHT = 12;

void setup()
{
    Serial.begin(9600);
    pinMode(LEFT, OUTPUT);
    pinMode(RIGHT, OUTPUT);
}

void loop()
{
    long duration;
    long cm;

    pinMode(SIGNAL, OUTPUT);
    digitalWrite(SIGNAL, LOW);
    delayMicroseconds(2);

    digitalWrite(SIGNAL, HIGH);
    delayMicroseconds(5);
    digitalWrite(SIGNAL, LOW);

    pinMode(SIGNAL, INPUT);
    duration = pulseIn(SIGNAL, HIGH);

    cm = microsecondsToCentimeters(duration);
    if (cm >= 336)
    {
        digitalWrite(SIGNAL, LOW);
        Serial.print("\n No signal:[motor off]\t");
    }
    if (cm > 0 && cm < 10)
    {
        Serial.print("\n Turn Right:[motor on]\t");
        turnRight();
    }
    else if (cm > 10 && cm < 336)
    {
        Serial.print("\n Turn Left:[motor on]\t");
        turnLeft();
    }
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
}

void turnLeft()
{
    digitalWrite(LEFT, HIGH);
    delay(1000);
    digitalWrite(LEFT, LOW);
}

void turnRight()
{
    digitalWrite(RIGHT, HIGH);
    delay(1000);
    digitalWrite(RIGHT, LOW);
}

long microsecondsToCentimeters(long microseconds)
{
    return microseconds / 29 / 2;
}