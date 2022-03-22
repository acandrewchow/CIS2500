Information:    

    Assignment Name: Tweet Manager
    Made by: Andrew Chow (1088114)
    Email: achow04@uoguelph.ca
    Course ID: CIS 2500
    Date of last Revision: March 19, 2021

Program Summary:

    This program displays a variety of functions the user can use.
    There are 8 menu options to choose from that the user may enter

    Menu Options 
    
    1: When the user enters 1, the user is able to create a tweet with a username
    and a computer generates a unique ID.

    2: When the user enters 2, a list of tweets that were created are displayed to
    the user with its unique user ID, username and tweet

    3: When the user enters 3, they can search for a specific keyword to search within
    the created tweets.

    4: When the user enters 4, the total amount of stop words across all tweets in the
    list will be displayed

    5: When the user enters 5, they are able to delete a tweet of their choice

    6: When the user enters 6, they are able to enter a file name of their choice to save the following
    tweets to that specific file

    7: When the user enters 7, they are able to enter a filename to load tweets from a specific .csv file

    8: When the user enter 8, the program will end

How to Compile and Run the program:

    To run the program, simply use the makefile with the following commands.
    1. Type "make" with all of the files in the current directory
    2. Run the program with the executable: ./tweetManager


Limitations:
    
    1.Not being able to load tweets to different types of files (only csv)
    2.Edge cases include loading in tweets that include multiple punctuation symbols, such as (!;,) because strtok only delimits certain symbols
    3.Tweets that contain many spaces, and tabs within the text
    
Future Improvements:

    1.The load function, perhaps an improvement would be to work with multiple types of files, rather than
    specifically .csv files. 
    2.Improving memory management throughout the program's variables and code



