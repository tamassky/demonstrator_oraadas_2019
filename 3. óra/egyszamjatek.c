#include <stdio.h>

int main(){
	int n,i,a;
	int hanyan_mondtak[35];
	while(scanf("%d", &n)!=EOF){
		for(i=1; i<=30; i++)
			hanyan_mondtak[i] = 0;
		for(i=0; i<n; i++){
			scanf("%d", &a);
			hanyan_mondtak[a]++;
		}
		int nyertes=-1;
		for(i=30; i>=1; i--)
			if(hanyan_mondtak[i] == 1)
				nyertes = i;
		if(nyertes == -1)
			puts("Nobody wins");
		else
			printf("%d\n", nyertes);
	}
	return 0;
}
