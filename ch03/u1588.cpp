#include <stdio.h>
#include <string.h>
#include <math.h>

char s1[110], s2[110];

int check_min(char *s1, char *s2) {
    int i1, i2, len1, len2;
    len1 = strlen(s1);
    len2 = strlen(s2);
    int minlen = 0;
    bool down = true;
    for (i1 = 0; i1 < len1; i1++) {
        down = true;
        for (i2 = 0; i2 < len2 && i1 + i2 < len1; i2++) {
            if (s1[i1+i2] + s2[i2] -'0'*2 > 3) {
                down = false;
                break;
            }
        } 
        if (down) {
            if (i2 == len2) {
                minlen = len1;
            } else {
                minlen = i1 + len2;
            }
            break;
        }
    }
    if (minlen == 0) minlen = len1+len2;
    return minlen;
}

int main() {

    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    while (scanf("%s%s", s1, s2) == 2) {
        int minlen = fmin(check_min(s1, s2), check_min(s2, s1));
        printf("%d\n", minlen);
    }
    
    return 0;
}

