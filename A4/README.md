    Name: Andrew Chow
    Course: CIS 2500
    Assignment: Tweet Manager II
    Last Edited: Apr 2, 2021



    How to compile an run program:

    1: With the files in the directory, type "make" to compile the makefile
    2. run the following makefile with the executable ./a4
	

    Completed Components:
	
    Queue Functions (queueFunctions.c)
    
    Function 1: enqueue:
        Adds a new node of information containing username, Id, and tweet to the end of the queue. Node is added to the tail of the list
    
    Function 2: dequeue:
        Removes the first node of the queue located at the head/front of the list
    
    Function 3: isEmpty:
        Checks the list to see if there is stuff inside
    
    Function 4: printQueue:
        Prints the nodes within the list outputting the ID, username and tweet
    
    Misc Functions (miscFunctions.c)
    
    Function 5: sortID:
        Sorts the IDs in the list in ascending order
    
    Function 6: sortUsername:
        Sorts the usernames in the list in alphabetical order
    
    Function 7: reverseQueue:
        Reverses the contents in the list from the tail to head, vice versa
    
    Helper Functions (helper.c)
    
    Function 8: createTweet:
        Creates a node and loads information including tweet, ID and username
    
    Function 9: clearList:
        Clears the list when the program is finished running
	
    
    Testing File (testA4.c)

	This File contains all of the function calls and node creations that allow for the program
	to be tested and marked. Each function is called a minimum of three times to ensure that each program
	is covered for a variety of different test cases.

    Limitations of the Program:
        
        There are edge cases when testing the sortUsername function. Due to unclear instructions the current function uses strcmp to compare the two strings in alphabetical order with ASCII values.
    
    Future Improvements:

        For the sort functions, individual information from each node was
        swapped rather than the pointers themselves, thus making the functions 
        a bit redundant. Could improve by making the pointers more efficient

