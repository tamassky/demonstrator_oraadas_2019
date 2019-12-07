#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* foo(const char* s){
    char* t = malloc(1000*sizeof(char));
    int h = 0;
    for(int i=0; i<=strlen(s); i=i+2){
        for(int j=0; j<s[i+1]-'0'; j++){
            t[h] = s[i];
            h++;
        }
    }
    t[h]='\0';
    return t;
}

/*int main(){
    char *s[]= {"h1e1l2o1", "w1o1r1l1d1", "M1i1s2i1s2i1p2i1"};
    int i;
    for(i=0;i<sizeof(s)/sizeof(char*);++i){
        char *p = foo(s[i]);
        printf("%s\n",p);
        free(p);
    }
    return EXIT_SUCCESS;
}*/
