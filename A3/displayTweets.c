#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

void displayTweets(tweet *tweetList) {

    // Declare a temp node to not lose the link's reference to the tweetList
    tweet * tempNode;
    
    // Check if the list is empty
    if (tweetList == NULL) {

        printf("Linked list is empty\n");
    }

    else {

       tempNode = tweetList;

       // keep looping until reaches end
       while (tempNode != NULL) {
           
           // print out node information
           printf("<%d> Created by <%s>: <%s>\n", tempNode->id, tempNode->user, tempNode->text);
           // iterate to next node in list
           tempNode = tempNode -> next;
       }
    }
}
