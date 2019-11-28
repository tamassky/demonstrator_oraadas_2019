//https://progcont.hu/progcont/100197/?pid=201031
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int legnagyobb(int *t, int n){
    int i;
    int maxim = INT_MIN;
    for(i=0;i<n;i++)
        if(t[i]>maxim)
            maxim = t[i];
    return maxim;
}

int foo(int* t, int n){
    int i;
    int maxim;
    maxim = legnagyobb(t,n);
    int* elofordulas = (int*) calloc(maxim+1, sizeof(int));
    for(i=0;i<n;i++)
        elofordulas[t[i]]++;
    int db = 0;
    for(i=0;i<=maxim;i++)
        if(elofordulas[i])
            db++;
    free(elofordulas);
    return db;
}

 /*   int main()
    {
        int t[] = {1, 20, 300, 1, 20, 300, 1, 20, 300, 1, 20};
        int size = sizeof(t) / sizeof(int);
        printf("%d\n", foo(t, size));
        return EXIT_SUCCESS;
    }*/
