//https://progcont.hu/progcont/100227?pid=201128
#include <stdio.h>

int main(int argc, char* argv[]){
	FILE* f_in = fopen(argv[1], "r");
	char c,elso,elozo;
	int flag = 1, yes = 1;
	while(fscanf(f_in, "%c", &c) != EOF){
		if(flag)
			elso = c;
		flag = 0;
		if(c=='\n'){
			flag = 1;
			if(elozo != elso){
				yes = 0;
				break;
			}
		}
		elozo = c;
	}
	fclose(f_in);
	if(yes)
		puts("YES");
	else
		puts("NO");
	return 0;
}
