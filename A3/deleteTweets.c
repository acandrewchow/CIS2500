#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

void deleteTweet(tweet ** tweetList) {

    // Variable Declarations
    int n = 0;
    int count = 0;
    tweet * node = * tweetList;
    tweet * current = * tweetList;
    tweet * previous = * tweetList;
    tweet * tempCount = *tweetList;

    // Loop counts the number of tweets (nodes) there are at the time
    while (tempCount != NULL) {

        tempCount = tempCount -> next;
        count++;
    }
    
    // Ask user which tweet they would like to delete
    printf("Which tweet would you like to delete - enter a value between 1 and %d: ", count);
    scanf("%d", &n);

    if (*tweetList == NULL) {

        printf("Linked list is empty\n");
    }
    // If the first node wants to be deleted, free the first node to accomodate memory issues
    else if (n == 1) {

        * tweetList = current->next;
        free(current);
    }
    else {
        // While there is more than one node, unlink the deleted node
        // and link the previous node to the other nodes
        while(n != 1) {

            previous = current;
            current = current->next;
            // previous node
            n = n - 1;
        }
        // Assign previous pointer to the current
        previous->next = current->next;
        // Free memory
        free(current); 
        }
        printf("Tweet %s deleted. There are now %d tweets left\n", node->text, count - 1);
    }
