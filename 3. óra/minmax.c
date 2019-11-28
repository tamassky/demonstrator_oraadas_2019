#include <stdio.h>
#include <limits.h>

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int min = INT_MAX;
		int max = INT_MIN;
		int t[25];
		for(int i=0; i<n; i++){
			scanf("%d", &t[i]);
			if(t[i]>max)
				max = t[i];
			if(t[i]<min)
				min = t[i];
		}
		int dbmin=0;
		int dbmax=0;
		for(int i=0; i<n; i++){
			if(t[i]==max)
				dbmax++;
			if(t[i]==min)
				dbmin++;
		}
		printf("%d %d\n", dbmin, dbmax);
	}
	return 0;
}
