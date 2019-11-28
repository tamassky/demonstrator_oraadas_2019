#include <stdio.h>
#include <stdlib.h>

int main()
{
    int elofordulas[25];
    int n;
    while(scanf("%d", &n)!=EOF){
        for(int i=1; i<=n ;i++)
            elofordulas[i] = 0;
        for(int i=1; i<=n; i++){
            int x;
            scanf("%d", &x);
            if(x<=n)
                elofordulas[x]++;
        }
        int yes=1;
        for(int i=1; i<=n ;i++)
            if(elofordulas[i]!=1){
                yes = 0;
                puts("NO");
                break;
            }
        if(yes)
            puts("YES");
    }
    return 0;
}
