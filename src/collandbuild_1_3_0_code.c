
// Collandbuild ver 1.3.0

// Source code

// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int hp,xp,stone,dirt,spines,gravel,flower,wood,iron,fence,water,crystal;
int px,py,max[10],may[10],mbx[10],mby[10],mcx[10],mcy[10],mdx[10],mdy[10],mex[10],mey[10];
int apy,apx,sa,imr,mv,pt[10],cm,mal[10],mbl[10],mcl[10],mdl[10],mel[10];
int amby[10],ambx[10],amay[10],amax[10],amdy[10],amdx[10],amey[10],amex[10],amcy[10],amcx[10];
int nsi,armor,bottle;
int seed,rnd;
int i,j;
char world[30][51],a,syp,rw[30][50];

void cb()
{
	if ((a == '+') && (nsi < 10)) nsi++;
	if ((a == '-') && (nsi > 1)) nsi--;
	if (a == 'x') {
		if (rw[py][px] == '#') stone++;
		if (rw[py][px] == '+') dirt++;
		if (rw[py][px] == '^') spines++;
		if (rw[py][px] == '~') gravel++;
		if (rw[py][px] == '!') flower++;
		if (rw[py][px] == '=') wood++;
		if (rw[py][px] == ':') iron++;
		if (rw[py][px] == '/') fence++;
		if (rw[py][px] == '[') crystal++;
		if (rw[py][px] != '.') rw[py][px] = ' ';
	}
	if ((a == 'p') && (bottle == 1)) {
		if (rw[py][px] == '.') water++,rw[py][px] = ' ';
	}
	if (a == 'k') {
		for (i = 0; i < 10; i++) {
			if (mal[i] == 1) {
				if ((px == max[i]) && (py == may[i])) mal[i] = 0,xp++,pt[i] = 0;
			}
			if (mbl[i] == 1) {
				if ((px == mbx[i]) && (py == mby[i]) && (xp > 0)) mbl[i] = 0,xp+=3;
			}
			if (mdl[i] == 1) {
				if ((px == mdx[i]) && (py == mdy[i])) mdl[i] = 0,xp++;
			}
			if (mel[i] == 1) {
				if ((px == mex[i]) && (py == mey[i])) mel[i] = 0,xp++;
			}
		}
	}
	if ((a == 'r') && (xp > 0)) {
		for (i = 0; i < 10; i++) {
			if ((mal[i] == 1) && (pt[i] == 0)) {
				if ((px == max[i]) && (py == may[i])) xp--,pt[i] = 1;
			}
		}
	}
	if (a == 'z') {
		if (nsi == 1) {
			if (stone > 0) stone--,rw[py][px] = '#';
		}
		if (nsi == 2) {
			if (dirt > 0) dirt--,rw[py][px] = '+';
		}
		if (nsi == 3) {
			if (spines > 0) spines--,rw[py][px] = '^';
		}
		if (nsi == 4) {
			if (gravel > 0) gravel--,rw[py][px] = '~';
		}
		if (nsi == 5) {
			if (flower > 0) flower--,rw[py][px] = '!';
		}
		if (nsi == 6) {
			if (wood > 0) wood--,rw[py][px] = '=';
		}
		if (nsi == 7) {
			if (iron > 0) iron--,rw[py][px] = ':';
		}
		if (nsi == 8) {
			if (fence > 0) fence--,rw[py][px] = '/';
		}
		if (nsi == 9) {
			if (water > 0) water--,rw[py][px] = '.';
		}
		if (nsi == 10) {
			if (crystal > 0) crystal--,rw[py][px] = '[';
		}
	}
}

void creation()
{
	printf("\n?");
	int numcr;
	scanf("%d",&numcr);
	if ((numcr == 1) && (stone >= 2) && (dirt >= 2)) {
		stone-=2,dirt-=2;
		gravel++;
	}
	if ((numcr == 2) && (spines >= 2) && (dirt >= 2) && (water >= 1)) {
		spines-=2,dirt-=2,water-=1;
		flower++;
	}
	if ((numcr == 3) && (spines >= 2) && (flower >= 2)) {
		spines-=2,flower-=2;
		wood++;
	}
	if ((numcr == 4) && (iron >= 3) && (crystal >= 1) && (armor == 0)) {
		iron-=3,crystal-=1;
		armor = 1;
	}
	if ((numcr == 5) && (iron >= 2) && (stone >= 2)) {
		iron-=2,stone-=2;
		fence++;
	}
	if ((numcr == 6) && (iron >= 3) && (wood >= 1) && (spines >= 1)) {
		spines-=1,iron-=3,wood-=1;
		crystal++;
	}
	if ((numcr == 7) && (iron >= 2) && (spines >= 1) && (bottle == 0)) {
		iron-=2,spines-=1;
		bottle = 1;
	}
}

