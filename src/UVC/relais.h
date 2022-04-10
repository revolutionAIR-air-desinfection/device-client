#define RELAIS D1

void relais_setup()
{
    pinMode(RELAIS, OUTPUT);
}

void relaisON() 
{
    digitalWrite(RELAIS, LOW);
}

void relaisOFF()
{
    digitalWrite(RELAIS, HIGH);
}
