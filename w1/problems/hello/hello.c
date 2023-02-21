#include <stdio.h>
#include <cs50.h>

// A program to greet a user
int main(void)
{
    string name = get_string("What's your name? ");
    printf("Hello, %s!\n", name);
    return 0;
}
