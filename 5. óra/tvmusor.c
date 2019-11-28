//https://progcont.hu/progcont/100050/?pid=200567

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musor{
	char nev[35];
	char ado[35];
	char nap[15];
	int ora;
	int perc;
}MUSOR;

int hasonlit(const void* x1, const void* x2){
	MUSOR* a = (MUSOR*) x1;
	MUSOR* b = (MUSOR*) x2;
	if(a->ora > b->ora)
		return 1;
	if(a->ora == b->ora && a->perc > b->perc)
		return 1;
	if(a->ora == b->ora && a->perc == b->perc && strcmp(a->ado, b->ado) > 0)
		return 1;
	return 0;
}

int main(){
	MUSOR t[405];
	int db=0;
	char nap[15];
	scanf("%s", nap);
	while(scanf("%s %s %s %d:%d", t[db].nev, t[db].ado, t[db].nap, &t[db].ora, &t[db].perc) != EOF)
		db++;
	qsort(t, db, sizeof(MUSOR), hasonlit);
	for(int i=0; i<db; i++)
		if(strcmp(t[i].nap, nap) == 0){
			printf("%s %s ", t[i].nev, t[i].ado);
			if(t[i].ora < 10)
				printf("0");
			printf("%d:", t[i].ora);
			if(t[i].perc < 10)
				printf("0");
			printf("%d\n", t[i].perc);
		}
	return 0;
}
