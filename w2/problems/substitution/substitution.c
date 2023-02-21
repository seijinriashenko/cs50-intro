#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Pseudocode:
// 1. A user executes the program providing command-line arguments of number argc.
// 2. If argc 2 return -1 and print an error message.
// 3. If argc == 1 and the only cli argument, which is a cipher key,
//    is incorrect (i.e. doesn't contain ONLY each alphabet letter ONLY ONCE),
//    then return -1 and print an error message.
// 4. If the given key is valid, perform the substitution.

const int ALPHA_LEN = 26;

bool is_valid_key(string key);
void substitute(string text, string key);

int main(int argc, string argv[])
{
    // argument count is not 2 - exit
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // not valid key - exit
    if (!is_valid_key(argv[1]))
    {
        printf("Key must contain all 26 alphabetical characters, nothing more, nothing less.\n");
        return 1;
    }

    // key is valid - perform the substitution
    string plain = get_string("plaintext:  ");
    substitute(plain, argv[1]);
}

// Check if the given key string is valid (statisfies the condition of the problem; see above)
bool is_valid_key(string key)
{
    // If the string is longer than 26 chars we don't need to continue validating it
    if (strlen(key) != ALPHA_LEN)
    {
        return false;
    }

    // Convert all key's chars to lowercase correspondents
    for (int i = 0; key[i]; i++)
    {
        key[i] = tolower(key[i]);
    }

    // Examine the key; it should satisfy the condition (see pseudocode above)
    for (int ch = 'a'; ch <= 'z'; ch++)
    {
        if (!strchr(key, ch)) // if we couldn't find a symbol between in the range a-z
        {
            return false;
        }
    }
    // the key is correct
    return true;
}

// Perform a substitution and print the resulting ciphertext
void substitute(string text, string key)
{
    printf("ciphertext: ");
    for (int i = 0, ch; text[i]; i++)
    {
        if (isupper(text[i]))
        {
            ch = toupper(key[text[i] - 'A']);
        }
        else if (islower(text[i]))
        {
            // key's characters are already in the lowercase
            ch = key[text[i] - 'a'];
        }
        else
        {
            ch = text[i];
        }
        printf("%c", ch);
    }
    printf("\n");
}
