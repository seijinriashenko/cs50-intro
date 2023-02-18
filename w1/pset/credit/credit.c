#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define AMEX 0
#define MASTERCARD 1
#define VISA 2
#define INVALID -1

int validate_card(long);
bool luhn(long, int);
int *get_digits_array(long, int);

int main(void) 
{
    long number = get_long("Number: ");
    // string number = get_string("Number: ");
    switch (validate_card(number))
    {
        case AMEX:
            printf("AMEX\n");
            break;
        case MASTERCARD:
            printf("MASTERCARD\n");
            break;
        case VISA:
            printf("VISA\n");
            break;
        default:
            printf("INVALID\n");
    }
}

// Validate the card number using the Luhn's Algorithm
// Return values:
// AMEX - American Express Card
// MASTERCARD - Mastercard Card
// VISA - Visa Card
// INVALID - invalid number
int validate_card(long number)
{
    if (number <= 0)
    {
        return INVALID;
    }

    // Validate the number of digits in the card number
    int digits = (int)ceil(log10(number));
    if (!(digits == 13 || digits == 15 || digits == 16))
    {
        return INVALID;
    }

    // Check the validity of the number and its first digits
    if (luhn(number, digits))
    {
        // First two digits of the number
        int first_digits = number / pow(10, digits - 2);

        if (first_digits / 10 == 4)
        {
            return VISA;
        }

        if (first_digits == 34 || first_digits == 37)
        {
            return AMEX;
        }

        if (first_digits >= 51 && first_digits <= 55)
        {
            return MASTERCARD;
        }
    }
    return INVALID;
}

// Luhn's Algorithm
bool luhn(long number, int digits) 
{
    // An array of digits which compound the card number
    int *digits_arr = get_digits_array(number, digits);
    // temp_num - temporary store every other digit, starting from the second-to-last one,
    // sum - store the sum of products' temp_num * 2 digits
    int temp_num = 0, sum = 0;

    // Calculate the sum of products' digits
    for (int i = digits - 2; i >= 0; i -= 2)
    {
        temp_num = digits_arr[i] * 2;
        while (temp_num > 0)
        {
            sum += temp_num % 10;
            temp_num /= 10;
        }
    }

    // Add digits that weren't multiplied by 2 to 'sum'
    for (int i = digits - 1; i >= 0; i -= 2)
    {
        sum += digits_arr[i];
    }

    // Deallocate the memory from under the pointer
    free(digits_arr);

    // If sum % 10 == 0, then we have a valid number (in terms of Luhn's Algorithm)
    return sum % 10 == 0;
}

int *get_digits_array(long number, int digits)
{
    int *arr = malloc(digits * sizeof(int));
    for (int i = digits - 1; i >= 0; i--)
    {
        arr[i] = number % 10;
        number /= 10;
    }
    return arr;
}
