#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    bool flag = true;
    if (a+b <= c) flag = false;
    if (b+c <= a) flag = false;
    if (a+c <= b) flag = false;
    
    if (a < b) {
        int t = a;
        a = b;
        b = t;
    }
    if (a < c) {
        int t = a;
        a = c;
        c = t;
    }
    if (flag) {
        if (b*b+c*c == a*a) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    } else {
        printf("not a triangle\n");
    }
    
    return 0;
} 
