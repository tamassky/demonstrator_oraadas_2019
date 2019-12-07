#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adat{
    char name[21];
    int hour;
    int minute;
}ADAT;

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
