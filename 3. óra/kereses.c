#include <stdio.h>
#define N 10
int main(){

	int t[N]={2,3,5,7,11,13,17,19,23,29};
	int a;	
	printf("Keresett szam: ");
	scanf("%d", &a);
	
	//Linearis kereses
	int poz=-1;
	for(int i=0;i<N;i++)
		if(t[i]==a){
			poz = i;
			break; //Valamennyit gyorsithat
		}
	if(poz==-1)
		printf("Nincs benne.\n");
	else
		printf("Benne van a %d. pozicion.\n", poz);

	//Binaris kereses, csak rendezett tombokre!
	int bal=0, jobb=N-1;
	while(bal<=jobb){
		int kozep = (bal + jobb) / 2;
		if(t[kozep] == a){ //Megtalaltuk
			printf("Benne van a %d. pozicion.\n", kozep);
			break;
		}
		if(t[kozep] < a) //Ha nagyobb a kozepsonel, elhagyjuk a bal felet
			bal = kozep + 1;
		if(t[kozep] > a) //Ha kisebb a kozepsonel, elhagyjuk a jobb felet
			jobb = kozep - 1;  
		
		if(bal>jobb) // Le fog allni, nem talaltuk meg
			printf("Nincs benne.\n");
	}
	return 0;
}
