/*
* Test for salvager()
*/
#include "dominion.h"

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

int main()
{
	struct gameState gametime;
	
	int kingdom[] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
	
	initializeGame(2, kingdom, 555, &gametime);
	
	int i;
	i = gametime.numBuys;
	i = i + 1;
	
	int x = cardEffect(salvager, 1, NULL, NULL, &gametime, 0, NULL);
	
	int j;
	j = gametime.numBuys;
	
	myassert((i == j), "salvager card did not increment buys successfully. \n");
	
	checkasserts();
	
	return 0;
}
	