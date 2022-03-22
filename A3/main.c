#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headerA3.h"

int main(void) {
 
    // Variable Declarations
    int userInput = 0;

    // temporary node to store
    tweet * node;

    int test = 0;

    // Set the tweetList of the list to NULL
    tweet * tweetList = NULL;
    
        // Menu Options (If user enters 8, ends the program)
        while (userInput != 8) {

            printf("Enter a menu option (1-8, 8 to exit): ");
            scanf("%d", &userInput);
            getchar();
            
            if (userInput == 1) {

                node = createTweet(tweetList);
                addNodeToList(&tweetList, node);
                
            }
            else if (userInput == 2) {
                displayTweets(tweetList);
            }
            else if (userInput == 3) {

                test = searchTweetsByKeyword(tweetList);
                printf("Function Worked!: %d\n", test);
            }
            else if (userInput == 4) {

                countStopWords(tweetList);
            }
            else if (userInput == 5) {

                deleteTweet(&tweetList);
            }
            else if (userInput == 6) {

               saveTweetsToFile(tweetList);
            }
            else if (userInput == 7) {

                loadTweetsFromFile(&tweetList);
            }
           else if (userInput == 8) {
                
                // While list is not empty
                while(tweetList != NULL) {
                  
                  // Free memory when option 8 is selected
                  // Declare a temp to set to the head
                  tweet * temp = tweetList;
                  // Iterate through the list and free each node
                  tweetList = tweetList -> next;
                  free(temp);
                    
                }
                exit(1);
            }
            else {

                exit(1);
            }
        }   
    return 0;
}
