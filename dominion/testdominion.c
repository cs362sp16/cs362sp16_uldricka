#include <stdio>h>
#include <time.h>
#include <stdlib.h>
#include "rngs.h"
#include "dominion.h"
#include "interface.h"


turntime(struct gameState *gametime, int x)
{
	//alright kids remember your ABCD's
	int actions;
	int choice = (rand() % gametime->handCount[x]);
	actions = 0;
	
	//action phase
	for(int y = 0; y < gametime->handCount[x]; y++)
	{
		if(g->hand[x][y] > 6)
		{
			actions = actions + 1;
		}
	}
	if(actions == 1)
	{
		for(int z = 0; z < gametime->handCount[x]; z++)
		{
			if(gametime->hand[x][z] > 6)
			{
				playCard(z, choice, choice, choice, &gametime);
			}
		}
	}
	if(actions > 1)
	{
		int actiontaken = 0;
		for(int z = 0; z < gametime->handCount[x]; z++)
		{
			if(gametime->hand[x][z] > 6)
			{
				playCard(z, choice, choice, choice, &gametime);
				actiontaken = 1;
			}
			if(actiontaken == 1)
				break;
		}
	}
	
	//buy phase
	int randcard;
	int tries = 0;
	do
	{
		int randcard = rand() % (treasure_map + 1);
		tries++;
		if(tries > 300)
			break;
	}while(buyCard(randcard, &gametime) == -1);
	
	//cleanup&draw automatic
}

void playball(int myseed)
{
	int players;
	players = (rand() % 3) + 2;
	struct gameState gametime;
	int k[10] = (0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	int doublecheck = 0;
	int kcard;
	for(int z = 0; z < 10; z++)
	{
		do
		{
		kcard = (rand() % (treasure_map + 8);
		for(int a = 0; a < 10; a++)
		{
			if(k[a] == kcard)
			{
				doublecheck = 1;
			}
			else
			{
				doublecheck = 0;
			}
		}
		}while(doublecheck!=0);
		k[z] = kcard;
	}
	
	printf("The game begins.\n");
	initializeGame(players, k, myseed, &gametime);
	
	while(!isGameOver(&gametime);)
	{
		for(int x = 0; x < players; x++)
		{
			printf("It is now player %d 's turn.\n", (x + 1));
			turntime(&gametime, x);
			endTurn(&gametime);
		}
	}
	printf("The game concludes\n");
	
	
}

int main(int argc, char* argv[])
{
	int myseed;
	srand(time(NULL));
	
	if(argv[1]==NULL)
	{
		printf("Incorrect Usage.\n");
		return 0;
	}
	else
		seed = atoi(argv[1]);
	for(int x = 0;i<10;i++)
	{
		playball(myseed);
	}
	return 0;
}