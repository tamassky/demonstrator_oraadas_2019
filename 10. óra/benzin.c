//https://progcont.hu/progcont/100108?pid=200715
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct car
{
    char type[30];
    int max_speed;
    char fuel;
}CAR;

int hasonlit(const void* x1, const void* x2){
	CAR* a = (CAR*) x1;
	CAR* b = (CAR*) x2;
	if(a->max_speed == b->max_speed)
		return strcmp(a->type, b->type);
	return b->max_speed - a->max_speed;
}

CAR *foo(char* file_name, int speed){
	FILE* fp = fopen(file_name,"rb");
	CAR tmp;
	CAR *t = malloc(10000*sizeof(CAR));
	int db = 0;
	while(fread(&tmp, sizeof(CAR), 1, fp)==1){
		if(tmp.fuel=='B' && tmp.max_speed>speed){
			strcpy(t[db].type, tmp.type);
			t[db].max_speed = tmp.max_speed;
			t[db].fuel = tmp.fuel;
			db++;
		}
	}
	qsort(t, db, sizeof(CAR), hasonlit);
	fclose(fp);
	t[db].max_speed = -1;
	return t;
}
