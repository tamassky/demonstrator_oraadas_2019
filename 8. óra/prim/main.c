///https://progcont.hu/progcont/100196/?pid=201030
///Ha tudn�nk, mekkora lehet maximum egy bolvasott sz�m, haszn�lhatn�nk ezt, az egy�bk�nt sokkal hat�konyabb algoritmust: https://hu.wikipedia.org/wiki/Eratoszthen%C3%A9sz_szit%C3%A1ja
///Mivel azonban nem tudjuk, egyenk�nt kell minden sz�mr�l ellen�rizz�k, hogy pr�m-e
///Ennek egy m�dszere, hogy megsz�moljuk az oszt�k sz�m�t: ha csak 2 van (1 �s �nmaga), akkor pr�m. A hat�konys�g n�vel�se �rdek�ben nem kell ellen�rizz�nk, csak a n�gyzetgy�k�ig a sz�mnak.
///Teh�t, ha 2 �s sqrt(n) k�z�tt nincs oszt�ja az n sz�mnak, akkor az n sz�m pr�m.

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
