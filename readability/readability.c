#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_words(string t);
int count_letters(string t);
int count_sentences(string t);
float index (string t, int count_words, int count_sentences, int count_letters);

int main(void)
{
//Your program must prompt the user for a string of text using get_string.
    {
        string t = get_string ("Text: ");
    }
//your program should output "Grade 16+"
if (index > 16);
int grade;
    {
    {
        printf("Grade 16+\n");
    }

    else if (index < 1);
    {
        printf("Before Grade 1\n");
    }

    else (int grade; grade = index;)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    }
}
//Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
float index (int count_words, int count_sentences, int count_letters)
{
    float l = (count_letters / count_words);
    float s = (count_sentences / count_words);
    float index = (0.0588 * l - 0.296 * s - 15.8);
        round(index);
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