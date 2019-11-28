#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(char **s, int m, int n){
    char pont[10005]=".";
    int i,j,pontok;
    for(i=0;i<m;i++){
        pontok = n - strlen(s[i]);
        for(j=0;j<pontok;j++){
            strcat(pont, s[i]);
            s[i]="";
            strcpy(s[i],pont);
        }
    }
}


int main()
{
    char *t[3] = {"alma", "dio", "barack"};
    int i;
    foo(t, 3, 10);
    for (i = 0; i < 3; ++i)
        printf("%s\n", t[i]);
    return EXIT_SUCCESS;
}
