#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adat{
    char name[21];
    int hour;
    int minute;
}ADAT;

int hasonlit(const void* x1, const void* x2){
    ADAT* a = (ADAT*)x1;
    ADAT* b = (ADAT*)x2;
    return strcmp(a->name, b->name);
}

int main(int argc, char* argv[])
{
    FILE* f;
    f = fopen(argv[1], "r");
    ADAT t[1000];

    char s[50];
    int db = 0;
    while(fgets(s,45,f)!=NULL){
        char* token;
        token = strtok(s,";");
        strcpy(t[db].name,token);
        token = strtok(NULL,";");
        t[db].hour = atoi(token);
        token = strtok(NULL,";");
        t[db].minute = atoi(token);
        db++;
    }

    qsort(t,db,sizeof(ADAT),hasonlit);

    int bent = 0;
    int szakasz = 1;
    for(int i=1; i<db; i++){
        if(strcmp(t[i-1].name, t[i].name)==0)
            szakasz++;
        else{
            if(szakasz % 2 == 1)
                bent++;
            szakasz = 1;
        }
    }
    if(szakasz % 2 == 1 && db!=0)
        bent++;
    printf("%d\n", bent);

    fclose(f);
    return 0;
}
