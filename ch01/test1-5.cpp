#include <cstdio>

int main() {
    int n, total;
    const int price  = 95;
    scanf("%d", &n);
    total = n * 95;
    if (total >= 300) printf("%.2lf", total*0.85);
    else printf("%.2lf", total*1.0);
    return 0;
}
