#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    int dispnum[12], N, end, cur;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &end); 
        memset(dispnum, 0, sizeof(dispnum));
        for (int i = 1; i <= end; i++) {
            cur = i;
            while (cur) {
                dispnum[cur%10]++;
                cur /= 10;
            }
        }
        for (int i = 0; i < 9; i++) {
            printf("%d ", dispnum[i]);
        }
        printf("%d\n", dispnum[9]);
    }
    
    
    return 0;
}
 
