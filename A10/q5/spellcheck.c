// spellcheck.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "dictionary.h"
#include "file2strqueue.h"

// for convenience: this is how you represent an apostrophe (')
const char apostrophe = '\'';

// a simple void * wrapper for strcmp
int strcmp_wrapper(const void *a, const void *b) {
  assert(a);
  assert(b);
  const char *str_a = a;
  const char *str_b = b;
  return strcmp(str_a, str_b);
}

// Because the Dictionary ADT uses key/value pairs,
// and for the wordlist dictionary, we only need keys
// we can use the VALID pointer for every value
int valid = 1;
void *VALID = &valid;

// but we don't want our Dictionary ADT free-ing VALID,
// so we need a function that does not free anything
// (to pass to the create_Dictionary function)
void do_nothing(void *p) {
  return;
}

bool contain_special (char *str){
    bool special = false;
    for (int i=0; i<strlen(str); i++){
        if (str[i]==0){
            break;
        }
        else if ((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122) || str[i]==39) {
        }
        else {
            special = true;
        }
    }
    return special;
}

bool in_wordlist (Dictionary dict, char *str){
    char temp[strlen(str)];
    int i = 0;
    for (i=0; i<strlen(str); i++){
        if (str[i]>=65 && str[i]<=90){
            temp[i] = str[i] + 32;
        }
        else {
            temp[i] = str[i];
        }
    }
    temp[i]=0;
    void *result = lookup(dict, temp);
    if (result){
        return true;
    }
    return false;
}

char *autocorrect(Dictionary dict, char *str){
    char *result = lookup(dict, str);
    if (result){
        return result;
    }
    else{
        return NULL;
    }
}

int main(void) {
    Dictionary wordlist = create_Dictionary(strcmp_wrapper, free, do_nothing);
    StrQueue sq = file2StrQueue("wordlist.txt");
    while (sq_length(sq)) {
        char *word = sq_remove_front(sq);
        insert(wordlist, word, VALID);
    }
    destroy_StrQueue(sq);
    sq = NULL;

    // the rest is up to you... have fun!
    Dictionary dict = create_Dictionary(strcmp_wrapper, free, free);
    sq = file2StrQueue("autocorrect.txt");
    while (sq_length(sq)) {
        char *key = sq_remove_front(sq);
        char *value = sq_remove_front(sq);
        insert(dict, key, value);
    }
    destroy_StrQueue(sq);
    sq = NULL;
    
    char input[64];
    int count = 0;
	while (scanf("%s", input)!=EOF){
        if (count%10==0 && count>0){
            printf("\n");
        }
        else if (count>0){
            printf(" ");
        }
        count++;
        char *correction = autocorrect(dict, input);
        if (contain_special(input)){
            printf("_%s_", input);
        }
        else if (in_wordlist(wordlist, input)){
            printf("%s", input);
        }
        else if (correction){
            printf("*%s*", correction);
        }
        else {
            printf("[%s]", input);
        }
	}
    printf("\n");
    
    // don't forget to free your memory
    destroy_Dictionary(wordlist);
    destroy_Dictionary(dict);
}
