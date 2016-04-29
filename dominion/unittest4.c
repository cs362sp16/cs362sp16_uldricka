/*
* Test for endTurn()
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
	
	endTurn(&gametime);
	
	int x = gametime.whoseTurn;
	myassert((x == 1), "endTurn did not end the first player's turn. \n");
	
	endTurn(&gametime);
	
	int y = gametime.whoseTurn;
	myassert((y == 0), "endTurn did not successfully loop back to the first player's turn upon the end of the last player's turn. \n");
	
	checkasserts();
	
	return 0;
}