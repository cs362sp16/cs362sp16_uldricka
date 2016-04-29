/*
* Test for great hall card. 
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
	
	int x = cardEffect(great_hall, NULL, NULL, NULL, &gametime, 0, NULL);
	
	int k;
	k = gametime.handCount[0];
	
	int l;
	l = gametime.numActions;
	
	myassert((i == k), "great hall card did not draw a new card. \n");
	myassert((j == l), "great hall card did not increment actions. \n");
	
	checkasserts();
	
	return 0;
	
}