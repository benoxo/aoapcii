#include <stdio.h>
#include <string.h>
#define MAXN 100005
int ans[MAXN];

int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    int N;
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i < MAXN; i++) {
        int a = i, sum = i;
        while (a > 0) {
            sum += a % 10;
            a /= 10;
        }
        if (sum >= MAXN) {
            break;
        } 
        if (ans[sum] == 0) ans[sum] = i;
    }
    scanf("%d", &N);
    while (N--) {
        int c;
        scanf("%d", &c);
        printf("%d\n", ans[c]);
    }
    return 0;
} 
