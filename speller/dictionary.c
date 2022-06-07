// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int key = hash(word);
    node* nodePtr = table[key];

    while(nodePtr == NULL)
    {
        if(strcasecmp(nodePtr->word, word) == 0)
        {
            return true;
        }
        nodePtr = nodePtr->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int value = 0;

    for(int i = 0; word[i]!= '\0'; i++)
    {
        value += tolower(word[i]);
    }
    // TODO: Improve this hash function
    return value % N;
}

int wordcount = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE* filePtr = fopen(dictionary, "r");
    if (filePtr == NULL)
    {
        return false;
    }

    for(int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char tmpword[LENGTH + 1];

    while(fscanf(filePtr, "%s\n", tmpword) != EOF)
    {
        node* tmpNode = malloc(sizeof(node));

        strcpy(tmpNode->word, tmpword);

        int key = hash(tmpword);

        if(table[key] == NULL)
        {
            tmpNode->next = NULL;
            table[key] = tmpNode;
        }
        else
        {
            tmpNode->next = table[key];
            table[key] = tmpNode;
        }
        wordcount++;
    }
    fclose(filePtr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
