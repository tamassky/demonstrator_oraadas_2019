///https://progcont.hu/progcont/100165/?pid=200921
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n, x, i;
    int sor = 0;
    int* minim = (int*) malloc(sizeof(int));
    int abszolut_minim = INT_MAX;
    while(scanf("%d", &n) != EOF){
        minim = (int*) realloc(minim, (sor+1)*sizeof(int));
        minim[sor] = INT_MAX;
        for(i=0; i<n; i++){
            scanf("%d", &x);
            if(x < minim[sor])
                minim[sor] = x;
        }
        if(minim[sor] < abszolut_minim)
            abszolut_minim = minim[sor];
        sor++;
    }

    for(i=0; i<sor; i++)
        if(minim[i] == abszolut_minim)
            printf("%d\n", i+1);
    return 0;
}
