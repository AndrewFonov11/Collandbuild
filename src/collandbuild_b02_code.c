// Collandbuild ver beta 0.2

// Source code

// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int hp,stone,dirt,spines;
int px,py,max,may;
int apy,apx,sa,mal;
int seed,rnd;
int i,j;
char world[20][31],a,rw[20][30];

void cb()
{
	if (a == 'x') {
		if (rw[py][px] == '#') stone++;
		if (rw[py][px] == '+') dirt++;
		if (rw[py][px] == '^') spines++;
		rw[py][px] = ' ';
	}
	if (a == 'k') {
		if ((px == max) && (py == may)) mal = 0;
	}
	if (a == 'z') {
		printf("\n?");
		a = getch();
		if (a == '1') {
			if (stone > 0) stone--,rw[py][px] = '#';
		}
		if (a == '2') {
			if (dirt > 0) dirt--,rw[py][px] = '+';
		}
		if (a == '3') {
			if (spines > 0) spines--,rw[py][px] = '^';
		}
	}
}

void go_ma()
{
	rnd = rand() % 4 + 1;
	if (rnd == 1) may++;
	if (rnd == 2) may--;
	if (rnd == 3) max++;
	if (rnd == 4) max--;
}

void tpp()
{
	if (sa == 1) {
		if (rw[py][px] == '#') py = apy,px = apx;
	}
	if (rw[py][px] == '^') hp--;
	if (rw[py][px] == '+') hp++;
}

void grw()
{
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 30; j++) {
			rnd = rand() % 8 + 1;
			if (rnd == 2) rw[i][j] = '#';
			else if (rnd == 3) rw[i][j] = '+';
			else if (rnd == 4) rw[i][j] = '^';
			else rw[i][j] = ' ';
		}
	}
}

void egrw()
{
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 30; j++) {
			rw[i][j] = ' ';
		}
	}
}

void map()
{
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 30; j++) {
			world[i][j] = rw[i][j];
		}
		world[i][30] = '\0';
	}
	if ((py > 19) || (px > 29) || (py < 0) || (px < 0)) py = 2,px = 2;
	if ((may > 19) || (max > 29) || (may < 0) || (max < 0)) may = 10,max = 10;
	world[py][px] = '*';
	if (mal == 1) {
		world[may][max] = '@';
	}
}

int main()
{
	printf("\nPUBLIC DOMAIN SOFTWARE");
	printf("\nCollandbuild");
	printf("\nVERSION: BETA 0.2\n");
	printf("\nS/E?");
	scanf(" %c",&a);
	if (a == 's') {
		printf("\nseed:");
		scanf("%d",&seed);
		srand(seed);
		hp = 5,stone = 0,dirt = 0,spines = 0;
		mal = 1;
		grw();
	}
	if (a == 'e') {
		hp = 999,stone = 999,dirt = 999,spines = 999;
		mal = 0;
		egrw();
	}
	printf("\nIs the stone active?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') sa = 1;
	if (a == 'n') sa = 0;
	py = 2,px = 2,max = 10,may = 10;
	do
	{
		apy = py,apx = px;
		map();
		for (i = 0; i < 20; i++) {
			printf("\n%s",world[i]);
		}
		printf("\nHP: %d",hp);
		printf("\n1 Stone: %d",stone);
		printf("\n2 Dirt: %d",dirt);
		printf("\n3 Spines: %d",spines);
		a = getch();
		system("cls");
		if (a == 'w') py--;
		if (a == 's') py++;
		if (a == 'd') px++;
		if (a == 'a') px--;
		cb();
		if (a == 'q') hp = 0;
		tpp();
		if (mal == 1) {
			go_ma();
		}
	}
	while (hp > 0);
	printf("\nEND GAME");
	return 0;
}