#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

int searchTweetsByKeyword(tweet * tweetList) {

    // Variable declarations
    tweet * tempNode = tweetList;
    char * tempInput = malloc(sizeof(char) * 150);
    char * originalText = malloc(sizeof(char) * 150);

    // Copy to a temp variable to show the original tweet
    strcpy(originalText, tempNode->text);

    // Gather user input
    printf("Enter a keyword to search: ");
    fgets(tempInput, 100, stdin);

    // Trim the text
    tempInput[strlen(tempInput) - 1] = '\0';
    
  
    // Reference: https://codeforwin.org/2015/04/c-program-convert-upper-case-string-to-lower.html 
    // Date Accessed: March 15, 2021
    // Converting the string to lower case by using ASCII Values of each character
     for(int i=0; tempInput[i]!='\0'; i++) {

        if(tempInput[i]>='A' && tempInput[i]<='Z') {

            tempInput[i] = tempInput[i] + 32;
        }
    }
    // Converting the string to lower case
    for (int i=0; tempNode->text[i]!='\0'; i++) {

        if (tempNode->text[i]>='A' && tempNode->text[i]<='Z') {
            
            tempNode->text[i] = tempNode->text[i] + 32;
        }
    }
    // Traverse through the node if there are items
    while (tempNode != NULL) {

        // Search the keyword in the given tweets wthin the linked list
        if (strstr(tempNode->text, tempInput)) {

            printf("Match found for '%s': %s wrote: %s\n", tempInput, tempNode->user, originalText);
           
        }
        else {

            printf("Match not found\n");
            return 0;
        }
        // Increment the node to the next node
        tempNode = tempNode -> next;
    }

    // Free excess memory
    free(tempInput);
    free(originalText);
    
    // Return the value if function is true
    return 1;
}
