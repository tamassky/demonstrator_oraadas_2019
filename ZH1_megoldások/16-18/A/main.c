#include <stdio.h>
#include <stdlib.h>

int foo(const void* x1, const void* x2){
    int* a = (int*) x1;
    int* b = (int*) x2;
    int voa=0, vob=0, i;
    for(i=2;i<(*a);i++)
        if((*a)%i==0)
            voa++;
    for(i=2;i<(*b);i++)
        if((*b)%i==0)
            vob++;
     //   printf("%d %d %d %d \n", *a, *b, voa, vob);
    return voa-vob;
}

/*int main(){
    int t[] = {4,6,30,2};
    int i;
    qsort(t,4,sizeof(int),foo);
    for(i=0;i<4;i++)
        printf("%d\n", t[i]);
    return EXIT_SUCCESS;
}*/
