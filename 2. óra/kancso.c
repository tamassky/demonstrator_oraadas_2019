#include <stdio.h>

int main(){
	int x, otos=0, harmas=0, tolteni;
	while(scanf("%d", &x)!=EOF){
		printf("%d %d\n", harmas, otos);
		switch(x){
			case 0:
				return 0;
				break;
			case -5:
				otos=0;
				break;
			case -3:
				harmas=0;
				break;
			case 3:
				harmas=3;
				break;
			case 5:
				otos=5;
				break;
			case 35:
				if(harmas>5-otos)
					tolteni=5-otos;
				else
					tolteni=harmas;
				harmas-=tolteni;
				otos+=tolteni;
				break;
			case 53:
				if(otos>3-harmas)
					tolteni=3-harmas;
				else
					tolteni=otos;
				otos-=tolteni;
				harmas+=tolteni;
				break;	
		}
	}
}
