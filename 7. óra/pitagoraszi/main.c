//https://progcont.hu/progcont/100198/?pid=201038
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pit(int a, int b, int c){
    if(a*a + b*b == c*c)
        return 1;
    if(a*a + c*c == b*b)
        return 1;
    if(b*b + c*c == a*a)
        return 1;
    return 0;
}

int main()
{
    int a,b,c;
    while(scanf("%d %d %d", &a, &b, &c)!=EOF){
        if(pit(a,b,c))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
