#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include "fleschIndex.h"

// Opens file and reads its contents, then returns the content
char * readFile (char * filename)  {

// Variable Declarations
    int fileSize = 0;
    FILE * fptr;
    char * content;

        fptr = fopen(filename, "r");

        if (fptr == NULL) {

            printf("Cannot open the file for readMode\n");
	    // Exit the program if the file cannot be opened
	    exit(1);
        }
        else {

        fseek(fptr, 0, SEEK_END); // seek to end of file
        fileSize = ftell(fptr);   // get position of file pointer
        fseek(fptr, 0, SEEK_SET); // seek back to beginning of file

        printf("Size of File: %d\n", fileSize);    

        //Allocate memory based on the size of the text file
        content = malloc(sizeof(char) * fileSize);

        // Loads text into content
        fread(content, fileSize, 1, fptr);

        //printf("%s", content);
        //Trim the text
        //content[strlen(content) - 1] = '\0';
    }
    fclose(fptr);
    return content;
}

// Calculates flesh index
int calculateFleschIndex(int syllables, int words, int sentences) {

    float index = 0;
   
        index = 206.835 - 84.6 * (syllables / words) - 1.015 * (words / sentences);
        index = round(index);
        //printf("Index : %.0lf\n", index);
        return index;
}

// Prints the score of syllables, words, fleshIndex, setences
void outputFormattedFleschScores(int syllables, int words, int fleshIndex, int sentenceCount) {

    printf("Flesh Index = %d\n", fleshIndex);
    printf("Syllable Count = %d\n", syllables);
    printf("Word Count = %d\n", words);
    printf("Sentence Count = %d\n", sentenceCount);

}

// Function that counts the total word count in the file
int countTotalWords(char * content) {

    int wordCount = 0;
    bool counter = false;

     for (int i = 0; content[i]!= '\0'; i++) {

        if (content[i] == ' ' || content[i] == '\n' || content[i] == '\t') {

            counter = false;
        }
        else if (counter == false) {
         
          counter = true;
          wordCount++;
        }
    }
    printf("\n");
    printf("Word Count: %d\n", wordCount);
    return wordCount;
}
int isVowel(char letter) {
    
    // Checks if a character is a vowel 
    switch(tolower(letter)){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            return 1;
        default:
            return 0;
    }
    return 0;
}
int isWordEnd(char letter){

    // Checks if a character is at the end of a word
    switch(letter){
        case ' ':
        case '\0':
        case '!':
        case '.':
        case ';':
        case ':':
        case '?':
        case '\n':
            return 1;
        default:
            return 0;
    }
    return 0;
}
int countTotalSyllables(char * content) {

    // Tokenize the word with a space and new line 
    char delimit[]=" \n";
    int syllableCount = 0;
    char * token = strtok(content, delimit);
    int totalSyllables = 0;

    while (token != NULL) {

        //printf("token: %s\n", token); <- Debugging purposes
        for (int i = 0; i <= strlen(token); i++) {

            // case where there is only one vowel & case where there is more than one vowel adjacent
            if (isVowel(token[i]) == 1) {
                // case where the vowel is the end of the word
                if (token[i] == 'e'){
                   // printf("%d, %c\n", isWordEnd(token[i+1]), token[i+1]); <- Debugging purposes
                    if (isWordEnd(token[i+1]) == 1){
                        syllableCount--;
                    } 
                    syllableCount++;
                } 
                else {
                    syllableCount++;
                }
                // case where current character is a vowel and the next one is as well
                if (isVowel(token[i+1]) == 1){
                    syllableCount--;
                }
            }
        }
        if (syllableCount == 0){
            // Set default syllable count to 1
            syllableCount = 1;
            printf("%s syllable count = %d: \n", token, syllableCount);
        } 
        else {
            printf("%s syllable count = %d: \n", token, syllableCount);
        }
        printf("\n");
        totalSyllables+= syllableCount;
        syllableCount = 0;

        //Move onto the next word
        token = strtok(NULL, delimit);
    } 
    printf("total syllables: %d\n\n", totalSyllables);
    return totalSyllables;
}

// Function that counts total sentences in the file 
int countTotalSentences(char * content) {

    int sentenceCount = 0;
    bool counter = false;

        // Loops through the string
        for (int i = 0; content[i]!= '\0'; i++) {

            // If it encounters a period, semi colon, exclamation mark set a flag to false
            if (content[i] == '.' || content[i] == '?' || content[i] == '!' || content[i] == ';' || content[i] == ':' ) {

            counter = false;

            }
            // Increase sentenceCount if the flag is == false
            else if ((counter == false) && (content[i] != '\n')){

                sentenceCount++;
                counter = true;
            }
        }
  printf("\n");
  printf("Sentence Count: %d\n", sentenceCount);
  printf("\n");
  return sentenceCount;
}






