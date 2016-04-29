/*
* Test for smithy card. 
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
	
	int i = gametime.handCount[0];
	int i = i + 2;
	
	int x = cardEffect(smithy, NULL, NULL, NULL, &gametime, 0, NULL);
	
	int k = gametime.handcount[0];
	
	myassert((i == k), "Smithy did not correctly add three cards to hand.\n");
	
	checkasserts();
	
	return 0;
		
}