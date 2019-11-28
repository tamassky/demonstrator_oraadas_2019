//https://progcont.hu/progcont/100143/?pid=200844
#include <stdio.h>
#include <stdlib.h>

int csillag(int a, int b, int i, int j){
    if(i==0 || i==a-1 || i==a/2) //elso, kozepso vagy utolso sor
        return 1;
    if(j==0 && i<=a/2) //elso oszlop, ha a sor fele es folotte van
        return 1;
    if(j==b-1) //utso oszlop
        return 1;
    return 0;
}

void draw(int a, int b){
    int i,j;
    for(i=0;i<a;i++){
        for(j=0;j<b;j++)
            if(csillag(a,b,i,j))
                printf("*");
            else
                printf(" ");
        puts("");
    }
}

int main()
{
    int a,b,n,i;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d %d", &a, &b);
        draw(a,b);
        if(i!=n-1) //utolso teszteset utan nem kell dupla soremeles!!
            puts("");
    }
    return 0;
}
