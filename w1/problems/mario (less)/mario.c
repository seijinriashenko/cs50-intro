#include <stdio.h>
#include <cs50.h>

int get_height();
void print_pyramid(int);

int main(void) 
{
    int height = get_height();    
    print_pyramid(height);
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

// Print the right-aligned pyramid from Mario Bros.
void print_pyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // Printing the spaces
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }

        // Printing the hashes
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
