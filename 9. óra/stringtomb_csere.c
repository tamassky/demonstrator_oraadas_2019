#include <stdio.h>
#include <string.h>

void kiir(char **s, int n){
	for(int i=0; i<n; i++)
		puts(s[i]);
	puts("");
}

int main(){
	char *s[5] = {"nulladik", "elso", "masodik", "harmadik", "negyedik"};
	kiir(s, 5);

	//Elso modszer (logikai csere / pointerek csereje) - AJANLOTT!
	char *tmp = s[0];
	s[0] = s[2];
	s[2] = tmp;
	kiir(s, 5);

	//Masodik modszer (fizikai csere), csak akkor hasznaljuk, ha biztosan van eleg memoria foglalva!!
	char tmp2[100];
	strcpy(tmp2, s[0]);
	strcpy(s[0], s[2]); //!!!ELSZALL, mert s[0]-n nincs eleg memoria fogalva s[2]-nek
	strcpy(s[2], tmp2); 
	kiir(s, 5);

	return 0;
}
