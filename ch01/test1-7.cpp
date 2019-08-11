#include <stdio.h>

int main() {
    int year;
    scanf("%d", &year);
    if (year % 400 == 0) {
        printf("yes\n");
    } else if (year % 100 && year % 4 == 0) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
