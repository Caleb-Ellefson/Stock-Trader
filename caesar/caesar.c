#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s);
char rotate(char p, int k);

int main(int argc, string argv[])
{
    int k;

    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Change argv[1] int an int
    k = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

}

bool only_digits(string s)
{
    int length = strlen(s);
    for(int i = 0; i < length; i++)
    {
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}

char rotate(char p, int k)
{
    c = (p + k)%26;
    
}
