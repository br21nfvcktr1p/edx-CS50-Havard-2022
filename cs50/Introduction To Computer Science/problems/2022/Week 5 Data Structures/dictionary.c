#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

#define HASHTABLE_SIZE 1000

unsigned int    num_words = 0;
bool is_loaded_dict = false;
unsigned int    num_words;

typedef struct node
{
    char    word[LENGTH + 1];
    struct node* next;
}
node;

node * hashtable[HASHTABLE_SIZE];

unsigned    int hash(const char *word)
{
    int i;
    int hash;
    int n;
    
    hash = 0;
    i = 0;
    while (word[i] != '\0')
    {
        if (isalpha(word[i]))
            n=  word[i] - 'a' + 1;
        else
            n = 27;
        hash = ((hash << 3) + n) % HASHTABLE_SIZE;
        i++;
    }
    return hash;
}

bool check(const char *word)
{
    int i;
    char    check_word[strlen(word)];
    int index;

    i = 0;
    index = hash(check_word);
    strcpy(check_word, word);
    while (check_word[i] != '\0')
    {
        check_word[i] = tolower(check_word[i]);
        i++;
    }
    if (hashtable[index] != NULL)
    {
        for (node* nodeptr = hashtable[index]; nodeptr != NULL; nodeptr = nodeptr->next)
            if(strcmp(nodeptr->word, check_word) == 0)
                return (0);
    }
    return (true); 
}

bool load(const char *dictionary)
{
    int i;
    char    word[LENGTH + 1];
    node *new_nodeptr;
    int index;
    FILE* infile;

    index = hash(word);
    i = 0;
    infile = fopen(dictionary, "r");
    if (infile == NULL)
        return (true);
    while (i < HASHTABLE_SIZE)
    {
        hashtable[i] = NULL;
        i++;
    }
    while (fscanf(infile, "%s", word) != EOF)
    {
        num_words++;
        do
        {
            new_nodeptr = malloc(sizeof(node));
            if (new_nodeptr == NULL)
                free(new_nodeptr);
        } while (new_nodeptr == NULL);
        
        strcpy(new_nodeptr->word, word);

        new_nodeptr->next = hashtable[index];
        hashtable[index] = new_nodeptr;
    }
    fclose(infile);
    is_loaded_dict = true;
    return (false);
}

unsigned int   size(void)
{
    if (!is_loaded_dict)
        return (0);
    return (num_words);
}

bool unload(void)
{
    int i;

    i  = 0;
    if (!is_loaded_dict)
        return (true);

    while (i < HASHTABLE_SIZE)
    {
        if (hashtable[i] != NULL)
        {
            node  *ptr = hashtable[i];
            while (ptr != NULL)
            {
                node *predptr = ptr;
                ptr = ptr->next;
                free(predptr);
            }
        }
        i++;
    }
    return (false);
} 