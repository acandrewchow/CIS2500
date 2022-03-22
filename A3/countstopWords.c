#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

void countStopWords(tweet * tweetList) {

    // Variable Declarations
    tweet * tempNode = tweetList;
    tweet * tempCount = tweetList;
    int stopWords = 0;
    int count = 0;
    char * token;
    
    // Token delimeter to tokenize with all of the following parameters
    char delimit[] = " \n,;:!?.";

    // Declare an array of 25 stop words
    char words[100][100] = {"a", "an", "and", "are", "as", "at", "be", "by", "for", "from", "has", "he", "in", "is", "it", "its", "on", "of", "that", "the", "to", "was", "were", "will", "with"};

    // Declare a temp array to store the tweet's information, because
    // strtok will create issues with the format
    char * tempArray = malloc(sizeof(char) * 150);
    
    // Count the following nodes
    while (tempCount != NULL) {

        tempCount = tempCount -> next;
        count++;
    }
    if (tempNode == NULL) {

        printf("Linked list is empty\n");
    }
    else {
        // Iterate through the list
        while (tempNode != NULL) {
            // Tokenize first
            tempArray = strcpy(tempArray, tempNode->text);
            token = strtok(tempArray, delimit);

            while (token != NULL) {

                for (int i = 0; i < 25; i++) {
                    // Check for a stop word
                    if (strcmp(token, words[i]) == 0) {

                        stopWords++;
                    }
                }
                // Tokenize the string each time
                token = strtok(NULL, delimit);
            }
            // Iterate to next node in the list
            tempNode = tempNode -> next;
        }
    }
    // Free excess memory
    free(tempArray);
    printf("Across %d tweet(s): %d stop word(s) were found\n", count, stopWords);
}
