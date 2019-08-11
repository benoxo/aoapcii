#include <stdio.h>
#include <string.h>

int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    char s[100], c;
    int N, len, onum, ans;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", s);
        len = strlen(s);
        onum = 0; ans = 0;
        for (int i = 0; i < len; i++) {
            c = s[i];
            if (c == 'O') {
                ans += ++onum;
            } else {
                onum = 0;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
 
