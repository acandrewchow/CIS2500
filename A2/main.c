#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include "fleschIndex.h"
int main(int argc, char * argv[]) {

// Variable Declarations
    char * filename = argv[1];
    char * string;
    int syllables, words, fleshIndex, sentences;

// Populate string with contents in filename read from cmd prompt
    string = readFile(filename);
    printf("\n");

// Function calls to assign variables values
words = countTotalWords(string);
sentences = countTotalSentences(string);
syllables = countTotalSyllables(string);
fleshIndex = calculateFleschIndex(syllables, words, sentences);

// Outputs the flesh scores
outputFormattedFleschScores(syllables, words, fleshIndex, sentences);

// Free excess memory
free(string);
}
