#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    // Print the winner
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    {
        if (score1 > score2)
            {
                printf("Player 1 wins!");
            }
        else if (score1 == score2 )
            {
                printf("It's a draw!");
            }
            else
            {
                printf("Player 2 wins!");
            }
    }

    // TODO: Print the winner
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
int score = 0;
for(int i = 0, len = strlen(word); i < len; i++)

    if (isupper(word[i]))
    {
        //Going through the array of points [i] taking the ASKII vaule of each char of "word" - 65 to match ASKII key then number of times adding the sum to "score" each time.
        score += POINTS[word[i] - 'A'];
    }
    else if (islower(word[i]))
    {
        score += POINTS[word[i] - 'a'];
    }

}
