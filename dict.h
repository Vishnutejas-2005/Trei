#ifndef DICT_H
#define DICT_H

#include "dict_adt.h"

#define DICT_SIZE 100

typedef struct trie{
    struct trie *next[26];
    int isEnd;
} Trie;

#endif