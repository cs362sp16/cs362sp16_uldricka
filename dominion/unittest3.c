/*
* Test for isGameOver()
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
	
	int x = isGameOver(&gametime);
	myassert((x == 0), "isGameOver reported a new game as over. \n");
	
	gametime->supplyCount[province] = 0;
	
	int y = isGameOver(&gametime);
	myassert((y == 1), "isGameOver did not recognize a game with an empty province pile as over. \n");
	
	int i;
	
	for (i = 0; i < 25; i++)
	{
		gametime->supplyCount[i] = 0;
	}
	
	int z = isGameOver(&gametime);
	myassert((z == 1), "isGameOver did not recognize a game with empty supply stacks as over. \n");
	
	checkasserts();
	
	return 0;
}