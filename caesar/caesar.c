#include <cs50.h>
#include <stdio.h>

bool only_digits(string s);
string plaintext;
int k = atio(argv[1]);
int main(int argc, string argv[])
{
    int k, length;
    string p;
// only 2 inputs on the command line
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    p = get_string("ciphertext: ");
    length = strlen(p);
    char cypher[length + 1];
    for (int i = 0; i < length; i++)
    {
        cypher[i] = rotate(p[i]);
    }
    cypher[1] = '\0';

    printf("ciphertext: %s",cypher);
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
    char c;
string p = plaintext;
    if (isupper(p))
    {
        c = (p - 'A' + k) % 26 + 'A';
    }
    else if (islower(p))
    {
        c = (p - 'a' + k) % 26 + 'a';
    }
    else
    {
        c = p;
    }

    return c;
}