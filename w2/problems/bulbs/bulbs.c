#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void convert_to_byte(bool byte[], int ch);
void print_byte(bool byte[]);
void clear_byte(bool byte[]);
void print_bulb(int bit);

int main(void)
{
    string msg = get_string("Message: ");
    bool byte[BITS_IN_BYTE] = {0};

    for (int i = 0, ascii_code; msg[i]; i++)
    {
        ascii_code = msg[i];
        convert_to_byte(byte, ascii_code);
        print_byte(byte); // byte is filled now
        clear_byte(byte);
    }
}

// Convert the given 'char' into a byte and write it into the byte[] array
void convert_to_byte(bool byte[], int ch)
{
    for (int i = BITS_IN_BYTE - 1; ch > 0; i--)
    {
        byte[i] = ch % 2;
        ch /= 2;
    }
}

// Print the given byte in the form of bulbs
void print_byte(bool byte[])
{
    // print bulbs
    for (int i = 0; i < BITS_IN_BYTE; i++)
    {
        print_bulb(byte[i]);
    }
    // print a new line
    printf("\n");
}

// Refill the byte with 0-bits again
void clear_byte(bool byte[])
{
    for (int i = 0; i < BITS_IN_BYTE; i++)
    {
        byte[i] = 0;
    }
}

// Print a bulb that corresponds to the given 'bit'
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

