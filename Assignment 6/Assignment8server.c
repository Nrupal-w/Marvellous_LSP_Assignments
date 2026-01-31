#include <ctype.h>

int CountUpper(char *str)
{
    int count = 0;
    while (*str)
    {
        if (isupper(*str))
            count++;
        str++;
    }
    return count;
}

int CountLower(char *str)
{
    int count = 0;
    while (*str)
    {
        if (islower(*str))
            count++;
        str++;
    }
    return count;
}

int CountDigit(char *str)
{
    int count = 0;
    while (*str)
    {
        if (isdigit(*str))
            count++;
        str++;
    }
    return count;
}
