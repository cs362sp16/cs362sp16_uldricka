/*
* Random test for salvager.   
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
		gametime.handCount[0] = rand() % 40;
		gametime.numBuys = rand() % 100;
		int hand = gametime.handCount[0];
		int buys = gametime.numBuys;
		cardEffect(salvager, 1, NULL, NULL, &g, 0, NULL);
		int handlater = gametime.handCount[0];
		myassert((hand == (handlater + 1)), "Hand count did not decrement \n")
		myassert((buys == (gametime.numBuys - 1)), "Buys did not increment \n");
	}
	
	checkasserts();
	
	return 0;
}
	