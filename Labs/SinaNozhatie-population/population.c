#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    int start_no_change = start;

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    int years = 0;

    // TODO: Calculate number of years until we reach threshold
    int i;

    do
    {
        // printf("s: %i\n", start);
        start = start + (start / 3) - (start / 4);
        // printf("y: %i\n", years);
        years++;
    }
    while (start < end);

    // TODO: Print number of years
    if (start_no_change == end)
    {
        printf("Years: 0\n");
    }

    else
    {
        printf("Years: %i\n", years);
    }
}
