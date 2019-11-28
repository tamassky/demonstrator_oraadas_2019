#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct teszt{
    char nev[35];
    int elert, elerheto;
    double arany;
}TESZT;

int hasonlit(const void* x1, const void* x2){
    TESZT* a = (TESZT*) x1;
    TESZT* b = (TESZT*) x2;
    if(a->arany < b->arany)
        return 1;
    if(a->arany == b->arany && strcmp(a->nev,b->nev)>0)
        return 1;
    return 0;
}

void kiir(TESZT* t, int n){
    int i = 0;
    while(i<n && t[i].arany>=0.5){
        printf("%s (%d/%d)\n", t[i].nev, t[i].elert, t[i].elerheto);
        i++;
    }
}

int main()
{
    char s[1000];
    int n = 0;
    TESZT t[25];
    while(gets(s)!=NULL){
        char* token;
        token = strtok(s,":");
        strcpy(t[n].nev, token);
        t[n].elert=0;
        t[n].elerheto=0;
        while((token = strtok(NULL,"/"))!=NULL){
            t[n].elert+=atoi(token);
            token = strtok(NULL,",");
            t[n].elerheto+=atoi(token);
        }
        t[n].arany = t[n].elert/(double)t[n].elerheto;
        n++;
    }
    qsort(t,n,sizeof(TESZT),hasonlit);
    kiir(t,n);
    return 0;
}
