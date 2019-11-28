//https://progcont.hu/progcont/100266?pid=201257
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

	FILE* fp;
	fp = fopen(argv[1], "r");
	char egyik[1000][35];
	int egyik_db = 0;
	while(fgets(egyik[egyik_db], 35, fp)!=NULL){
		egyik_db++;
	}
	fclose(fp);

	fp = fopen(argv[2], "r");
	char masik[1000][35];
	int masik_db = 0;
	while(fgets(masik[masik_db], 35, fp)!=NULL){
		masik_db++;
	}
	fclose(fp);

	for(int i=0; i<egyik_db; i++){
		int masikban_szerepel = 0;
		for(int j=0; j<masik_db; j++)
			if(strcmp(egyik[i], masik[j])==0){
				masikban_szerepel = 1;
				break;			
			}
		if(!masikban_szerepel)
			printf("%s", egyik[i]); ///Az fgets a sortorest is beolvasta!
	}

	for(int i=0; i<masik_db; i++){
		int masikban_szerepel = 0;
		for(int j=0; j<egyik_db; j++)
			if(strcmp(masik[i], egyik[j])==0){
				masikban_szerepel = 1;
				break;			
			}
		if(!masikban_szerepel)
			printf("%s", masik[i]);
	}
	return 0;
}
