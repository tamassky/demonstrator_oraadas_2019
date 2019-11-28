#include <stdio.h>
 
int main() {
    int magas;
    printf("Milyen magas legyen a piramis? ");
    scanf("%d", &magas);
 
    for (int sor=0; sor<magas; sor=sor+1) {
        for (int x=0; x<magas-sor-1; x=x+1)
            printf(" ");
        for (int x=0; x<sor*2+1; x=x+1)
            printf("o");
        printf("\n");
    }
 
    return 0;
}

