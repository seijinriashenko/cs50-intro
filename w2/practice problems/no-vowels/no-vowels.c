// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    printf("%s\n", replace(argv[1]));
    return 0;
}

// a function to replace alphabetical characters with their corresponding number, similar to 'leetspeak'
// word - a string to which we apply changes
string replace(string word)
{
    int i = 0;
    // iterate till word[i] == '\0'
    while (word[i])
    {
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
        }
        i++;
    }
    return word; // return the modified string (actually we don't need to return anything, 'cause string word == char *word[n])
}
