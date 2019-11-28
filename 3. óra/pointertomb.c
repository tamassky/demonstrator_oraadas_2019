#include <stdio.h>

int main(){
	//Pointerek
	int a=5;
	int *p;
	p = &a;
	printf("Memoriacim: %p\n Tarolt ertek:%d\n", p, *p);

	int b=9;
	p++;
	printf("Memoriacim: %p\n Tarolt ertek:%d\n", p, *p);

	p--;

	(*p)++; //ugyanaz, mint a++
	printf("Memoriacim: %p\n Tarolt ertek:%d\n", p, *p);
	
	//Egydimenzios tombok
	int t[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	for(int i=0;i<20;i++){
		printf("%d ", t[i]);
	}
	puts("");
	//t[3] <=> *(t+3)
	int t2[5];
	for(int i=0;i<5;i++){
		scanf("%d", &t2[i]);
	}
	for(int i=0;i<5;i++){
		printf("%d ", t2[i]);
	}
	return 0;
}
