///https://progcont.hu/progcont/100249/?pid=201211
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(const char* forras, char* cel){
    int h = strlen(forras);
    int i,j;
    for(i=0; i<=h; i++){
        if(forras[i]=='@' || forras[i]=='\0' || forras[i]=='=')
            cel[i] = forras[i];
        else{
            for(j=i-1; j>=0; j--)
                if(cel[j]=='='){
                    cel[j] = '*';
                    break;
                }
            cel[i] = '=';
        }
    }

}

/*int main()
{
    char source[100], destination[100];
    while (fgets(source, 100, stdin) != NULL)
    {
        if (source[strlen(source) - 1] == '\n')
            source[strlen(source) - 1] = '\0';
        foo(source, destination);
        printf("%s\n", destination);
    }
    return EXIT_SUCCESS;
}*/
