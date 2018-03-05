#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int layer = n, stars, blanks;
    while (layer > 0) {
        stars = (layer-1)*2+1;
        blanks = n - layer;
        for (int i = 0; i < blanks; i++) {
            printf(" ");
        }
        for (int i = 0; i < stars; i++) {
            printf("#");
        }
        printf("\n");
        layer--;
    }
    
    return 0;
}
