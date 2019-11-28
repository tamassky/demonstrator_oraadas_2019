#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(){
	char s[25];
	int hossz[55];
	int min = INT_MAX;
	int db=0;
	while(scanf("%s",s)!=EOF){
		db++;
		hossz[db] = strlen(s);
		if(strlen(s)<min)
			min = strlen(s);
	}
	printf("%d\n", min);
	int elso_kiirva = 0;
	for(int i=1;i<=db;i++){
		if(hossz[i]==min && elso_kiirva)
			printf(" %d", i);
		if(hossz[i]==min && !elso_kiirva){
			printf("%d", i);
			elso_kiirva = 1;
		}
	}
	puts("");
	return 0;
}
