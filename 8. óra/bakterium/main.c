///https://progcont.hu/progcont/100110/?pid=200722
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adat{
    char nev[15];
    char dupl[15];
    int sum;
    int db;
}ADAT;

int darab(char s[]){
    int i;
    int db = 0;
    for(i=0; i<strlen(s); i++)
        if(s[i]=='1')
            db++;
    return db;
}

int hatvany(int alap, int kitevo){
    int i;
    int eredmeny = 1;
    for(i=1; i<=kitevo; i++)
        eredmeny *= alap;
    return eredmeny;
}

int hasonlit(const void* x1, const void* x2){
    ADAT* a = (ADAT*) x1;
    ADAT* b = (ADAT*) x2;
    if(a->sum < b->sum)
        return 1;
    if(a->sum == b->sum && strcmp(a->nev, b->nev)>0)
        return 1;
    return 0;
}

int main()
{
    ADAT t[25];
    char s[30];
    int db = 0;
    while(scanf("%s", s) != EOF){
        char* token = strtok(s, "/");
        strcpy(t[db].nev, token);
        token = strtok(NULL, "/");
        strcpy(t[db].dupl, token);
        t[db].db = darab(t[db].dupl);
        t[db].sum = hatvany(2, t[db].db);
        db++;
    }
    qsort(t, db, sizeof(ADAT), hasonlit);
    int i = 0;
    while(t[i].db >= 7){
        printf("%s %d\n", t[i].nev, t[i].sum);
        i++;
    }
    return 0;
}
