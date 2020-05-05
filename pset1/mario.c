#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    for (int r = 0; r < h; r++)
    {
        for (int d = 0; d < h - 1 - r; d++)
        {
            printf(" ");
        }
        for (int c = 0; c <= r; c++)
        {
            printf("#");
        }
        printf("\n");
    }
}







