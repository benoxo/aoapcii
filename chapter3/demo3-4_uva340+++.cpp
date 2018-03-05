#include <stdio.h>
#include <string.h>

int N;
int inputs[1005];
int guess[1005];
int th;
int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    int A, P;
    th = 0;
    while (scanf("%d", &N) == 1 && N != 0) {
        printf("Game %d:\n", ++th);
        for (int i = 0; i < N; i++) {
            scanf("%d", inputs + i);
        }
        while (true) {
            A = P = 0;
            for (int i = 0; i < N; i++) {
                scanf("%d", guess + i); 
                if (inputs[i] == guess[i]) A++;
            }
            if (guess[0] == 0) break;
            int c1, c2;
            for (int i = 1; i < 10; i++) {
                c1 = c2 = 0;
                for (int j = 0; j < N; j++) {
                    if (inputs[j] == i) c1++;
                    if (guess[j] == i) c2++;
                }
                P += c1 < c2 ? c1 : c2;
            }
            
            printf("    (%d,%d)\n", A, P-A);
        }
        
    }
    
    return 0;
} 
