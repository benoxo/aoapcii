#include <stdio.h>
#include <string.h>

char s[210];
int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    int N, mins, len;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", s);
        len = strlen(s);
        strncpy(s+len, s, len);
        mins = 0;
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (strncmp(s+mins, s+i, len) > 0) {
                    mins = i;
                }
            }
        }
        
        for (int i = 0; i < len; i++) {
            printf("%c", s[mins+i]);
        }
        printf("\n");
    }
    
    return 0;
} 
