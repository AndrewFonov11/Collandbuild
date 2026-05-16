
// Collandbuild ver 1.0.2

// Source code

// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int hp,xp,stone,dirt,spines,gravel,flower,wood,iron,fence;
int px,py,max,may,mbx,mby,mcx,mcy;
int apy,apx,sa,imr,armor,cm,mal,mbl,mcl,amby,ambx,amay,amax;
int seed,rnd;
int i,j;
char world[20][31],a,syp,rw[20][30];

void cb()
{
	if (a == 'x') {
		if (rw[py][px] == '#') stone++;
		if (rw[py][px] == '+') dirt++;
		if (rw[py][px] == '^') spines++;
		if (rw[py][px] == '~') gravel++;
		if (rw[py][px] == '!') flower++;
		if (rw[py][px] == '=') wood++;
		if (rw[py][px] == ':') iron++;
		if (rw[py][px] == '/') fence++;
		rw[py][px] = ' ';
	}
	if (a == 'k') {
		if (world[py][px] == '@') mal = 0,xp++;
		if ((world[py][px] == '&') && (xp > 0)) mbl = 0,xp+=3;
	}
	if ((a == 'n') && (xp > 3)) {
		mal = 1;
		xp-=3;
		may = py,max = px;
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
		if (a == '4') {
			if (gravel > 0) gravel--,rw[py][px] = '~';
		}
		if (a == '5') {
			if (flower > 0) flower--,rw[py][px] = '!';
		}
		if (a == '6') {
			if (wood > 0) wood--,rw[py][px] = '=';
		}
		if (a == '7') {
			if (iron > 0) iron--,rw[py][px] = ':';
		}
		if (a == '8') {
			if (fence > 0) fence--,rw[py][px] = '/';
		}
	}
}

void creation()
{
	printf("\n?");
	a = getch();
	if ((a == '1') && (stone > 2) && (dirt > 2)) {
		stone-=2,dirt-=2;
		gravel++;
	}
	if ((a == '2') && (spines > 2) && (dirt > 2)) {
		spines-=2,dirt-=2;
		flower++;
	}
	if ((a == '3') && (spines > 2) && (flower > 2)) {
		spines-=2,flower-=2;
		wood++;
	}
	if ((a == '4') && (iron > 3) && (wood > 1) && (armor == 0)) {
		iron-=3,wood-=1;
		armor = 1;
	}
	if ((a == '5') && (iron > 2) && (stone > 2)) {
		iron-=2,stone-=2;
		fence++;
	}
}

void go_ma()
{
	rnd = rand() % 4 + 1;
	if (rnd == 1) may++;
	if (rnd == 2) may--;
	if (rnd == 3) max++;
	if (rnd == 4) max--;
	if (rw[may][max] == '!') rw[may][max] = '+';
	if (rw[may][max] == '/') may = amay,max = amax;
}

void go_mb()
{
	if (mbx > px) mbx--;
	if (mbx < px) mbx++;
	if (mby > py) mby--;
	if (mby < py) mby++;
	if ((mbx == px) && (mby == py)) hp--,armor = 0;
	if (rw[mby][mbx] == '#') mby = amby,mbx = ambx;
	if (rw[mby][mbx] == '^') mby = rand() % 20,mbx = rand() % 30;
	if (rw[mby][mbx] == '=') mbl = 0,xp++;
}

void go_mc()
{
	if (mbl == 1) {
		if (mcx > mbx) mcx--;
		if (mcx < mbx) mcx++;
		if (mcy > mby) mcy--;
		if (mcy < mby) mcy++;
		if ((mbx == mcx) && (mby == mcy)) mbl = 0;
	}
	else if ((mal == 1) && (mbl == 0)) {
		if (mcx > max) mcx--;
		if (mcx < max) mcx++;
		if (mcy > may) mcy--;
		if (mcy < may) mcy++;
		if ((max == mcx) && (may == mcy)) mal = 0;
	}
	else {
		if (mcx > px) mcx--;
		if (mcx < px) mcx++;
		if (mcy > py) mcy--;
		if (mcy < py) mcy++;
		if ((mcx == px) && (mcy == py)) hp = 0;
	}
}

void tpp()
{
	if (sa == 1) {
		if (rw[py][px] == '#') py = apy,px = apx;
	}
	if ((rw[py][px] == '^') && (armor == 0)) hp--;
	if ((rw[py][px] == '!') && (hp < 15)) hp++;
}

