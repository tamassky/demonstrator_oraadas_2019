#include <stdio.h>

int hatvanyozas(int alap, int kitevo){
	if(kitevo==0)
		return 1;	
	if(kitevo%2==0)
		return hatvanyozas(alap,kitevo/2)*hatvanyozas(alap,kitevo/2);
	if(kitevo%2==1)
		return hatvanyozas(alap,kitevo/2)*hatvanyozas(alap,kitevo/2)*alap;
}

int main(){
	int alap, kitevo;
	puts("Alap:");
	scanf("%d", &alap);
	puts("Kitevo:");
	scanf("%d", &kitevo);
	printf("%d\n", hatvanyozas(alap,kitevo));
	return 0;
}
