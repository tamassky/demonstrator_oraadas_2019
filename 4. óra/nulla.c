//https://progcont.hu/progcont/100165/?pid=200919
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *foo(int n, int h, int w){
	static char s[100005]="";
	int kar = 0;
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int l=0;l<w;l++){
				if(i==0 || i==h-1 || l==0 || l==w-1)
					s[kar]='*';
				else
					s[kar]=' ';
				kar++;
			}
			if(j!=n-1){
				s[kar]=' ';
				kar++;
			}
		}
		s[kar]='\n';
		kar++;
	}
	s[kar]='\0';
	return s;
}

/*int main()
{
    char *result = foo(4, 5, 3);
    printf("%s", result);
    free(result);
    return EXIT_SUCCESS;
}*/

