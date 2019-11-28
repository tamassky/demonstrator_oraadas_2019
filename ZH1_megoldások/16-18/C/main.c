#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n,x;
    int minim, maxim;
    while(scanf("%d", &n)!=EOF){
        minim = INT_MAX;
        maxim = INT_MIN;
        for(int i=1; i<=n; i++){
            scanf("%d", &x);
            if(x<minim)
                minim = x;
            if(x>maxim)
                maxim = x;
        }
        printf("%d %d\n", minim, maxim);
    }
    return 0;
}
