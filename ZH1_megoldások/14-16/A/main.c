#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(const void* x1, const void* x2) {
    char* a = *(char**) x1;
    char* b = *(char**) x2;
    int suma=0, sumb=0, i;
    for(i=0; i<strlen(a); i++)
        suma += (a[i] - 'A' + 1);
    for(i=0; i<strlen(b); i++)
        sumb += (b[i] - 'A' + 1);
    return suma-sumb;
}

/*int main(){
    char *t[20] = {"PEAR", "RASPBERRY", "APPLE", "ORANGE"};
    int i;
    qsort(t,4,sizeof(char *), foo);
    for(i=0;i<4;++i)
        printf("%s\n", t[i]);
    return EXIT_SUCCESS;
}*/
