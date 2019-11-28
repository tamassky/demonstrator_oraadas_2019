#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[35];
    while(gets(s)!=NULL){
        if(strcmp(s, "THE END")==0)
            break;
        int kisbetu = 0;
        int nagybetu = 0;
        for(int i=0; i<strlen(s); i++){
            if(islower(s[i]))
                kisbetu++;
            if(isupper(s[i]))
                nagybetu++;
        }
        printf("%d %d ", nagybetu, kisbetu);
        if((nagybetu+kisbetu)/(double)strlen(s) > 0.5)
            puts("STRONG");
        else
            puts("WEAK");
    }
    return 0;
}
