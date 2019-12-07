#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adat{
    char name[20];
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
    f = fopen(argv[1], "rb");
    ADAT t[1000], tmp;

    int db = 0;
    while(fread(&tmp,sizeof(ADAT),1,f)==1){
        strcpy(t[db].name,tmp.name);
        t[db].hour = tmp.hour;
        t[db].minute = tmp.minute;
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
