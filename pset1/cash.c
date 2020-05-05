//first asks the user how much change is owed and then prints the minimum number of coins with which that change can be made.
// 0.25, 0.10, 0.5, 0.1

#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_positive_float(void);

int main(void)
{
    float i = get_positive_float();
    int cents = round(i * 100);
    int coins = 0;
    while (cents > 0)
    {
        if (cents >= 25)
        {
            coins++;
            cents = cents - 25;
        }
        else if (cents >= 10)
        {
            coins++;
            cents = cents - 10;
        }
        else if (cents >= 5)
        {
            coins++;
            cents = cents - 5;
        }
        else
        {
            coins++;
            cents = cents - 1;
        }
    }
    printf("%i\n", coins);
}

float get_positive_float(void)
{
    float n;
    do
    {
        n = get_float("Change owed:  ");
    }
    while (n < 0);
    return n;
}












