#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    int stat[255];
    int i;
    for(i='A'; i<='Z'; i++)
        stat[i]=0;
    FILE* fp;
    fp = fopen(argv[1], "r");
    char s[25];
    while(fgets(s,21,fp)!=NULL){
        stat[toupper(s[0])]++;
    }
    for(i='A'; i<='Z'; i++)
        if(stat[i]>0)
            printf("%c: %d\n",i,stat[i]);
    fclose(fp);
    return 0;
}
