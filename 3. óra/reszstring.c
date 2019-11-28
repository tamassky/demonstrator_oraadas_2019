#include <stdio.h>
#include <string.h>

int main(){
	char s[55];
	int x;
	while(scanf("%d %s", &x, s)!=EOF){
		int max=1;
		int hossz=1;		
		for(int i=1;i<strlen(s);i++){
			if(s[i]==s[i-1])
				hossz++;
			else
				hossz=1;		
			if(hossz>max)
				max=hossz;
		}
		if(max>=x)
			puts("Good");
		else
			puts("Bad");
	}
	return 0;
}
