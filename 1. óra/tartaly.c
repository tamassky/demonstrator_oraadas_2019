//Számítsuk ki hány liter víz fér el egy henger alakú tartálytban! Hány doboz festék szükséges a tartály kifestéséhez! Egy doboz festék 2 m^2 kifestésére elég. (2 tizedes pontossággal)

#include <stdio.h>

#define pi 3.1415 //#define pi acos(-1.0) <--- pontosabb, kell hozzá math.h

int main(){
	double atmero, magassag;
	printf("Hany meter a tartaly atmeroje? ");
	scanf("%lf", &atmero);
	printf("Hany meter a tartaly magassaga? ");
	scanf("%lf", &magassag);
	double terfogat = pi * (atmero/2) * (atmero/2) * magassag;
	printf("A tartalyban %0.2lf liter viz fer el.\n", terfogat*1000);
	double of = atmero * pi * magassag;
	printf("A tartaly kifestesehez %0.2lf doboz szukseges.\n", of/2);
	return 0;
}
