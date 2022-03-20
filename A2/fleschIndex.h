/*
 Student Name: Andrew Chow 
 Student ID: 1088114
 Due Date: Feb 26, 2021
 Course: CIS*2500
 I have exclusive control over this submission via my password.
 By including this header comment, I certify that:
 1) I have read and understood the policy on academic integrity.
 2) I have completed Moodle's module on academic integrity.
 3) I have achieved at least 80% on the academic integrity quiz
 I assert that this work is my own. I have appropriate acknowledged
 any and all material that I have used, be it directly quoted or
 paraphrased. Furthermore, I certify that this assignment was written
 by me in its entirety.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

// Function Prototypes
char * readFile(char * filename);
int calculateFleschIndex(int syllables, int words, int sentences);
void outputFormattedFleschScores(int syllables, int words, int fleshIndex, int sentenceCount);
int countTotalWords(char * content);
int isVowel(char letter);
int isWordEnd(char letter);
int countTotalSyllables(char * content);
int countTotalSentences(char * content);
