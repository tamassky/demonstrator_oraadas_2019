//https://progcont.hu/progcont/100130?pid=200794
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int duplaz(char* arg, char a){
	if(strchr(arg,'u')!=NULL && isupper(a))
		return 1;
	if(strchr(arg,'l')!=NULL && islower(a))
		return 1;
	if(strchr(arg,'d')!=NULL && isdigit(a))
		return 1;
	return 0;
}

int main(int argc, char* argv[]){
	FILE* f_in = fopen(argv[argc-1], "r");
	if(argc<2 || argc>3 || (argc==3 && argv[1][0]!='-') || f_in==NULL){
		puts("Error!");
		return 0;
	}
	char c;
	while(fscanf(f_in, "%c", &c) != EOF){
		printf("%c", c);
		if(argc==3)
			if(duplaz(argv[1],c))
				printf("%c", c);
	}
	fclose(f_in);
	return 0;
}
