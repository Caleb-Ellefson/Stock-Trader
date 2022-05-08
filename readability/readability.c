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
//our program should count the number of letters, words, and sentences in the text.
// any sequence of characters separated by spaces should count as a word and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
//Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
//If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".

}

// a string of text, and that returns an int, the number of letters in that text.
int count_letters(string t)
{
    int count_letters = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        count_letters++;
    }
    return count_letters;
    }

int count_sentences(string t)
{
    int count_sentences = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if t[i] == '!' t[i] == '.' t[i] == '?'
        {
            count_sentences++;
        }
    }
        return count_sentences;
}