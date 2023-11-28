// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

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
int dicto = 0;    // make a variable for doctionary

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_x = hash(word);   // amke a hash table for hash_x
    node *n = table[hash_x];
    while(n != NULL)
    {
        if(strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    long count = 0;
    for(int i=0 ; i < strlen(word) ; i++)
    {
        count += tolower(word[i]);
    }
    return count % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dic_p = fopen(dictionary, "r");    // open the dictionary file
    if(dictionary == NULL) // if this is null
    {
        printf("unable to open %s\n", dictionary);
        return false;
    }
    char n_word_n[LENGTH + 1];
    while(fscanf(dic_p, "%s\n", n_word_n) != EOF)   // eof for end of file
    {
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return false;
        }
        strcpy(n->word , n_word_n); // copy of word in n
        int hash_x = hash(n_word_n);
        n -> next = table[hash_x];
        table[hash_x] = n;
        dicto ++;
    }
    fclose(dic_p);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dicto;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0 ; i < N ; i++)
    {
        node *n = table[i];
        while(n != NULL)
        {
            node *ttt = n;
            n = n -> next;
            free(ttt);
        }
        if(n == NULL && i == N-1)
        {
            return true;
        }
    }
    return false;
}
