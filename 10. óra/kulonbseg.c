//https://progcont.hu/progcont/100181?pid=200976
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* kivonas(char* kisebbitendo, char* kivonando){
	int hossz = strlen(kisebbitendo);
	char* eredmeny = malloc(sizeof(char)*(1+hossz));
	char* nulla = malloc(sizeof(char)*(1+hossz));
    nulla[0]='0';
    nulla[1]='\0';
	while(strlen(kivonando)!=hossz){
		strcpy(kivonando, strcat(nulla, kivonando));
        nulla[0]='0';
        nulla[1]='\0';
	}
	//FIGYELEM!  "kivonando = strcat("0", kivonando);" NEM JO!!
	// "kivonando = strcat(nulla, kivonando)" SEM
	for(int i = hossz-1; i>=0; i--){
		if(kisebbitendo[i]>=kivonando[i])
			eredmeny[i] = kisebbitendo[i] - kivonando[i] + '0';
		else{
			int j=i-1;
			while(kisebbitendo[j]==0)
				j--;
			kisebbitendo[j]--;
			for(int k=j+1; k<i; k++)
				kisebbitendo[k] = 9;
			eredmeny[i] = 10 + kisebbitendo[i] - kivonando[i] + '0';
		}
	}
	free(nulla);
	eredmeny[hossz]='\0';
	return eredmeny;
}

int main(int argc, char* argv[]){
	char* elso = malloc( (strlen(argv[1])+1) * sizeof(char) );
	char* masodik = malloc( (strlen(argv[1])+1) * sizeof(char) );
	strcpy(elso, argv[1]);
	strcpy(masodik, argv[2]);
	char* kulonbseg = kivonas(elso, masodik);	
	int mehet = 0;
	for(int i=0; i<strlen(kulonbseg); i++){
		if(kulonbseg[i]!='0')
			mehet = 1;
		if(mehet)
			printf("%c", kulonbseg[i]);
	}
	if(!mehet)
		printf("0");
	puts("");
	free(kulonbseg);
	free(elso);
	free(masodik);
	return 0;
}
