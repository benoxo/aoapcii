#include <stdio.h>

int main() {
    int a, b, c, kase = 1;
    double result;
    while (scanf("%d%d%d", &a, &b, &c)) {
        if (a == 0 && b == 0 && c == 0) break;
        printf("Case %d: %d", kase, a/b);
        if (c > 0) printf(".");
        int d = a % b;
        for (int i = 0; i < c-1; i++) {
            d *= 10;
            printf("%d", d / b);
            d = d % b;
        }
        d *= 10;
        printf("%.lf", d*1.0 / b);
    }
    
    return 0;
}