void go_ma()
{
	if (pt[i] == 0) {
		rnd = rand() % 4 + 1;
		if (rnd == 1) may[i]++;
		if (rnd == 2) may[i]--;
		if (rnd == 3) max[i]++;
		if (rnd == 4) max[i]--;
	}
	if (pt[i] == 1) {
		if (max[i] > px+1) max[i]--;
		if (max[i] < px-1) max[i]++;
		if (may[i] > py+1) may[i]--;
		if (may[i] < py-1) may[i]++;
	}
	if (rw[may[i]][max[i]] == '!') rw[may[i]][max[i]] = '+';
	if (rw[may[i]][max[i]] == ',') rw[may[i]][max[i]] = ' ';
	if (rw[may[i]][max[i]] == '/') may[i] = amay[i],max[i] = amax[i];
}

void go_mb()
{
	if (mbx[i] > px) mbx[i]--;
	if (mbx[i] < px) mbx[i]++;
	if (mby[i] > py) mby[i]--;
	if (mby[i] < py) mby[i]++;
	if ((mbx[i] == px) && (mby[i] == py)) hp--,armor = 0;
	if (rw[mby[i]][mbx[i]] == '#') mby[i] = amby[i],mbx[i] = ambx[i];
	if (rw[mby[i]][mbx[i]] == '^') mby[i] = rand() % 30,mbx[i] = rand() % 50;
	if (rw[mby[i]][mbx[i]] == '=') mbl[i] = 0,xp++;
}

void go_mc()
{
	for (j = 0; j < 10; j++) {
		if ((mal[j] == 1) && (may[j] == mcy[i]) && (max[j] == mcx[i])) mal[j] = 0;
		if ((mbl[j] == 1) && (mby[j] == mcy[i]) && (mbx[j] == mcx[i])) mbl[j] = 0;
		if ((mdl[j] == 1) && (mdy[j] == mcy[i]) && (mdx[j] == mcx[i])) mdl[j] = 0;
	}
	if (mcx[i] > px) mcx[i]--;
	if (mcx[i] < px) mcx[i]++;
	if (mcy[i] > py) mcy[i]--;
	if (mcy[i] < py) mcy[i]++;
	if ((mcx[i] == px) && (mcy[i] == py)) hp = 0;
	if ((rw[mcy[i]][mcx[i]] == '.') || (rw[mcy[i]][mcx[i]] == ',')) mcl[i] = 0;
}

void go_md()
{
	rnd = rand() % 4 + 1;
	if (rnd == 1) mdy[i]++;
	if (rnd == 2) mdy[i]--;
	if (rnd == 3) mdx[i]++;
	if (rnd == 4) mdx[i]--;
	if (rw[mdy[i]][mdx[i]] == '#') mdy[i] = amdy[i],mdx[i] = amdx[i];
	if ((py == mdy[i]) && (px == mdx[i])) {
		printf("\nT?");
		a = getch();
		if (a == 'y') {
			rnd = rand() % 10 + 1;
			printf("\n%d iron",rnd);
			if (iron >= rnd) {
				iron-=rnd;
				rnd = rand() % 8 + 1;
				if ((rnd == 1) || (rnd == 2)) flower++;
				if ((rnd == 3) || (rnd == 4) || (rnd == 5)) stone++;
				if ((rnd == 6) || (rnd == 7)) spines++;
				if (rnd == 8) wood++;
				printf("\nOk");
			}
			else
				printf("\nNo");
		}
	}
}

void go_me()
{
	rnd = rand() % 4 + 1;
	if (rnd == 1) mey[i]++;
	if (rnd == 2) mey[i]--;
	if (rnd == 3) mex[i]++;
	if (rnd == 4) mex[i]--;
	if ((rw[mey[i]][mex[i]] != '.') && (rw[mey[i]][mex[i]] != ',')) mey[i] = amey[i],mex[i] = amex[i];
}

void tpp()
{
	if (sa == 1) {
		if (rw[py][px] == '#') py = apy,px = apx;
	}
	if ((rw[py][px] == '^') && (armor == 0)) hp--;
	if ((rw[py][px] == '!') && (hp < 15)) hp++;
}

void fw()
{
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 50; j++) {
			if ((rw[i][j] == '.') && (i < 29) && (i > 0) && (j < 49) && (j > 0)) {
				if (rw[i+1][j] == ' ') rw[i+1][j] = ',';
				if (rw[i-1][j] == ' ') rw[i-1][j] = ',';
				if (rw[i][j+1] == ' ') rw[i][j+1] = ',';
				if (rw[i][j-1] == ' ') rw[i][j-1] = ',';
			}
		}
	}
}

