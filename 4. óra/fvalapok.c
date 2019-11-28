#include <stdio.h>

int lnko(int a, int b){
	while(a!=b){
		if(a>b)
			a-=b;
		else
			b-=a;
	}
	return b;
}

int lnko_cim(int* a, int* b){
	while(*a!=*b){
		if(*a>*b)
			*a-=*b;
		else
			*b-=*a;
	}
	return *b;
}

void lnko_kiir(int a, int b){
	while(a!=b){
		if(a>b)
			a-=b;
		else
			b-=a;
	}
	printf("Lnko: %d\n", b);
}

int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	printf("%d\n", lnko(a,b));
	printf("%d %d\n", a, b);
	printf("%d\n", lnko_cim(&a,&b));
	printf("%d %d\n", a, b);
	lnko_kiir(a,b);
	return 0;
}
