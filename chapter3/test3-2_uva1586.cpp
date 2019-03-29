#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    char s[100], c;
    double m[30];
    m['C'-'A'] = 12.01; m['H'-'A'] = 1.008;
    m['O'-'A'] = 16.00; m['N'-'A'] = 14.01;
    int N, len, num;
    double ans;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", s);
        len = strlen(s);
        ans = 0;
        for (int i = 0; i < len; i++) {
            c = s[i];
            num = 0;
            if (isalpha(c)) {
                while (i+1 < len && isdigit(s[i+1])) {
                    num = num*10+s[i+1]-'0';
                    ++i;
                }
                if (num == 0) num = 1;
                ans += num*m[c-'A'];
            }
        }
        printf("%.3lf\n", ans);
    }
    
    return 0;
}
 
