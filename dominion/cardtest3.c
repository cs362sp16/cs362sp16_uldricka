/*
* Test for village card.
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
	i = gametime.handCount[0];
	
	int j;
	j = gametime.numActions;
	j = j + 1;
	
	int x = cardEffect(village, NULL, NULL, NULL, &gametime, 0, NULL);
	
	int k;
	k = gametime.handCount[0];
	
	int l;
	l = gametime.numActions;
	
	myassert((i == k), "village card did not draw a new card. \n");
	myassert((j == l), "village card did not increment two actions. \n");
	
	checkasserts();
	
	return 0;
}