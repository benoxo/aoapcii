#include <stdio.h>

int main() {
    int a, b, c, k, kase = 1;
    while (scanf("%d %d %d", &a, &b, &c) == 3) {
        for (int i = 10; i <= 100; i++) {
            if (i%3==a && i%5==b && i%7==c) {
                printf("Case %d: %d", kase++, i);
                break;
            }
            if (i == 100) {
                printf("Case %d: No answer", kase++);
            }
        }
    }
    return 0;
}
