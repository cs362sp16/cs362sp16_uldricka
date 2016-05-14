/*
* Random test for adventurer.   
*/
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>

int failure = 0;

int myassert(int x,char* msg) 
{
	if (x == 0) 
	{
		printf("Assertion failed: %s\n",msg);
		failure = 1;
		return 0;
	}
}

void checkasserts() 
{
	if(!failure) 
	{
		printf("Test successful! \n");
	}
}

int main(int argc, char *argv[])
{
	struct gameState gametime;
	
	int kingdom[] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
	
	int myseed;
	myseed = atoi(argv[1]);
	
	int x;
	for(x = 0, x < 1000, x++)
	{
		printf("Test number %d", x+1);
		initializeGame(2, kingdom, myseed, , &gametime);
		gametime.deckCount[0] = rand() % 40;
		gametime.discardCount[0] = rand() % 40;
		gametime.handCount[0] = rand() % 10;
		int hand = gametime.handCount[0];
		int cards = gametime.deckCount[0] + gametime.discardCount[0] + gametime.handCount[0];
		cardEffect(adventurer, 1, NULL, NULL, &g, 0, NULL);
		int cardslater = gametime.deckCount[0] + gametime.discardCount[0] + gametime.handCount[0];
		int handlater = gametime.handCount[0];
		myassert((cards == cardslater), "Cards have gone missing\n");
		myassert((hand == handlater), "Hand is not two treasure cards larger\n");
	}
	
	checkasserts();
	
	return 0;
}
	