//https://progcont.hu/progcont/100269?pid=201267
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int foo(const char * const * s, int n){
	char *minim = s[0];
	int minim_pos = 0;
	for(int i=1; i<n; i++)
		if(strcmp(minim, s[i]) > 0){
			minim = s[i];
			minim_pos = i;
		}

	int db=0;
	for(int i=0; i<n; i++)
		if(strcmp(minim, s[i])==0)
			db++;

	return db;
}

/*int main()
{
    const char *t[] = {"narancs", "alma", "eper", "alma", "meggy", "eper"};
    printf("%u\n", foo(t, 6));
    return EXIT_SUCCESS;
}*/

