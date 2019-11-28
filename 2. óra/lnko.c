#include <stdio.h>
#include <math.h>

int main(){
	{
	int a,b;
	scanf("%d %d", &a, &b);
	if(a>b)
		printf("%d\n", a);
	else
		printf("%d\n", b);
	}

	//Masodfoku egyenlet
	{
	double a,b,c;
	scanf("%lf %lf %lf", &a, &b, &c);
	double delta = b*b-4*a*c;
	if(delta<0)
		printf("Nincs megoldas:(\n");	
	else
		if(delta>0)
			printf("Ket megoldas: x1=%lf; x2=%lf\n", -b+sqrt(delta)/(2*a), -b-sqrt(delta)/(2*a));
		else
			printf("Egy megoldas: x=%lf\n", -b/(2*a));
	}
	
	//Allapotgep-osztalyzat
	int jegy;
	scanf("%d", &jegy);
	switch(jegy){
		case 1:
			puts("Elegtelen");
			break;
		case 2:
			puts("Elegseges");
			break;
		case 3:
			puts("Kozepes");
			break;
		case 4:
			puts("Jo");
			break;
		case 5:
			puts("Jeles");
			break;
		default:
			puts("Nem erdemjegy!!");
	}*/
	
	//Legnagyobb kozos oszto
	//Naiv modszer
	{
		int a,b;
		scanf("%d %d", &a, &b);
		int i,lnko=1,n;
		if(a>b)
			n=b;
		else
			n=a;
		for(i=2;i<=n;i++)
			if(a%i==0 && b%i==0)
				lnko=i;
		printf("lnko: %d\n", lnko);
	}
	
	{
		int a,b;
		scanf("%d %d", &a, &b);
		while(1){
			if(a>b)
				a-=b;
			else if(a<b)
					b-=a;
			else
				break;
		}
		printf("lnko: %d\n", b);
	}

	{
		int a,b;
		scanf("%d %d", &a, &b);
		while(a!=b){
			if(a>b)
				a-=b;
			else
				b-=a;
		}
		printf("lnko: %d\n", b);
	}

	{
		int a,b,r;
		scanf("%d %d", &a, &b);
		while(1){
			r=a%b;
			if(r==0)
				break;
			//else
			a=b;
			b=r;
		}
		printf("lnko: %d\n", b);
	}
	
	{
		int a,b,r;
		scanf("%d %d", &a, &b);
		r=a%b;
		while(r!=0){
			a=b;
			b=r;
			r=a%b;
		}
		printf("lnko: %d\n", b);
	}

	{
		int a,b,r;
		scanf("%d %d", &a, &b);
		for(r=a%b; r!=0; r=a%b){
			a=b;
			b=r;
		}
		printf("lnko: %d\n", b);
	}

	{
		int a,b,r;
		scanf("%d %d", &a, &b);
		for(;(r=a%b)!=0;){
			a=b;
			b=r;
		}
		printf("lnko: %d\n", b);
	}

	{
		int a,b,r;
		scanf("%d %d", &a, &b);
		for(;r=a%b;){
			a=b;
			b=r;
		}
		printf("lnko: %d\n", b);
	}

	{
		int a,b,r;
		for(scanf("%d %d", &a, &b); r=a%b; a=b,b=r);
		printf("lnko: %d\n", b);
	}*/

	//1-100 kiveve, ami oszthato 5-tel (continue)
	{
		for(int i=1;i<=100;i++){
			if(i%5==0)
				continue;
			printf("%d ", i);	
		}
	}

	return 0;
}
