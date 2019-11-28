//https://progcont.hu/progcont/100126/?pid=200774
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct eloleny{
	char leny_neve[35];
	float irritacio_faktor;
	char megjegyzes[35];
}ELOLENY;

int hasonlit(const void* x1, const void* x2){
	ELOLENY* a = (ELOLENY*) x1;
	ELOLENY* b = (ELOLENY*) x2;
	if((*a).irritacio_faktor < b->irritacio_faktor) //ket felirasi mod ugyanaz
		return 1;
	if(a->irritacio_faktor == b->irritacio_faktor && strcmp(a->leny_neve, b->leny_neve)<0)
		return 1;
	return 0;
}

int main(){
	char s[100];
	ELOLENY t[33];
	int db=0;
	while(gets(s)!=NULL){ //!!
		char* token = strtok(s,";");
		strcpy(t[db].leny_neve, token);
		token = strtok(NULL,";"); //!!
		t[db].irritacio_faktor = atof(token);
		token = strtok(NULL,";");
		strcpy(t[db].megjegyzes, token);
		db++;
	}
	qsort(t,db,sizeof(ELOLENY),hasonlit);
	for(int i=0;i<3;i++)
		printf("%s (%.1f): %s\n", t[i].leny_neve, t[i].irritacio_faktor, t[i].megjegyzes);
	return 0;
}
