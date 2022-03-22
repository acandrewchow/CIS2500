tweetManager: createTweet.o displayTweets.o searchkeyWords.o countstopWords.o deleteTweets.o saveTweets.o loadTweets.o addNode.o main.o headerA3.h
	gcc -Wall -std=c99 main.o -o tweetManager createTweet.o displayTweets.o searchkeyWords.o countstopWords.o deleteTweets.o saveTweets.o loadTweets.o addNode.o headerA3.h

main.o: main.c
	gcc -Wall -std=c99 -c main.c

tweetCreate.o: createTweet.c
	gcc -Wall -std=c99 -c createTweet.c

displayTweets.o: displayTweets.c
	gcc -Wall -std=c99 -c displayTweets.c

searchkeyWords.o: searchkeyWords.c
	gcc -Wall -std=c99 -c searchkeyWords.c 

countstopWords.o: countstopWords.c
	gcc -Wall -std=c99 -c countstopWords.c 

deleteTweets.o: deleteTweets.c 
	gcc -Wall -std=c99 -c deleteTweets.c 

saveTweets.o: saveTweets.c
	gcc -Wall -std=c99 -c saveTweets.c

loadTweets.o: loadTweets.c
	gcc -Wall -std=c99 -c loadTweets.c

addNode.o: addNode.c
	gcc -Wall -std=c99 -c addNode.c

clean:
	rm *.o tweetManager













