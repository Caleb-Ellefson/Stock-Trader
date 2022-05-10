#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s);
char rotate(char p, int k);

int main(int argc, string argv[])
{
    int k, i, length;

    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Change argv[1] int an int
    k = atoi(argv[1]);

    string plain = get_string("plaintext: ");
    length = strlen(plain);
    char cypher[length+1];
    for(i = 0; i < length; i++)
    {
        cypher[i] = rotate(plain[i], k);
    }
        cypher[i] = '\0';

    printf("ciphertext: %s\n", cypher);
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
    char c;

    if(isupper(p))
    {
        c = (p - 'A' + k)%26 + 'A';
    }

    else if(islower(p))
    {
        c = (p - 'a' + k)%26 + 'a';
    }

    else
    {
        c = p;
    }

    return c;
}
