#include <stdio.h>

int counter = 0;

void Increment()
{
    counter++;
}

void Display()
{
    printf("Counter value = %d\n", counter);
}

void Reset()
{
    counter = 0;
}
