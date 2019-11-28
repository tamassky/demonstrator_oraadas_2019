///https://progcont.hu/progcont/100158/?pid=200904
///Elismerem...ez nem egy könnyû feladat duplapointeres adatszerkezetek nélkül, de megoldható...
#include <stdio.h>
#include <stdlib.h>

void rajzol(int n){
    int i;
    char* paros_sor = (char*) malloc ((n+1)*sizeof(char));
    for(i=0; i<n; i++)
        paros_sor[i] = '*';
    paros_sor[n] = '\0';
    printf("%s\n", paros_sor);
    char* paratlan_sor = (char*) malloc ((n+1)*sizeof(char));
    paratlan_sor[0] = '*';
    for(i=1; i<n-1; i++)
        paratlan_sor[i] = ' ';
    paratlan_sor[n-1] = '*';
    paratlan_sor[n] = '\0';
    if(n>1)
        printf("%s\n", paratlan_sor);

    for(i=2; i<n; i++){
        if(i <= n/2){
            if(i%2 == 0){
                paros_sor[i-1] = ' ';
                paros_sor[n-i] = ' ';
                printf("%s\n", paros_sor);
            }
            else{
                paratlan_sor[i-1] = '*';
                paratlan_sor[n-i] = '*';
                printf("%s\n", paratlan_sor);
            }
        }
        if(i == n/2+1)
            printf("%s\n",paratlan_sor);
        if(i > n/2+1){
            if(i%2 == 0){
                paros_sor[i-1] = '*';
                paros_sor[n-i] = '*';
                printf("%s\n", paros_sor);
            }
            else{
                paratlan_sor[i-1] = ' ';
                paratlan_sor[n-i] = ' ';
                printf("%s\n", paratlan_sor);
            }
        }
    }
}

int main()
{
    int n, x, i;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d", &x);
        int hossz = 4*x-3;
        rajzol(hossz);
        if(i!=n)
            puts("");
    }
    return 0;
}
