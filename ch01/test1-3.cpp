#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n%2) {
        printf("%d", (1+n/2)*n);
    } else {
        printf("%d", (n+1)*n/2);
    }
    
    return 0;
}