void grw()
{
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 30; j++) {
			rnd = rand() % 9 + 1;
			if (rnd == 2) rw[i][j] = '#';
			else if (rnd == 3) rw[i][j] = '+';
			else if (rnd == 4) rw[i][j] = '^';
			else if (rnd == 5) rw[i][j] = ':';
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
	if ((may > 19) || (max > 29) || (may < 0) || (max < 0)) may = 2,max = 2;
	if ((mby > 19) || (mbx > 29) || (mby < 0) || (mbx < 0)) mby = 2,mbx = 2;
	if ((mcy > 19) || (mcx > 29) || (mcy < 0) || (mcx < 0)) mcy = 2,mcx = 2;
	world[py][px] = syp;
	if (mal == 1) {
		world[may][max] = '@';
	}
	if (mbl == 1) {
		world[mby][mbx] = '&';
	}
	if (mcl == 1) {
		world[mcy][mcx] = 'R';
	}
}

void com()
{
	printf("\n$");
	scanf(" %c",&a);
	if (a == 't') {
		printf("\ny:");
		scanf("%d",&py);
		printf("\nx:");
		scanf("%d",&px);
	}
	else if (a == 's') {
		printf("\n?");
		scanf(" %c",&a);
		if (a == '1') mal = 1,may = py,max = px;
		if (a == '2') mbl = 1,mby = py,mbx = px;
		if (a == '3') mcl = 1,mcy = py,mcx = px;
	}
	else if (a == 'v') {
		printf("\nhp:");
		scanf("%d",&hp);
		printf("\nxp:");
		scanf("%d",&xp);
	}
	else {
		printf("\n???");
	}
}

int main()
{
	printf("\nPUBLIC DOMAIN SOFTWARE");
	printf("\nCollandbuild");
	printf("\nVersion 1.0.2\n");
	printf("\nseed:");
	scanf("%d",&seed);
	srand(seed);
	printf("\nS/E?");
	scanf(" %c",&a);
	if (a == 's') {
		hp = 5,xp = 0,stone = 0,dirt = 0,spines = 0,gravel = 0,flower = 0,wood = 0,iron = 0,fence = 0;
		mal = 1,mbl = 1,mcl = 0;
		grw();
	}
	if (a == 'e') {
		hp = 999,xp = 999,stone = 999,dirt = 999,spines = 999,gravel = 999,flower = 999,wood = 999,iron = 999,fence = 999;
		mal = 0,mbl = 0,mcl = 0;
		egrw();
	}
	printf("\nImmortal?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') imr = 1;
	if (a == 'n') imr = 0;
	printf("\nCommands?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') cm = 1;
	if (a == 'n') cm = 0;
	printf("\nIs the stone active?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') sa = 1;
	if (a == 'n') sa = 0;
	printf("\nPlayer symbol:");
	scanf(" %c",&syp);
	py = 2,px = 2,max = 10,may = 10,mbx = 15,mby = 15,armor = 0;
	do
	{
		apy = py,apx = px;
		amby = mby,ambx = mbx;
		amay = may,amax = max;
		map();
		for (i = 0; i < 20; i++) {
			printf("\n%s",world[i]);
		}
		printf("\nHP: %d",hp);
		printf("\nXP: %d",xp);
		printf("\nArmor: ");
		if (armor == 1)
			printf("yes");
		else
			printf("no");
		printf("\n1 Stone: %d",stone);
		printf("\n2 Dirt: %d",dirt);
		printf("\n3 Spines: %d",spines);
		printf("\n4 Gravel: %d",gravel);
		printf("\n5 Flower: %d",flower);
		printf("\n6 Wood: %d",wood);
		printf("\n7 Iron: %d",iron);
		printf("\n8 Fence: %d",fence);
		a = getch();
		system("cls");
		if (a == 'w') py--;
		if (a == 's') py++;
		if (a == 'd') px++;
		if (a == 'a') px--;
		if ((a == 't') && (cm == 1)) {
			com();
		}
		if (a == 'c') {
			creation();
		}
		cb();
		tpp();
		if (mal == 1) {
			go_ma();
		}
		if (mbl == 1) {
			go_mb();
		}
		if (mcl == 1) {
			go_mc();
		}
		if (imr == 1) hp = 100;
		if (a == 'q') hp = 0;
	}
	while (hp > 0);
	printf("\nEND GAME");
	return 0;
}