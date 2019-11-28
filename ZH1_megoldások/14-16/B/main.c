#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adat{
    char nev[100];
    int db;
}ADAT;

int hasonlit(const void* x1, const void* x2) {
    ADAT* a = (ADAT*) x1;
    ADAT* b = (ADAT*) x2;
    if(a->db == b->db)
        return strcmp(a->nev, b->nev);
    return b->db - a->db;
}

int main()
{
    ADAT t[25];
    char s[105];
    int i=0;
    while(scanf("%s", s)!=EOF){
        char* token;
        token = strtok(s,":");
        strcpy(t[i].nev, token);
        t[i].db = 0;
        while(token!=NULL){
            token = strtok(NULL,",");
            t[i].db++;
        }
        i++;
    }
    qsort(t,i,sizeof(ADAT), hasonlit);
    for(int j=0; j<i; j++)
        printf("%s\n",t[j].nev);
    return 0;
}
