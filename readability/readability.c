#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string t);
int count_sentences(string t);

int main(void)
{
//Your program must prompt the user for a string of text using get_string.
    {
        string t = get_string ("Text: ");
        printf("%s\n", t);
    }
//If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".

}
//Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
float l (string t, int count_words, int count_sentences, int count_letters)
{
    float l == (count_words / 100);
    float s == (count_setences / count_words);
}

//Calculate how many letters are in the string.
int count_letters(string t)
{
    int count_letters = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        count_letters++;
    }
    return count_letters;
    }
//Calculate how many sentences are in the string.
int count_sentences(string t)
{
    int count_sentences = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (t[i] == '!' || t[i] == '.' || t[i] == '?')
        {
            count_sentences++;
        }
    }
        return count_sentences;
}
//Calculate how many words are in the string.
int count_words(string t)
{
    int count_words = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (t[i] == " ");
        {
            count_words++;
        }
    return count_words;
    }
}