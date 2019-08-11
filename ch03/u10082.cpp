#include <stdio.h>

char keys[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    int c;
    while ((c = getchar()) != EOF) {
        int i = 0;
        for (; keys[i] && keys[i] != c; i++);
        if (keys[i])
            printf("%c", keys[i-1]);
        else putchar(c);
    }
} 
