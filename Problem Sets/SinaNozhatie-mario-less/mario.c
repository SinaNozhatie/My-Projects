#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int n;

    int j = 1;

    // Picking Posetive number between 1 and 8
    do
    {
        n = get_int("posetive number:");
    }
    while (n > 8 || n < 1);

    for (int i = 1; i <= n; i++) // Height
    {
        int m = n - j; // number of needed space

        for (int k = m; k > 0; k--) // making space

        {
            printf(" ");
        }
        for (j = 1; j <= i; j++) // hash
        {
            printf("#");
        }

        printf("\n");
    }
}