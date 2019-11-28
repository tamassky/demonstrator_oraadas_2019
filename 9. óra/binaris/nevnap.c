//https://progcont.hu/progcont/100058?pid=200603
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adat{
	char keresztnev[21];
	int honap;
	int nap;
}ADAT;

int olvas(FILE* fp, ADAT* t, char* nev){
	ADAT tmp;
	int db = 0;
	while(fread(&tmp, sizeof(ADAT), 1, fp)==1){
		if(strcmp(tmp.keresztnev, nev)==0){
			strcpy(t[db].keresztnev, tmp.keresztnev);
			t[db].honap = tmp.honap;
			t[db].nap = tmp.nap;
			db++;
		}
	}
	return db;
}

int hasonlit(const void* x1, const void* x2){
	ADAT* a = (ADAT*) x1;
	ADAT* b = (ADAT*) x2;
	if(a->honap == b->honap)
		return a->nap - b->nap;
	return a->honap - b->honap;
}

int main(int argc, char* argv[]){
	FILE* elso = fopen(argv[1], "rb");
	FILE* masodik = fopen(argv[2], "wb");
	char nev[22];
	strcpy(nev, argv[3]);
	ADAT t[1000]; 
	int n = olvas(elso, t, nev);
	qsort(t, n, sizeof(ADAT), hasonlit);
	/*for(int i=0; i<n;i++)
		printf("%s %d %d\n", t[i].keresztnev, t[i].honap, t[i].nap);*/
	fwrite(t, sizeof(ADAT), n, masodik);
	fclose(elso);
	fclose(masodik);
	return 0;		
}
