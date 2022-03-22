#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

void addNodeToList(tweet ** tweetList, tweet * node) {

    // set temp to the tweetList
    tweet * tempNode = * tweetList;
    if (*tweetList == NULL) {

        //printf("Linked list is empty\n");
        * tweetList = node;
    }

    // Traverse through the list until it reaches NULL
    else {
       
        // Last node's next address will become NULL
        while (tempNode->next != NULL) {

            tempNode = tempNode->next;
        }
        // Adds the last node to the end of the linked list
        tempNode->next = node;
    }
}
