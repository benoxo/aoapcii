#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    char s[100];
    int N, len, period;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", s);
        period = len = strlen(s);
        for (int p = 1; p < len; p++) {
            if (len % p) continue;
            int k;
            for (k = p; k < len; k++) {
                if (s[k%p] != s[k])
                    break;
            }
            if (k == len) {
                period = p; break;
            }

        }
        printf("%d\n", period);
        if (N) printf("\n");
    }
    
    return 0;
}
 
