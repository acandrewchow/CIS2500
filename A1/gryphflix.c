#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "gryphflix.h"
/*
 Student Name: Andrew Chow
 Student ID: 1088114
 Due Date: Jan 29, 2021
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

FILE * openFileForReading(char * fileName) {

// Declares a file pointer and returns NULL if it cannot be opened, else returns the pointer

FILE * fptr;

fptr = fopen(fileName, "r");

if (fptr == NULL) {

    return NULL;
}

else {

        return fptr;
    }
}

int readMovies(FILE * fileMovies, char movieNames[NUMBER_MOVIES][MAX_STR]) {

char c;
int lines = 0;

//fileMovies = fopen("movies.txt", "r");

    if (fileMovies == NULL) {

        printf("Cannot open file");
        return 0;
    }
// Counts the number of lines in the file

    else {

      while ((c = fgetc(fileMovies)) != EOF) {

          if (c == '\n') {

              lines++;
          }
      }
     //fclose(fileMovies);
}

printf("Total number of lines are: %d\n", lines);

//fileMovies = fopen("movies.txt", "r");

    if (lines == NUMBER_MOVIES) {

        for (int i = 0; i < NUMBER_MOVIES; i++) {

        fgets(movieNames[i], 100, fileMovies);
        movieNames[i][strlen(movieNames[i]) - 1] = '\0';
    }
}

else if (lines != NUMBER_MOVIES) {

    return 0;
}

for (int i = 0; i < NUMBER_MOVIES; i++) {

    printf("%s\n", movieNames[i]);
    }

    return 1;
} 



int readReviews(FILE * fileReviews, struct reviewStruct reviews[NUMBER_REVIEWERS]) {

// Variable declaration
int lines = 0;
char c;
char tempArray[MAX_STR][NUMBER_MOVIES];

//fileReviews = fopen("reviews.txt", "r");

    if (fileReviews == NULL) {

        printf("Cannot open file");
        return 0;
    }
    else {

// Counts the number of lines in the file

      while ((c = fgetc(fileReviews)) != EOF) {

          if (c == '\n') {

              lines++;
          }
      }
     //fclose(fileReviews);
}

printf("Lines in the reviews.txt file: %d\n", lines);

if (lines != NUMBER_REVIEWERS) {

    return 0;
}

//fileReviews = fopen("reviews.txt", "r");

for (int i = 0; i < NUMBER_REVIEWERS; i++) {

    fscanf(fileReviews, "%s ", reviews[i].reviewer);

    for (int j = 0; j < NUMBER_MOVIES; j++) {

        fscanf(fileReviews, "%c ", &tempArray[i][j]);
    }
}  

// Converts the data into an integers 1 and 0

for (int i = 0; i < NUMBER_REVIEWERS; i++) {

    for (int j = 0; j <NUMBER_MOVIES; j++) {

        if ((tempArray[i][j] == 'Y') || (tempArray[i][j] == 'y')) {

            reviews[i].feedback[j] = 1;
       }
       else if ((tempArray[i][j] == 'N') || (tempArray[i][j] == 'n')) {

           reviews[i].feedback[j] = 0;
       }
    }
}

return 1;

}

int getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS], char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR]) {

// Variable declaration
int record = 0;
int criticalReviewers = 0;
int tempArray[50];

// Loops through the data to determine the max # of 0's

for (int i = 0; i < NUMBER_REVIEWERS; i++) {

    int count = 0;

    for (int j = 0; j < NUMBER_MOVIES; j++) {

        if (reviews[i].feedback[j] == 0) {

            count++;
        }
    }
    if (count > record) {

        record = count;
    }
}

printf("Max number of N's = %d\n", record);

// Compares the values 

for (int i = 0; i < NUMBER_REVIEWERS; i++) {

    int temp = 0;
    
    for (int j = 0; j < NUMBER_MOVIES; j++) {

        if (reviews[i].feedback[j] == 0) {

            temp++;
        }    
    }
     tempArray[i] = temp;
}

// If the values are met, copies the reviewer's names into the array; mostCriticalReviewers

for (int i = 0; i < NUMBER_REVIEWERS; i++) {

    if (record == tempArray[i]) {

        strcpy(mostCriticalReviewers[criticalReviewers++], reviews[i].reviewer);

        }
    }

// Return the # of critical Reviewers
return criticalReviewers;
}
int getMostRecommendedMovies(const char movies [NUMBER_MOVIES][MAX_STR], const struct reviewStruct reviews [NUMBER_REVIEWERS], char mostRecommendedMovies [NUMBER_REVIEWERS][MAX_STR]) {

// Variable declaration
int count = 0;
int record = 0;
char tempArray[50];
int recommendedMovies = 0;

// Scans the data to find the max number of Y's out of all 3 movies

for (int i = 0; i < NUMBER_MOVIES; i++) {

    for (int j = 0; j < NUMBER_REVIEWERS; j++) {

        if (reviews[i].feedback[j] == 1) {

            count++;
        }
    }
    if (count > record) {

        record = count;
    }
}
// Compare the values

for (int i = 0; i < NUMBER_MOVIES; i++) {

    int temp = 0;
    
    for (int j = 0; j < NUMBER_REVIEWERS; j++) {

        if (reviews[i].feedback[j] == 1) {

            temp++;
        }    
    }
     tempArray[i] = temp;
}

printf("Max number of Y's = %d\n", record);

// If conditions are met, copy the movie name into the array mostRecommendedMovies

for (int i = 0; i < NUMBER_REVIEWERS; i++) {

    if (record == tempArray[i]) {

        strcpy(mostRecommendedMovies[recommendedMovies++], movies[i]);

        }
    }
// Return the # of recommended movies

return recommendedMovies;

}

int predictMovie(const char movie[MAX_STR]) {

    char tempString[50];
    int wordCount = 0;
    int i = 0;
    int length = 0;
    char charCounts[50];
    int j = 0;
    int counter = 0;
    int sales = 0;
    int count = 0;
    int z = 0;
    printf("%d", z);

    strcpy(tempString, movie);
    
    // Checks for space, new line or null character to count the words in a string

    for (int i = 0; tempString[i]!= '\0'; i++) {

        if (tempString[i] == ' ' || tempString[i] == '\n' || tempString[i] == '\0') {

            wordCount++;
        }
    }
    printf("# of words in %s : %d Words\n", tempString, wordCount+1);

// REFERENCE: https://www.includehelp.com/c-programs/read-a-string-and-print-the-length-of-the-each-word.aspx
// Date Accessed: January 29th, 2021

    // Loops through the string to determine how many characters are in each word

    while(true) {

        if ((tempString[i] == ' ') || (tempString[i] == '\0')) {

            if (tempString[i] == '\0') {

                if (length > 0) {

                    charCounts[j++] = length;
                    length = 0;
                }
                break;
            }
            charCounts[j++] = length;
            length = 0;
        }
        else {

            length ++;
        }
        i++;
    }

    for (int i = 0; i < j; i++) {

        printf("Word %d: %d Characters\n", i+1, charCounts[i]);
    }

    while (count != wordCount) {

        if ((charCounts[wordCount] == charCounts[wordCount - 1])) {

            z = 1;
            wordCount = wordCount - 1;
            sales = sales + 2;
        }
        else {
            z = 0;
            break;
        }
    }
    if (wordCount > 2) {
        
        sales = sales - 1;
    }
    if (wordCount == 1) {

        sales = sales - 2;
    }
    if (wordCount > 1) {

        counter = 0;

        for (int i = 0; i <= wordCount; i++) {

            if (charCounts[i] % 2 == 0) {

                counter++;
            }
            if (counter > 1) {

                sales = sales + 1;
                break;
            }
        }

    } 
    printf("Sales Price: %d\n", sales);
    return sales;
}

int enumerateMovie (const char movie[MAX_STR], int charCounts[MAX_WORDS]) {

// Variable declaration

    int wordCount = 1;
    char tempString[50];
    int length = 0;
    int j = 0;
    int i = 0;

strcpy(tempString, movie);

printf("String broken down: %s\n", tempString);

    for (int i = 0; tempString[i]!= '\0'; i++) {

        if (tempString[i] == ' ' || tempString[i] == '\n' || tempString[i] == '\0') {

            wordCount++;
        }
    }
    while(true) {

        if ((tempString[i] == ' ') || (tempString[i] == '\0')) {

            if (tempString[i] == '\0') {

                if (length > 0) {

                    charCounts[j++] = length;
                    length = 0;
                }
                break;
            }
            charCounts[j++] = length;
            length = 0;
        }
        else {

            length ++;
        }
        i++;
    }


    for (int i = 0; i < j; i++){
        
        printf("Word %d: %d Characters\n", i+1, charCounts[i]);
    }

    printf("Word count: %d\n\n", wordCount);
    return wordCount;
}