void grw()
{
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 50; j++) {
			rnd = rand() % 16 + 1;
			if ((rnd == 2) || (rnd == 3)) rw[i][j] = '#';
			else if ((rnd == 4) || (rnd == 5)) rw[i][j] = '+';
			else if ((rnd == 7) || (rnd == 8)) rw[i][j] = '^';
			else if (rnd == 9) rw[i][j] = ':';
			else if (rnd == 10) rw[i][j] = '.';
			else rw[i][j] = ' ';
		}
	}
}

void egrw()
{
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 50; j++) {
			rw[i][j] = ' ';
		}
	}
}

void map()
{
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 50; j++) {
			world[i][j] = rw[i][j];
		}
		world[i][50] = '\0';
	}
	if ((py > 29) || (px > 49) || (py < 0) || (px < 0)) py = apy,px = apx;
	for (i = 0; i < 10; i++) {
		if ((may[i] > 29) || (max[i] > 49) || (may[i] < 0) || (max[i] < 0)) may[i] = amay[i],max[i] = amax[i];
		if ((mby[i] > 29) || (mbx[i] > 49) || (mby[i] < 0) || (mbx[i] < 0)) mby[i] = amby[i],mbx[i] = ambx[i];
		if ((mcy[i] > 29) || (mcx[i] > 49) || (mcy[i] < 0) || (mcx[i] < 0)) mcy[i] = amcy[i],mcx[i] = amcx[i];
		if ((mdy[i] > 29) || (mdx[i] > 49) || (mdy[i] < 0) || (mdx[i] < 0)) mdy[i] = amdy[i],mdx[i] = amdx[i];
		if ((mey[i] > 29) || (mex[i] > 49) || (mey[i] < 0) || (mex[i] < 0)) mey[i] = amey[i],mex[i] = amex[i];
	}
	world[py][px] = syp;
	for (i = 0; i < 10; i++) {
		if (mal[i] == 1) {
			world[may[i]][max[i]] = '@';
		}
		if (mbl[i] == 1) {
			world[mby[i]][mbx[i]] = '&';
		}
		if (mcl[i] == 1) {
			world[mcy[i]][mcx[i]] = 'R';
		}
		if (mdl[i] == 1) {
			world[mdy[i]][mdx[i]] = 'T';
		}
		if (mel[i] == 1) {
			world[mey[i]][mex[i]] = '_';
		}
	}
}

void oxy_a()
{
	apy = py,apx = px;
	for (i = 0; i < 10; i++) {
		amay[i] = may[i],amax[i] = max[i];
		amby[i] = mby[i],ambx[i] = mbx[i];
		amcy[i] = mcy[i],amcx[i] = mcx[i];
		amdy[i] = mdy[i],amdx[i] = mdx[i];
		amey[i] = mey[i],amex[i] = mex[i];
	}
}

void itm_p()
{
	printf("\n1 Stone: %d",stone);
	printf("\n2 Dirt: %d",dirt);
	printf("\n3 Spines: %d",spines);
	printf("\n4 Gravel: %d",gravel);
	printf("\n5 Flower: %d",flower);
	printf("\n6 Wood: %d",wood);
	printf("\n7 Iron: %d",iron);
	printf("\n8 Fence: %d",fence);
	printf("\n9 Water: %d",water);
	printf("\n10 Crystal: %d",crystal);
	a = getch();
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
	else if (a == 'm') {
		printf("\n?");
		int numsm;
		scanf("%d",&numsm);
		if (numsm == 1) {
			for (i = 0; i < 10; i++) {
				if (mal[i] == 0) mal[i] = 1,max[i] = px,may[i] = py,i=10;
			}
		}
		if (numsm == 2) {
			for (i = 0; i < 10; i++) {
				if (mbl[i] == 0) mbl[i] = 1,mbx[i] = px,mby[i] = py,i=10;
			}
		}
		if (numsm == 3) {
			for (i = 0; i < 10; i++) {
				if (mcl[i] == 0) mcl[i] = 1,mcx[i] = px,mcy[i] = py,i=10;
			}
		}
		if (numsm == 4) {
			for (i = 0; i < 10; i++) {
				if (mdl[i] == 0) mdl[i] = 1,mdx[i] = px,mdy[i] = py,i=10;
			}
		}
		if (numsm == 5) {
			for (i = 0; i < 10; i++) {
				if (mel[i] == 0) mel[i] = 1,mex[i] = px,mey[i] = py,amey[i] = mey[i],amex[i] = mex[i],i=10;
			}
		}
	}
	else if (a == 'v') {
		printf("\nhp:");
		scanf("%d",&hp);
		printf("\nxp:");
		scanf("%d",&xp);
	}
	else if (a == 'n') {
		int na=0,nb=0,nc=0,nd=0,ne=0;
		for (i = 0; i < 10; i++) {
			if (mal[i] == 1) na++;
			if (mbl[i] == 1) nb++;
			if (mcl[i] == 1) nc++;
			if (mdl[i] == 1) nd++;
			if (mel[i] == 1) ne++;
		}
		printf("\n@: %d",na);
		printf("\n&: %d",nb);
		printf("\nR: %d",nc);
		printf("\nT: %d",nd);
		printf("\n_: %d",ne);
		a = getch();
	}
	else if (a == 's') {
		printf("\nSeed: %d",seed);
		a = getch();
	}
	else if (a == 'g') {
		printf("\nNumber of moves: %d",mv);
		a = getch();
	}
	else {
		printf("\n???");
	}
}

