#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

tweet * createTweet(tweet * tweetList) {

    // Variable Declarations
    int sumAscii = 0;
    int totalChar = 0;
    int userId = 0;
    int newId = 0;
    
    // Allocate Memory
    char * tempUser = malloc(sizeof(char) * 150);
    char * tempText = malloc(sizeof(char) * 150);
    tweet * newTweet = malloc(sizeof(tweet));
    tweet * temp;
    temp = tweetList;

        // Ask the user for tweet and id
        printf("Enter a username: ");
        fgets(tempUser, 150, stdin);

        printf("Enter a tweet: ");
        fgets(tempText, 150, stdin);

        // Trim the strings
        tempUser[strlen(tempUser) - 1] = '\0';
        tempText[strlen(tempText) - 1] = '\0';

        // Checking for Invalid Inputs, if invalid, reprint the menu
            if (strlen(tempUser) < 1 || strlen(tempUser) > 51) {

                printf("\nInvalid Input Try Again\n");
                return NULL;
            }   

            if (strlen(tempUser) < 1 || strlen(tempUser) > 141) {
                printf("\nInvalid Input Try Again\n");
                return NULL;
            }
    
        // Loop through the username and count each character's ASCII Values
        for (int i = 0; tempUser[i]!= '\0'; i++) {

            sumAscii = sumAscii + tempUser[i];
        }
        
        for (int i = 0; tempText[i]!= '\0'; i++) {  

        totalChar++;
        }
        
        userId = totalChar + sumAscii;

        printf("Your computer-generated userid is %d\n", userId);

        // Assigning values to members of the node
        printf("\n");
        strcpy(newTweet->user, tempUser);
        strcpy(newTweet->text, tempText);
        newTweet->id = userId;

        // Loop through the nodes and check if the ID exists already
        
        // srand function to generate random numbers
        srand(time(NULL));
        
        while (temp != NULL) {

            if (temp->id == userId) {

                // Generates a random ID
                newId = rand() % 999 + 1;
                printf("ID is the same, new ID is: %d\n", newId);
                newTweet->id = newId;
            }
            // Interate through the linked list
            temp = temp -> next;
        }

        // Free excess Memory
        free(tempUser);
        free(tempText);

        // Point new node to NULL
        newTweet->next = NULL;
        
        // Return node back to main
        return newTweet;
}
