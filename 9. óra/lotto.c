//https://progcont.hu/progcont/100270/?pid=201274
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element
{
    int week_id;
    int numbers[5];
}ELEM;

void olvas(FILE* fp, int x){
	ELEM t[1000];
	int db = 0;
	while(fread(&t[db], sizeof(ELEM), 1, fp)==1){
		db++;
	}
	printf("%d\n", db);
	for(int i=0; i<db; i++){
		int yes=0;
		printf("%d: %d", t[i].week_id, t[i].numbers[0]);
		if(t[i].numbers[0] == x)
			yes = 1;
		for(int j=1; j<5; j++){
			printf(",%d", t[i].numbers[j]);
			if(t[i].numbers[j] == x)
			yes = 1;
		}
		if(yes)
			printf(" YES\n");
		else
			printf(" NO\n");
	}
}

int main(int argc, char* argv[]){
	FILE* f = fopen(argv[1], "rb");
	int keresett_szam = atoi(argv[2]);
	olvas(f, keresett_szam);
	fclose(f);
	return 0;		
}
