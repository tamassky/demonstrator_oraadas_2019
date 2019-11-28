///https://progcont.hu/progcont/100196/?pid=201030
///Ha tudnánk, mekkora lehet maximum egy bolvasott szám, használhatnánk ezt, az egyébként sokkal hatékonyabb algoritmust: https://hu.wikipedia.org/wiki/Eratoszthen%C3%A9sz_szit%C3%A1ja
///Mivel azonban nem tudjuk, egyenként kell minden számról ellenõrizzük, hogy prím-e
///Ennek egy módszere, hogy megszámoljuk az osztók számát: ha csak 2 van (1 és önmaga), akkor prím. A hatékonyság növelése érdekében nem kell ellenõrizzünk, csak a négyzetgyökéig a számnak.
///Tehát, ha 2 és sqrt(n) között nincs osztója az n számnak, akkor az n szám prím.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prim(int x){
    if(x==1)
        return 0;
    for(int i=2; i<=sqrt(x); i++)
        if(x%i == 0)
            return 0;
    return 1;
}

int main()
{
    int n, x, yes;
    scanf("%d", &n);
    while(n!=0){
        yes = 1;
        for(int i=0; i<n; i++){
            scanf("%d", &x);
            if(!prim(x)){
                yes = 0;
            }
        }
        if(yes)
            puts("YES");
        else
            puts("NO");
        scanf("%d", &n);
    }
    return 0;
}
