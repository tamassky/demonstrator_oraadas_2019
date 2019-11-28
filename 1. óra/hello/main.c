#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define gyokketto 1.41

int main()
{
    int a=5, b=7;
    printf("%d\n", a/b);
    printf("%f\n", a/(float)b);
    printf("%d\n", a%b);
    a--;
    b++;
    printf("%d %d\n", a, b);
    a+=2; //a = a + 2;
    b-=3; //b = b - 3;
    a=15; b=25;

    (a>b)? printf("%d\n", a): printf("%d\n", b);

    int r = 2147483640;
    r+=10;
    printf("%d\n", r);

   /* int w;
    scanf("%d", &w);
    printf("%d\n", w);*/

    double p;
    p=gyokketto;
    printf("%0.2lf\n", p);

    char c1='g', c2='E', c3='6', c4='.';
    printf("%d %d %d %d\n", isalnum(c1), isalnum(c2), isalnum(c3), isalnum(c4));
    printf("%d %d %d %d\n", isalpha(c1), isalpha(c2), isalpha(c3), isalpha(c4));
    printf("%d %d %d %d\n", isdigit(c1), isdigit(c2), isdigit(c3), isdigit(c4));
    printf("%d %d %d %d\n", islower(c1), islower(c2), islower(c3), islower(c4));
    printf("%d %d %d %d\n", isupper(c1), isupper(c2), isupper(c3), isupper(c4));

    srand(time(NULL));
    printf("%d\n", rand()%301-100);
    printf("%d\n", INT_MIN);
    printf("%d\n", INT_MAX);

    ceil(2.7);
    floor(2.6);
    exp(5);
    pow(4.5, 1.4);
    sqrt(16);

    return 0;
}
