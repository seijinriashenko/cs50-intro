#include <cs50.h>
#include <stdio.h>

int get_height();
void print_pyramids(int);

int main(void) 
{
    int height = get_height();    
    print_pyramids(height);
}

// Get a height of the pyramid (int values in [1,8]) to print
int get_height()
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

// Print two adjacent pyramids from Mario Bros.
void print_pyramids(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // Print the spaces
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        // Print the first pyramid
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        // Print the blank space between pyramids
        printf("  ");
        
        // Print the second pyramid 
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
