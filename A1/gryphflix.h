#define NUMBER_REVIEWERS 10
#define NUMBER_MOVIES 3
#define MAX_STR 50
#define MAX_WORDS 10
#include <stdio.h>
#include <string.h>
#include <stdbool.h>



struct reviewStruct {
    
 char reviewer[MAX_STR];
 int feedback[NUMBER_MOVIES];

};
