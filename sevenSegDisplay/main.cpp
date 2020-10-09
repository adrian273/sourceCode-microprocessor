/**
 * @author Adrian Verdugo
 * @GitHub adrian273
 * @since 10/6/2020
 * */
// ------------------------------------------------------------------------------------------
int B = 1, A = 2, F = 3, G = 4, C = 5, D = 6, E = 7;
//-------------------------------------------------------------------------------------------
int PIN_LIST[] = {B, A, F, G, C, D, E};
int ARR_SIZE = sizeof(PIN_LIST) / sizeof(PIN_LIST[0]);
//-------------------------------------------------------------------------------------------
int COMBINATION[][7] = {
    {B, C}, {A, B, G, E, D}, {A, B, C, D, G}, {F, G, B, C}, {A, F, G, C, D}, {F, E, D, C, G}, 
    {A, B, C, G}, {A, B, G, F, C, D, E}, {A, F, G, B, C}};
int ZERO[] = {A, B, C, D, E, F};
// ------------------------------------------------------------------------------------------
int START_STATUS = 0;
int BACK_STATUS = 0;
int RESET_STATUS = 0;
// ------------------------------------------------------------------------------------------

void setup()
{
    for (int i = 0; i < ARR_SIZE; i++)
    {
        pinMode(PIN_LIST[i], OUTPUT);
    }
    reset(false);
}

void loop()
{
    START_STATUS = digitalRead(8);
    BACK_STATUS = digitalRead(9);
    RESET_STATUS = digitalRead(10);

    if (START_STATUS == HIGH)
    {
        reset(true);
        start();
    }
    else if (BACK_STATUS == HIGH)
    {
        reset(true);
        back();
    }
    else if (RESET_STATUS == HIGH)
    {
        reset(false);
    }
}

void start()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            digitalWrite(COMBINATION[i][j], HIGH);
        }
        if (i != 8)
        {
            delay(500);
            reset(true);
        }
    }
}

void back()
{
    for (int i = 8; i >= 0; i--)
    {
        for (int j = 6; j >= 0; j--)
        {
            digitalWrite(COMBINATION[i][j], HIGH);
        }
        if (i != 0)
        {
            delay(500);
            reset(true);
        }
    }
}

void reset(bool z)
{
    for (int i = 0; i < ARR_SIZE; i++)
    {
        digitalWrite(PIN_LIST[i], LOW);
        //delay(1000);
    }
    if (z == false)
    {
        for (int j = 0; j < 6; j++)
        {
            digitalWrite(ZERO[j], HIGH);
        }
    }
}
