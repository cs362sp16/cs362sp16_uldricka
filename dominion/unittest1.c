/*
* Test for numHandCards()
*/
#include "dominion.h"

int failure = 0;

int myassert(int x,char* msg) 
{
	if (x == 0) 
	{
		printf("Assertion failed: %s\n",msg);
		failure = 1;
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
	
	int x = numHandCards(&gametime);
	myassert((x == 5), "numHandCards did not identify a starting hand as five cards. \n");
	
	drawCard(1, &gametime);
	drawCard(0, &gametime);
	
	int y = numHandCards(&gametime);
	myassert((x == 6), "numHandCards did not identify the amount of cards in this hand as six. \n");
	
	checkasserts();
	
	return 0;
}