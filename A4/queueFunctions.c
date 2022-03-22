#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerA4.h"

void enqueue(tweet ** head, tweet ** tail, tweet * node) {

    // if queue is empty
    if (*tail == NULL) {

         // Point both tail and head to the beginning nodde
        *tail = node;
        *head = node;
        return;
    }
    else {
            
        // Update the values to add to the end of queue
        (*tail) -> next = node;
        *tail = node;
    }
}

void dequeue(tweet ** head, tweet ** tail) {

    printf("Dequeue: Removing node from the head/front\n");
    tweet * tempNode = * head;

    // if queue is empty
    if (head == NULL) {

        printf("Queue is empty, nothing to remove\n");
        return;
    }
    else {

        // move the head to the next node
        *head = (*head) -> next;
    }
    // Since we are removing the head/front node it needs to be free'd
    free(tempNode);
}

int isEmpty(tweet * head) {

    tweet * temp = head;
    
    // Return 1 if queue is empty
    if (temp == NULL) {

        printf("FAIL: list is empty\n");
        return 1;
    }
    printf("SUCCESS: list is not empty\n");
    // Return 0 if queue is not empty
    return 0;
}

void printQueue(tweet * head) {

    tweet * tempNode = head;

    // Check if the queue is empty
    if (tempNode == NULL) {

        printf("Queue is empty\n");
    }
    else {
       // keep looping until reaches end
       while (tempNode != NULL) {
           
           // print out node information
           printf("%d: Created by %s: %s\n", tempNode->id, tempNode->user, tempNode->text);

           // iterate to next node in queue
           tempNode = tempNode->next;
       }
    }
}
