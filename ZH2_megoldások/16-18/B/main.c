#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int good_a_vege(char s[]){
    int h = strlen(s);
    if(s[h-5]=='g' && s[h-4]=='o' && s[h-3]=='o' && s[h-2]=='d')
        return 1;
    else
        return 0;
}

int main(int argc, char* argv[])
{
    FILE* fp;
    fp = fopen(argv[1], "r");
    char s[1000][55];
    int i = 0;
    int db = 0;
    while(fgets(s[i],55,fp)!=NULL){
        if(good_a_vege(s[i]))
            db++;;
        i++;
    }
    printf("%d\n", db);
    for(int j=0;j<i;j++)
        if(good_a_vege(s[j]))
            printf("%s", s[j]);
    fclose(fp);
    return 0;
}
