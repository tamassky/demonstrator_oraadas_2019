//https://progcont.hu/progcont/100196/?pid=201029
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bad(char* s, int x){
    int i;
    int h = strlen(s);
    for(i=0;i<x;i++)
        if(s[i]!=s[h-x+i])//<-- itt a kulcs
            return 1;
    return 0;
}

int main()
{
    char s[55];
    int x;
    while(scanf("%d %s", &x, s)!=EOF){
        if(bad(s,x))
            puts("Bad");
        else
            puts("Good");
    }
    return 0;
}
