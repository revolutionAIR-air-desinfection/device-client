#define RELAIS D1

void relais_setup()
{
    pinMode(RELAIS, OUTPUT);
}

void relaisON() 
{
    digitalWrite(RELAIS, HIGH);
}

void relaisOFF()
{
    digitalWrite(RELAIS, LOW);
}
