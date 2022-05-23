class RGB
{
public:
    unsigned int r;
    unsigned int g;
    unsigned int b;

    RGB(unsigned int red, unsigned int green, unsigned int blue)
    {
        r = red;
        g = green;
        b = blue;
    }
};

//? splits String and returns the requested snipped
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = {0, -1};
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++)
    {
        if (data.charAt(i) == separator || i == maxIndex)
        {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i + 1 : i;
        }
    }

    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

RGB stringToRGB(String s)
{
    int r = getValue(s, ',', 0).toInt();
    int g = getValue(s, ',', 1).toInt();
    int b = getValue(s, ',', 2).toInt();

    return RGB(r, g, b);
}
