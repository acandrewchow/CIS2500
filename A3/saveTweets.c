#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

void saveTweetsToFile(tweet * tweetList) {

    FILE * fptr;
    tweet * saveNode = tweetList;
    char * fileName = malloc(sizeof(char) * 100);

    // Ask a user for a filename to save existing tweets to a file
    printf("Enter the filename where you would like to store your tweets: ");
    fgets(fileName, 100, stdin);

    fptr = fopen(fileName, "w");

    // If file cannot be opened, exit
    if (fptr == NULL) {

        printf("File cannot be found\n");
        exit(1);
    }
    else {

        while(saveNode != NULL) {

            // Write to the linked list with the values
            fprintf(fptr, "%d,%s,%s\n", saveNode->id, saveNode->user, saveNode->text);

            // Iterate through the linked list
            saveNode = saveNode->next;
        }
        printf("Output Successful!\n"); 
    }
    // Free memory and close file when finished
    free(fileName);
    fclose(fptr);

}

