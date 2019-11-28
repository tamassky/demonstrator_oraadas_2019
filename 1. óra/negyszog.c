//Kérjük be egy tetszőleges négyszög pontjainak koordinátáit (óra járásával ellentétes irányban, a koordináták egész számok), és állapítsuk meg a négyszög kerületét és területét! Feltételezzük, hogy a bemenő adatok helyesek, és nincs három kolineáris pont.

#include <stdio.h>
#include <math.h>

int main(){
	int x1,y1,x2,y2,x3,y3,x4,y4;
	puts("1. pont koordinatai: ");
	scanf("%d %d", &x1, &y1);
	puts("2. pont koordinatai: ");
	scanf("%d %d", &x2, &y2);
	puts("3. pont koordinatai: ");
	scanf("%d %d", &x3, &y3);
	puts("4. pont koordinatai: ");
	scanf("%d %d", &x4, &y4);

	double oldal12, oldal23, oldal34, oldal14, atlo13;
	double kerulet, fk123, fk134, t123, t134, terulet;

	oldal12 = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	oldal23 = sqrt(pow(x2-x3,2)+pow(y2-y3,2));
	oldal34 = sqrt(pow(x3-x4,2)+pow(y3-y4,2));
	oldal14 = sqrt(pow(x1-x4,2)+pow(y1-y4,2));
	kerulet = oldal12 + oldal23 + oldal34 + oldal14;
	
	atlo13 = sqrt(pow(x1-x3,2)+pow(y1-y3,2));
	fk123 = (oldal12 + oldal23 + atlo13)/2;
	fk134 = (oldal34 + oldal14 + atlo13)/2;
	t123 = sqrt(fk123*(fk123-oldal12)*(fk123-oldal23)*(fk123-atlo13));
	t134 = sqrt(fk134*(fk134-oldal34)*(fk134-oldal14)*(fk134-atlo13));
	terulet = t123 + t134;
	
	printf("A negyszog kerulete %0.2lf, terulete %0.2lf.\n", kerulet, terulet);
	return 0;
} 
