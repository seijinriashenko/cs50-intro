#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int ALPHABET_LEN = 26;

int strtoi(string str);

// a-z (65 - 91); A-Z (97-123)
int main(int argc, string argv[])
{
    // we cannot check for 'strtoi' return value here, because we don't know
    // the exact number of command-line arguments that were passed yet
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // now we know that argc == 2, that's why we can use 'strtoi'
    int k = strtoi(argv[1]);
    if (k == -1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    k %= ALPHABET_LEN;
    // Prompt user for a string of plain text
    string plain = get_string("plaintext:  ");
    printf("ciphertext: ");
    // Print a cipher-text shifted by k symbols forward
    for (int i = 0, ch; plain[i]; i++)
    {
        if (isupper(plain[i]))
        {
            // subtract 'A' from the given uppercase letter to remove the 65-chars-shift
            // (as if the alphabet starts at 0)
            ch = 'A' + (plain[i] - 'A' + k) % ALPHABET_LEN;
        }
        else if (islower(plain[i]))
        {
            // subtract 'a' from the given lowercase letter to remove the 97-chars-shift
            // (as if the alphabet starts at 0)
            ch = 'a' + (plain[i] - 'a' + k) % ALPHABET_LEN;
        }
        else // not an upper-/lowercase letter
        {
            ch = plain[i];
        }
        printf("%c", ch);
    }
    printf("\n");
}

// Convert a string to a non-negative integer if it represents a valid positive number or 0;
// if not - return -1
int strtoi(string str)
{
    const int offset = 48; // offset in ASCII for 0
    int number = 0;

    for (int i = 0; str[i]; i++)
    {
        number *= 10;
        if (!isdigit(str[i]))
        {
            return -1;
        }
        number += str[i] - offset;
    }
    return number;
}
