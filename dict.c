#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dict.h"

Trie* trieCreate() {
    Trie *root = (Trie *)malloc(sizeof(Trie));
    memset(root, 0, sizeof(Trie));
    return root;
}
// Create an empty Dict
Dict make_dict() {
    Trie *dict = (Trie *) malloc(sizeof(Trie));
    if (dict == NULL) {
        return NULL;
    }
    return (Dict) dict;
}
void trieFree(Trie* obj) {
    for (int i = 0; i < 26; i++) {
        if (obj->next[i]) {
            trieFree(obj->next[i]);
        }
    }
    free(obj);
}
// Free up all memory allocated to a Dict (including char* keys)
void free_dict(Dict dict_adt) {
    if (dict_adt == NULL) {
        return;
    }
    Trie *dict = (Trie *) dict_adt;
    trieFree(dict);
}

// Get a pointer to the value associated with key
// (returns NULL if no such value exists)
int *get(Dict dict_adt, const char *key) {
    if (dict_adt == NULL) {
        return NULL;
    }
    Trie *dict = (Trie *) dict_adt;
    for (int i = 0; i < strlen(key); i++) {
        if (dict->next[key[i] - 'a'] == NULL) {
            return NULL;
        }
        dict = dict->next[key[i] - 'a'];
    }
    if (dict->isEnd) {
        return &dict->isEnd;
    }
    return NULL;
}

// Set the value associated with key to value
// while maintaining insertion order
// (returns 1 if successful, 0 if not)
void trieInsert(Trie* obj,const char * word,int val) {
    Trie *node = obj;
    for (int i = 0; word[i]; i++) {
        if (!node->next[word[i] - 'a']) {
            node->next[word[i] - 'a'] = trieCreate();
        }
        node = node->next[word[i] - 'a'];
    }
    node->isEnd = val;
}
int set(Dict dict_adt, const char *key, int value) {
    if (dict_adt == NULL) {
        return 0;
    }
    Trie *dict = (Trie *) dict_adt;
    trieInsert(dict, key, value);
    return 1;
}
void printAllWords(Trie* obj, char* word, int index){
    if(obj->isEnd){
        word[index] = '\0';
        printf("%s:%d\n", word, obj->isEnd);
    }
    for(int i = 0; i < 26; i++){
        if(obj->next[i]){
            word[index] = i + 'a';
            printAllWords(obj->next[i], word, index + 1);
        }
    }
}

// Print the contents of the dictionary
void print_dict(Dict dict_adt) {
    if (dict_adt == NULL) {
        return;
    }
    Trie *dict = (Trie *) dict_adt;
    char word[100];
    printAllWords(dict, word, 0);
}
