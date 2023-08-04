#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

// convert a positive integer represented by a string into an actual int
int convert(string input)
{
    // if the 1st char is '\0', then return 0
    if (!input[0])
    {
        return 0;
    }

    int len = strlen(input);
    int last_digit = input[len - 1] - '0'; // retrieve the last digit of the string
    input[len - 1] = 0; // assign '\0' instead of the last digit to shorten the string

    return last_digit + convert(input) * 10;
}
