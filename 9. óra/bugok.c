//https://progcont.hu/progcont/100189?pid=201005
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *foo(char *s){
	char* t = malloc(sizeof(char)*1000); //Ez a kulcs...
	strcpy(t,s);
	while(strstr(t, "BUG") != NULL){
		int h = strlen(t);
		int i, pos;
		for(i=0; i<h-2; i++)
			if(t[i]=='B' && t[i+1]=='U' && t[i+2]=='G')
				pos = i;
		for(i=pos; i<h-2; i++)
			t[i] = t[i+3];
	}
	return t;
}

/*int main()
{
    char *t[] = {"almafa", "almaBUGfa", "almaBBUGUGfa"};
    int i;
    for (i = 0; i < 3; ++i)
    {
        char *p = foo(t[i]);
        puts(p);
        free(p);
    }
    return EXIT_SUCCESS;
}*/

