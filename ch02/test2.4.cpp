#include <stdio.h>

int main() {
    long long n, m;
    int kase = 1;
    double result = 0;
    while (scanf("%lld %lld", &n, &m)) {
        if (n == 0 && m == 0) break;
        result = 0;
        for (long long i = n; i <= m; i++) {
            result += 1.0 / (i*i);
        }
        printf("Case %d: %.5lf", kase++, result);
    }
    
    return 0;
}
