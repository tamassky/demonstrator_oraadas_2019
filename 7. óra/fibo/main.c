#include <stdio.h>
#include <stdlib.h>

void beolv(int t[], int n){
    int i;
    for(i=0;i<n;i++)
        scanf("%d", &t[i]);
}

void fibo_felepit(int fibo[]){
    fibo[1] = 1;
    int a = 1, b = 1;
    int sum = a + b;
    while(sum <= 100000){
        fibo[sum] = 1;
        a = b;
        b = sum;
        sum = a + b;
    }
}

int mind_fibo(int t[], int n, int fibo[]){
    int i;
    for(i=0;i<n;i++)
        if(!fibo[t[i]])
            return 0;
    return 1;
}

int main()
{
    int* fibo = (int*) calloc(100001,sizeof(int));
    fibo_felepit(fibo);
    int n;
    scanf("%d", &n);
    while(n!=0){
        int* t = (int*) malloc(sizeof(int)*n);
        beolv(t,n);
        if(mind_fibo(t,n,fibo))
            puts("YES");
        else
            puts("NO");
        free(t);
        scanf("%d", &n);
    }
    free(fibo);
    return 0;
}
