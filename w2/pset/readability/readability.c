#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = (letters > 0) ? count_words(text) : 0;
    int sentences = (words > 0) ? count_sentences(text) : 0;

    // L - average number of letters/100 words
    float L = (float)letters / words * 100;
    // S - average number of sentences/100 words
    float S = (float)sentences / words * 100;

    // calculcate the Coleman-Liau index of the given text
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // if index < 1, then the text is for readers before grade 1
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    // if index > 16, then we don't need to bother by whom exactly the text is meant to be read
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    // finally, print the precise grade of the text if it's between 1 and 16 inclusively
    else
    {
        printf("Grade %i\n", index);
    }
}

// Count a number of letter in the given text
// letter is either a-z or A-Z
int count_letters(string text)
{
    int count = 0;
    for (int i = 0; text[i]; i++) {
        // count each alphabetical symbol as a letter (i.e. characters a-z or A-Z)
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Count a number of words in the given text
// word is a continuous sequence of non-space symbols (i.e. a sequence without ' ', '\t', '\n' etc)
int count_words(string text)
{
    int i = 0, count = 0;
    while (text[i])
    {
        // while the char is not an alphabetical symbol
        while (text[i] && !isalpha(text[i]))
        {
            i++;
        }

        // if we reached the '\0', then exit the loop
        if (!text[i])
        {
            break;
        }

        // a word may contain symbol "'" or "-"
        while (isalpha(text[i]) || text[i] == '\'' || text[i] == '-')
        {
            i++;
        }

        count++;
    }
    return count;
}

// Count a number of sentences in the given text
// sentence is any sequence of alphabetical characters that ends with '.', '!', or '?'
int count_sentences(string text)
{
    int i = 0, count = 0;
    while (text[i])
    {
        // while the char is not an alphabetical symbol
        while (text[i] && !isalpha(text[i]))
        {
            i++;
        }

        // iterate through the text until we find characters '.', '!', or '?', or reach the '\0'
        while (text[i] && text[i] != '.' && text[i] != '!' && text[i] != '?')
        {
            i++;
        }

        // if we didn't reach the '\0', count the traversed sequence of characters as a sentence
        if (text[i])
        {
            count++;
        }
    }
    return count;
}
