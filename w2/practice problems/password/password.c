// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// Check if the given password is valid, i.e. it comprises at least one uppercase letter, lowercase letter, number (digit) and symbol
bool valid(string password)
{
    bool has_upper = false, has_lower = false, has_digit = false, has_symbol = false;
    for (int i = 0; password[i]; i++)
    {
        if (isupper(password[i]))
        {
            has_upper = true;
        }
        else if (islower(password[i]))
        {
            has_lower = true;
        }
        else if (isdigit(password[i]))
        {
            has_digit = true;
        }
        else
        {
            has_symbol = true;
        }
    }
    return has_upper && has_lower && has_digit && has_symbol;
}
