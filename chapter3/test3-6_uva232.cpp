#include <stdio.h>
#include <string.h>
#define MAXN 15

int r, c, kase, h;
char data[MAXN][MAXN];
int els[MAXN][MAXN];
int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    kase = 1;
    while (scanf("%d %d", &r, &c) == 2) {
        h = 1;
        memset(els, 0, sizeof(els));
        getchar();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%c", data[i]+j);
                if (data[i][j] != '*') {
                    if (i == 0 || (i > 0 && data[i-1][j] == '*') ||
                        j == 0 || (j > 0 && data[i][j-1] == '*')) {
                        els[i][j] = h++;
                    }
                }
            }
            getchar();
        }
        
        if (kase > 1) printf("\n");
        printf("puzzle #%d:\n", kase++);
        printf("Across\n");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (els[i][j] == 0) continue;
                else {
                    printf("%3d.", els[i][j]);
                    while (j < c && data[i][j] != '*') {
                        printf("%c", data[i][j]);
                        j++;
                    }
                    printf("\n");
                }
            }
        }
        
        printf("Down\n");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (els[i][j] == 0 || (i > 0 && data[i-1][j] != '*')) continue;
                else {
                    printf("%3d.", els[i][j]);
                    int row = i;
                    while (row < r && data[row][j] != '*') {
                        printf("%c", data[row][j]);
                        row++;
                    }
                    printf("\n");
                }
            }
        }
        
    }
    
    return 0;
}
