#include <cs50.h>
#include <stdio.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
// only 2 inputs on the command line
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        return 0;
    }
    // Make sure every character in argv[1] is a digit

    // Convert argv[1] from a `string` to an `int`

    // Prompt user for plaintext

    // For each character in the plaintext:

        // Rotate the character if it's a letter
}

bool only_digits(string s)
{
    for(int i = 0; i < strlen(s); i++)
    {
        if(!isdigit (s[i]))
            return false;
    }
    return true;
}

char rotate(char c, int n)
{
    for(int i = 0; i < strlen(s); i++)
    {
        if (isupper(s[i]))
        rotate = 
    }
}