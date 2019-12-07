#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* foo(const char* s){
    char* t = malloc(1000*sizeof(char));
    int h = 0;
    for(int i=0; i<=strlen(s); i++){
        int db=1;
        while(s[i+1]==s[i]){
            db++;
            i++;
        }
        t[h]=s[i];
        h++;
        t[h]=db+'0';
        h++;

    }

    t[h]='\0';
    return t;
}

/*int main(){
    char *s[]= {"hello", "world", "Mississippi"};
    int i;
    for(i=0;i<sizeof(s)/sizeof(char*);++i){
        char *p = foo(s[i]);
        printf("%s\n",p);
        free(p);
    }
    return EXIT_SUCCESS;
}*/
