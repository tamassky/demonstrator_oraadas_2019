///https://progcont.hu/progcont/100143/?pid=200846
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int ora = 0, perc = 0;
    char s[10];
    while(scanf("%s", s)!=EOF){
        if(strcmp(s,"END")==0){
            if(perc>59){
                ora += perc/60;
                perc = perc%60;
            }
            printf("%d.", ora);
            if(perc<10)
                printf("0");
            printf("%d\n", perc);
            ora = 0;
            perc = 0;
        }
        else{
            char* token;
            token = strtok(s,".");
            ora += atoi(token);
            token = strtok(NULL,".");
            perc += atoi(token);
        }
    }
    return 0;
}
