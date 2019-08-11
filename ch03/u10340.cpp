#include <stdio.h>
#include <string.h>
#define MAXN 10000000

char s1[MAXN], s2[MAXN];
int len1, len2;
int main() {

    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    bool find;
    while (scanf("%s %s", s1, s2) == 2) {
        len1 = strlen(s1);
        len2 = strlen(s2);
        int i = 0, j = 0; 
        for (; i < len1; i++) {
            find = false;
            for (; j < len2; j++) {
                if (s1[i] == s2[j]) {
                    find = true;
                    j++;
                    break;
                }
            }
            if (!find) break;
        }
        if (i == len1) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
