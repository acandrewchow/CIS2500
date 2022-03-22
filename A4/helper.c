#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "headerA4.h"

tweet * createTweet(tweet * tweetList) {

    // Variable Declarations
    int sumAscii = 0;
    int totalChar = 0;
    int userId = 0;
 
    // Allocate Memory
    char * tempUser = malloc(sizeof(char) * 150);
    char * tempText = malloc(sizeof(char) * 150);
    tweet * newTweet = malloc(sizeof(tweet));
   
        // Ask the user for tweet and id
        printf("Enter a username: ");
        fgets(tempUser, 150, stdin);

        printf("Enter a tweet: ");
        fgets(tempText, 150, stdin);

        // Trim the strings
        tempUser[strlen(tempUser) - 1] = '\0';
        tempText[strlen(tempText) - 1] = '\0';

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

        // Free excess Memory
        free(tempUser);
        free(tempText);

        // Point new node to NULL
        newTweet->next = NULL;
        
        // Return node back to main
        return newTweet;
}
void clearQueue(tweet ** head) {

    // Declare tempNode
    tweet * temp;   

    while (*head != NULL) {

        // Set a temp node to head
        temp = *head;
        // Iterate to next node using head's reference
        * head = (*head) -> next;
        // Free the node
        free(temp);
    }
}
