#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_words(string t);
int count_letters(string t);
int count_sentences(string t);
int index (string t, int count_words, int count_sentences, int count_letters);

int main()
{
    {
        //prompt the user for a string of text using get_string.
        string t = get_string ("Text: ");
    }

    int count_words(string t);
    int count_letters(string t);
    int count_sentences(string t);
    int index(count_words, count_sentences, count_letters);

    if (index >= 16)
        printf("Grade 16+");

    else if (index < 1)
        printf("Before Grade 1\n");

    else
        printf("Grade %i\n",(int) round(index));
}

//Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
int index (string t, int count_words, int count_sentences, int count_letters)
{
    float l = (float) count_letters / count_words;
    float s = (float) count_sentences / count_words;
    int index = round(0.0588 * l - 0.296 * s - 15.8);

    return index;
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
    int count_words = 1;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (t[i] == ' ')
        {
            count_words++;
        }
    }
    return count_words;
}