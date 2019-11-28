//https://progcont.hu/progcont/100049/?pid=200580

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int main(){
	char s[305];
	char nev[35];
	int pontszam, pont, min, max;
	while(gets(s) != NULL){
		char* token = strtok(s,"#");
		strcpy(nev, token);
		min = INT_MAX;
		max = INT_MIN;
		pontszam = 0;
		token = strtok(NULL,"#");
		while(token != NULL){
			pont = atoi(token);
			if(pont < min)
				min = pont;
			if(pont > max)
				max = pont;
			pontszam += pont;
			token = strtok(NULL, "#");
		}
		pontszam -= max;
		pontszam -= min;
		printf("%s: %d\n", nev, pontszam);
	}
	return 0;
}
