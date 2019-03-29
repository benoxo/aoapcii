#include <stdio.h>
#include <string.h>

char str[60][1100];
char css[1100];
int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    int k, m, n;
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++) {
            scanf("%s", str[i]);
        }
        
        int err = 0;
        for (int j = 0; j < n; j++) {
            int time[4];
            memset(time, 0, sizeof(time));
            for (int i = 0; i < m; i++) {
                switch(str[i][j]) {
                case 'A': time[0]++; break;
                case 'C': time[1]++; break;
                case 'G': time[2]++; break;
                case 'T': time[3]++; break;
                }
            }
            
            char maxi = 0;
            for (int i = 1; i < 4; i++) {
                if (time[i] > time[maxi]) {
                    maxi = i;
                }
            }
            err += (m-time[maxi]); 
            
            switch(maxi) {
            case 0: css[j] = 'A'; break;
            case 1: css[j] = 'C'; break;
            case 2: css[j] = 'G'; break;
            case 3: css[j] = 'T'; break;
            }
        }
        css[n] = '\0';
        printf("%s\n", css);
        printf("%d\n", err);
    }
    
    return 0;
} 
