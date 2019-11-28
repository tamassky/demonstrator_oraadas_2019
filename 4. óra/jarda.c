#include <stdio.h>

int jarda(int hossz) {
    if (hossz == 1)
        return 1;
    if (hossz == 2)
        return 2;

    return jarda(hossz - 1) + jarda(hossz - 2);
}

int main() {
    int h;
    printf("Hossz?\n");
    scanf("%d", &h);

    printf("%d lehetőség.\n", jarda(h));
}

