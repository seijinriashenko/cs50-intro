#include <cs50.h>
#include <stdio.h>

int get_years(int, int);

int main(void)
{
    // Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    int years = get_years(start_size, end_size);
    
    // Print number of years
    printf("Years: %i\n", years);
}

// Calculate number of years until we reach threshold
int get_years(int start_size, int end_size)
{
    int n = start_size, years = 0; // starting with 0 years
    while (n < end_size)
    {
        // Each year n / 3 llamas are born and n / 4 llamas pass away, where n - current population size
        n += n / 3 - n / 4;
        years++;
    }
    return years;
}
