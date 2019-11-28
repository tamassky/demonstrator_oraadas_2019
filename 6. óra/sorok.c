//https://progcont.hu/progcont/100270/?pid=201273
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sor{
	char nev[25];
	int hossz;
}SOR;

int hasonlit(const void* x1, const void* x2){
	SOR* a = (SOR*) x1;
	SOR* b = (SOR*) x2;
	if(a->hossz < b->hossz)
		return 1;
	if(a->hossz == b->hossz && strcmp(a->nev, b->nev)>0)
		return 1;
	return 0;
}

int main(int argc, char* argv[]){
	FILE* f_in = fopen(argv[1], "r");
	SOR* t = (SOR*) malloc(sizeof(SOR));
	int i=0;
	while(fgets(t[i].nev, 25, f_in) != NULL){
		t[i].hossz = strlen(t[i].nev);
		i++;
		t = (SOR*) realloc(t, sizeof(SOR)*(i+1));
	}
	qsort(t,i,sizeof(SOR),hasonlit);
	printf("%d\n",i);
	int j=0;
	while(t[j].hossz == t[0].hossz){
		printf("%s",t[j].nev);
		j++;
	}
	free(t);
	fclose(f_in);
	return 0;
}
