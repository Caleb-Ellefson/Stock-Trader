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
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

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
    }
    fclose(filePtr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
