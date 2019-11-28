#include <stdio.h>
#include <limits.h>

int main(){
	int x,db=0;
	int max=INT_MIN, min=INT_MAX;
	while(scanf("%d", &x)!=EOF){
		if(x>max)
			max=x;
		if(x<min)
			min=x;
		db++;
	}
	printf("%d %d\n", max-min, 200*(db-1));
	return 0;
}

