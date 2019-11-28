//https://progcont.hu/progcont/100112?pid=200742
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(char *t[], int n, int m){
	for(int i=0;i<n*m-1;i++)
		for(int j=i+1;j<n*m;j++)
			if(strcmp(t[i],t[j])==0)
				return 0; 
	return 1;
}

/*int main()
{
    char *m[2][3] = {{"galambtojas", "furjtojas", "kakukktojas"},
                     {"kakastojas",  "tyuktojas", "okostojas"}};
    if (foo(&m[0][0], 2, 3))
        puts("YES");
    else
        puts("NO");
    return EXIT_SUCCESS;
}*/

