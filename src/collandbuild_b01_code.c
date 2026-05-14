
// Collandbuild ver beta 0.1

// Source code

// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int hp,res;
int px,py;
int seed,rnd;
int i,j;
char world[20][21],a,rw[20][20];

void grw()
{
	for (i = 0; i < 19; i++) {
		for (j = 0; j < 19; j++) {
			rnd = rand() % 2 + 1;
			if (rnd == 1) rw[i][j] = ' ';
			if (rnd == 2) rw[i][j] = '#';
		}
	}
}

void egrw()
{
	for (i = 0; i < 19; i++) {
		for (j = 0; j < 19; j++) {
			rw[i][j] = ' ';
		}
	}
}

void map()
{
	for (i = 0; i < 19; i++) {
		for (j = 0; j < 19; j++) {
			world[i][j] = rw[i][j];
		}
		world[i][20] = '\0';
	}
	world[py][px] = '*';
}

int main()
{
	printf("\nPUBLIC DOMAIN SOFTWARE");
	printf("\nCollandbuild");
	printf("\nVERSION: BETA 0.1\n");
	printf("\nS/E?");
	scanf(" %c",&a);
	if (a == 's') {
		printf("\nseed:");
		scanf("%d",&seed);
		srand(seed);
		res = 0;
		grw();
	}
	if (a == 'e') {
		printf("\nR?:");
		scanf("%d",&res);
		egrw();
	}
	hp = 1,py = 2,px = 2;
	do
	{
		map();
		for (i = 0; i < 19; i++) {
			printf("\n%s",world[i]);
		}
		printf("\nHP: %d",hp);
		printf("\nRES: %d",res);
		a = getch();
		system("cls");
		if (a == 'w') py--;
		if (a == 's') py++;
		if (a == 'd') px++;
		if (a == 'a') px--;
		if ((a == 'z') && (res > 0) && (rw[py][px] == ' ')) rw[py][px] = '#',res--;
		if ((a == 'x') && (rw[py][px] == '#')) rw[py][px] = ' ',res++;
		if (a == 'q') hp = 0;
	}
	while (hp > 0);
	printf("\nEND GAME");
	return 0;
}