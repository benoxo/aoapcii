#include <stdio.h> 

int main() {
    int a, b, c;
    bool test[10];
    for (int i = 123; i < 333; i++) {
        a = i;
        b = 2*a;
        c = 3*a;
        int t = a * 1000000 + b * 1000 + c;
        for (int j = 0; j < 10; j++) test[j] = true;
        while (t && test[t%10]) {
            test[t%10] = false;
            t = t / 10;
        }
        if (t) continue;
        else printf("%d %d %d\n", a, b, c);
    }
    return 0;
}
