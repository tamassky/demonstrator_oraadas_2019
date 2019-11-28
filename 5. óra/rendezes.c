#include <stdio.h>
#include <stdlib.h>

int hasonlit(int a, int b){
	if(a<b) //csokkenobe rendez, mert akkor cserel, ha az utobbi nagyobb
		return 1;
	return 0;
}

void csere(int* a, int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


void bub_rendez(int t[], int n){
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(hasonlit(t[j], t[j+1]))
				csere(&t[j], &t[j+1]);
}

int hasonlit_qsort(const void* x1, const void* x2){
	int* a = (int*) x1;
	int* b = (int*) x2;
	if(*a>*b)//novekvobe rendez, mert akkor cserel, ha az elobbi nagyobb
		return 1;
	return 0;
}

int main(){
	int t[10]={5,3,9,7,14,10,2,11,23,1};
	//bub_rendez(t,10);
	qsort(t, 10, sizeof(int), hasonlit_qsort);
	for(int i=0;i<10;i++)
		printf("%d ", t[i]);
	return 0;
}
