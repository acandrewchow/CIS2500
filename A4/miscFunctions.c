#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerA4.h"

void sortID(tweet ** head, tweet ** tail) {

    // Variable Declarations
    tweet * tempNode = * head;
    tweet * tempHead = * head;
 
    int swapId = 0;
    char * swapUser = malloc(sizeof(char) * 150);
    char * swapText = malloc(sizeof(char) * 150);
  
    // Check if queue is empty
    if (*head == NULL) {

        printf("Queue is empty\n");
        return;
    }
    // Iterate throughout the queue
    while (tempHead != NULL) {
 
        tempNode = tempHead->next;

        while (tempNode != NULL) {

            if (tempHead->id > tempNode->id) {

                // Swapping IDs
                swapId = tempHead->id;
                tempHead->id = tempNode->id;
                tempNode->id = swapId;

                // Swapping Usernames
                strcpy(swapUser, tempHead->user);
                strcpy(tempHead->user, tempNode->user);
                strcpy(tempNode->user, swapUser);

                // Swapping Tweets
                strcpy(swapText, tempHead->text);
                strcpy(tempHead->text, tempNode->text);
                strcpy(tempNode->text, swapText);
            }
            // Iterate to next node
            tempNode = tempNode->next;
        }
        // Interate to next node
        tempHead = tempHead->next;
    }
    // Free excess memory
    free(swapUser);
    free(swapText);
}

void reverse(tweet ** head, tweet ** tail) {

    tweet * nextNode = NULL;
    tweet * previousNode = NULL;
    tweet * currentNode = * head;
   
    // Traverse through while the queue has items
    while (currentNode != NULL) {

        // Store information into the next node
        nextNode = currentNode->next;

        // Move pointer one position back of the list
        currentNode->next = previousNode;

        // Move pointer one position ahead of the list
        previousNode = currentNode;
        currentNode = nextNode;
    }
    // Updating the head and tail position once the queue is reversed
    *tail = *head;
    *head = previousNode;

    //printf("Head: %s\n", (*head)->user);
    //printf("Tail: %s\n", (*tail)->user);
}

void sortUsername(tweet ** head, tweet ** tail) {

    printf("Sorting usernames\n");
    tweet * tempNode = * head;
    tweet * tempHead = * head;
    char * swapUser = malloc(sizeof(char) * 150);
    char * swapText = malloc(sizeof(char) * 150);
    int swapId = 0;

    if (tempNode == NULL) {

        printf("Queue is empty\n");
        return;
    }
    while (tempHead != NULL) {
        // Point tempHead to tempNode
        tempNode = tempHead -> next;
        
        while (tempNode != NULL) {
            // Check for alphabetical order
            if (strcmp(tempHead->user, tempNode->user) > 0) {

                // Swapping Usernames
                strcpy(swapUser, tempHead->user);
                strcpy(tempHead->user, tempNode->user);
                strcpy(tempNode->user, swapUser);

                // Swapping Tweets
                strcpy(swapText, tempHead->text);
                strcpy(tempHead->text, tempNode->text);
                strcpy(tempNode->text, swapText);

                // Swapping IDs
                swapId = tempHead->id;  
                tempHead->id = tempNode->id;
                tempNode->id = swapId;

            }
            // Iterate
            tempNode = tempNode -> next;
        }
        // Iterate
        tempHead = tempHead -> next;
    }
    // Free memory
    free(swapUser);
    free(swapText);
}
