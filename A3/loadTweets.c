#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

void loadTweetsFromFile(tweet ** tweetList) {

    // Variable Declartions
    tweet * tempNode;
    char * fileName = malloc(sizeof(char) * 100);
    char * line = malloc(sizeof(char) * 1000);
    char * loadUser = malloc(sizeof(char) * 151);
    char * loadText = malloc(sizeof(char) * 151);
    FILE * fptr;

    // Ask user for filename to load tweets into
    printf("Enter a filename to load from: ");
    scanf("%s", fileName);
    fptr = fopen(fileName, "r");
  
    if (fptr == NULL) {

        printf("File cannot be found\n");
        exit(1);
    }
    else {
        // Reading each line in the .csv file
        while(fgets(line, 1000, fptr) != NULL) {
            
            // Strtok and assign the values to the node's members
            tempNode = malloc(sizeof(tweet));
            tempNode->id = atoi(strtok(line, ","));
            
            loadUser = strtok(NULL, ",");
            strcpy(tempNode->user, loadUser);

            loadText = strtok(NULL, "\n");  
            strcpy(tempNode->text, loadText);

            tempNode->text[strlen(tempNode->text) - 2] = '\0';
            tempNode->next = NULL;
        
            // Add the information to the node
            addNodeToList(tweetList, tempNode);
        }
      
        printf("Tweets Imported!\n");
    }

    printf("\n");
}
