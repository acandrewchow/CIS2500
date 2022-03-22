#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerA4.h"

int main(void) {

    // Variable Declrations
    tweet * node;
    tweet * head = NULL;
    tweet * tail = NULL;

    // Node to check the isEmpty function
    tweet * emptyNode = NULL;

        // A4 Testing
        printf("Beginning A4 program testing...\n");
        printf("Creating initial queue list...\n");

        // Ask the user for 5 nodes to begin testing
        node = createTweet(head);
        enqueue(&head, &tail, node);

        node = createTweet(head);
        enqueue(&head, &tail, node);
        
        node = createTweet(head);
        enqueue(&head, &tail, node);

        node = createTweet(head);
        enqueue(&head, &tail, node);

        node = createTweet(head);
        enqueue(&head, &tail, node);


        printf("Verifying Queue contents via printQueue\n");
        printQueue(head);
        printf("\n");

        // Enqueue Function Testing
        printf("Testing [Enqueue] Function\n");
        node = createTweet(head);
        printf("Iteration [1]: [Node]: %d: Created by %s: %s\n", node->id, node->user, node->text);
        printf("\n");
        printf("After enqueue, queue looks like:\n");
        enqueue(&head, &tail, node);
        printQueue(head);
        printf("\n");

        node = createTweet(head);
        printf("Iteration [2]: [Node]: %d: Created by %s: %s\n", node->id, node->user, node->text);
        printf("\n");
        printf("After enqueue, queue looks like:\n");
        enqueue(&head, &tail, node);
        printQueue(head);
        printf("\n");

        node = createTweet(head);
        printf("Iteration [3]: [Node]: %d: Created by %s: %s\n", node->id, node->user, node->text);
        printf("\n");
        printf("After enqueue, queue looks like:\n");
        enqueue(&head, &tail, node);
        printQueue(head);
        printf("\n");

        // Dequeue Function Testing
        printf("Testing [Dequeue] function\n");
        printf("Iteration [1]\n");
        printf("After dequeue, queue looks like:\n");
        dequeue(&head, &tail);
        printQueue(head);
        printf("\n");

        printf("Iteration [2]\n");
        printf("After dequeue, queue looks like:\n");
        dequeue(&head, &tail);
        printQueue(head);
        printf("\n");

        printf("Iteration [3]\n");
        printf("After dequeue, queue looks like:\n");
        dequeue(&head, &tail);
        printQueue(head);
        printf("\n");

        // isEmpty function testing
        printf("Testing [isEmpty] Function\n");
        printf("Iteration [1]\n");
        printf("Testing with list, expecting !isEmpty\n");
        isEmpty(head);
        printf("Using printQueue to verify queue contents\n");
        printQueue(head);
        printf("\n");

        printf("Iteration [2]\n");
        printf("Testing with list after two dequeues, expecting !isEmpty\n");
        isEmpty(head);
        printf("Using printQueue to verify queue contents\n");
        printQueue(head);
        printf("\n");

        printf("Iteration [3]\n");
        printf("Testing with  empty queue, expecting isEmpty\n");
        isEmpty(emptyNode);
        printf("\n");

        // sortID Function function testing
        printf("Testing [ascendSortID] function\n");
        printf("Iteration [1]\n");
        sortID(&head, &tail);
        printQueue(head);
        printf("\n");

        printf("Iteration [2]\n");
        node = createTweet(head);
        enqueue(&head, &tail, node);
        sortID(&head, &tail);
        printQueue(head);
        printf("\n");

        printf("Iteration [3]\n");
        node = createTweet(head);
        enqueue(&head, &tail, node);
        sortID(&head, &tail);
        printQueue(head);
        printf("\n");

        // sortUsername function testing
        printf("Testing [ascendSortUsername function\n");
        printf("Iteration [1]\n");
        sortUsername(&head, &tail);
        printQueue(head);
        printf("\n");

        printf("Iteration [2]\n");
        node = createTweet(head);
        enqueue(&head, &tail, node);
        sortUsername(&head, &tail);
        printQueue(head);
        printf("\n");

        printf("Iteration [3]\n");
        node = createTweet(head);
        enqueue(&head, &tail, node);
        sortUsername(&head, &tail);
        printQueue(head);
        printf("\n");

        // reverseQueue function testing
        printf("Testing [reverseQueue] Function\n");
        printf("Iteration [1]\n");
        reverse(&head, &tail);
        printQueue(head);
        printf("\n");

        printf("Iteration [2]\n");
        node = createTweet(head);
        enqueue(&head, &tail, node);
        reverse(&head, &tail);
        printQueue(head);
        printf("\n");

        printf("Iteration [3]\n");
        node = createTweet(head);
        enqueue(&head, &tail, node);
        reverse(&head, &tail);
        printQueue(head);
        printf("\n");

        printf("Completed Program Testing!\n");

        // Free the list to prevent memory leaks and errors
        clearQueue(&head);
}