int main()
{
	printf("\nPUBLIC DOMAIN SOFTWARE");
	printf("\nCollandbuild");
	printf("\nVersion 1.3.0\n");
	printf("\nseed:");
	scanf("%d",&seed);
	srand(seed);
	printf("\nS/E?");
	scanf(" %c",&a);
	for (i = 0; i < 10; i++) {
		mal[i] = 0;
		mbl[i] = 0;
		mdl[i] = 0;
		mcl[i] = 0;
		mel[i] = 0;
	}
	if (a == 's') {
		hp = 5,xp = 0,stone = 0,dirt = 0,spines = 0,gravel = 0,flower = 0,wood = 0,iron = 0,fence = 0,water = 0,crystal = 0;
		for (i = 0; i < 4; i++) {
			mal[i] = 1;
			mdl[i] = 1;
		}
		for (i = 0; i < 2; i++) {
			mbl[i] = 1;
		}
		mel[0] = 1;
		grw();
	}
	if (a == 'e') {
		hp = 999,xp = 999,stone = 9999,dirt = 9999,spines = 9999,gravel = 9999,flower = 9999,wood = 9999,iron = 9999,fence = 9999,water = 9999,crystal = 9999;
		egrw();
	}
	printf("\nImmortal?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') imr = 1;
	else imr = 0;
	printf("\nCommands?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') cm = 1;
	else cm = 0;
	printf("\nIs the stone active?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') sa = 1;
	else sa = 0;
	printf("\nPlayer symbol:");
	scanf(" %c",&syp);
	py = 2,px = 2,armor = 0,bottle = 0,nsi = 1,mv = 0;
	for (i = 0; i < 10; i++) {
		max[i] = rand() % 50;
		may[i] = rand() % 30;
		mbx[i] = rand() % 50;
		mby[i] = rand() % 30;
		mcx[i] = 0;
		mcy[i] = 0;
		mdx[i] = rand() % 50;
		mdy[i] = rand() % 30;
		mex[i] = rand() % 50;
		mey[i] = rand() % 30;
		pt[i] = 0;
	}
	oxy_a();
	do
	{
		mv++;
		fw();
		map();
		oxy_a();
		for (i = 0; i < 30; i++) {
			printf("\n%s",world[i]);
		}
		printf("\nHP: %d",hp);
		printf("\nXP: %d",xp);
		printf("\nNumber of the selected item: %d",nsi);
		printf("\nArmor: ");
		if (armor == 1)
			printf("yes");
		else
			printf("no");
		printf(", Bottle: ");
		if (bottle == 1)
			printf("yes");
		else
			printf("no");
		a = getch();
		printf("\033[H\033[2J\033[3J");
		if (a == 'w') py--;
		if (a == 's') py++;
		if (a == 'd') px++;
		if (a == 'a') px--;
		if (a == 'i') {
			itm_p();
		}
		if ((a == 't') && (cm == 1)) {
			com();
		}
		if (a == 'c') {
			creation();
		}
		cb();
		tpp();
		for (i = 0; i < 10; i++) {
			if (mal[i] == 1) {
				go_ma();
			}
			if (mbl[i] == 1) {
				go_mb();
			}
			if (mcl[i] == 1) {
				go_mc();
			}
			if (mdl[i] == 1) {
				go_md();
			}
			if (mel[i] == 1) {
				go_me();
			}
		}
		if (imr == 1) hp = 100;
		if (a == 'q') hp = 0;
	}
	while (hp > 0);
	printf("\nEND GAME");
	return 0;
}