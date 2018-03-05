#include <stdio.h>

int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    int a, left = 1;
    while ((a = getchar()) != EOF) {
        if (a == '\"') {
            if (left) {
                printf("``");
            } else {
                printf("''");
            }
            left = !left;
        } else {
            printf("%c", a);
        }
    }
    return 0;
}
