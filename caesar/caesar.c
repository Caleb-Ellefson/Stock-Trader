#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char p, int k);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
        return 0;

int atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
}

bool only_digits(string s)
{
    int length = strlen(s);
    for(int i = 0; i < length; i++)
    {
        if(!isdigit(s[i]));
            return false;
    }
    return true;
}