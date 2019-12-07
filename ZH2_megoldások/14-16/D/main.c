#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adat{
    char name[20];
    int hour;
    int minute;
}ADAT;

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

    int kulonbozo = 0;
    int i,j;
    for(i=0;i<db;i++){
        int uj=1;
        for(j=0;j<i;j++){
            if(strcmp(t[i].name, t[j].name)==0){
                uj=0;
                break;
            }
        }
        if(uj)
            kulonbozo++;
    }
    printf("%d\n", kulonbozo);

    fclose(f);
    return 0;
}
