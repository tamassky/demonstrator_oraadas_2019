#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adat{
	char keresztnev[21];
	int honap;
	int nap;
}ADAT;

int main(int argc, char* argv[]){
	FILE* f = fopen("in.bin", "wb");
	ADAT t[5];
	strcpy(t[0].keresztnev, "Laci");
	t[0].honap = 7;
	t[0].nap = 10;
	strcpy(t[1].keresztnev, "Laci");
	t[1].honap = 2;
	t[1].nap = 14;
	strcpy(t[2].keresztnev, "Laci");
	t[2].honap = 2;
	t[2].nap = 8;
	strcpy(t[3].keresztnev, "Laci");
	t[3].honap = 7;
	t[3].nap = 21;
	strcpy(t[4].keresztnev, "Karcsi");
	t[4].honap = 4;
	t[4].nap = 3;
	fwrite(t, sizeof(ADAT), 5, f);
	fclose(f);
	return 0;		
}
