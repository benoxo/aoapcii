#include <stdio.h>
#include <string.h>

/* At the end of input, you should put a more charater of '\n', 
   if you dont, you will get a presentation error*/

int cycles[1000];
int occur[30000];
int main() {

    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    int x, y, len, start; // 分别为两个操作数，结果长度，循环数列起始位置 
    while (scanf("%d %d", &x, &y) == 2) {
        len = 0;
        cycles[len++] = x/y;
        memset(occur, 0, sizeof(occur));
        int d = (x%y)*10;
        while (!occur[d]) {
            occur[d] = len;
            cycles[len++] = d/y;
            d = (d%y)*10;
        }
        start = occur[d];
        
        printf("%d/%d = %d.", x, y, cycles[0]);
        int i;
        for (i = 1; i < len && i < 51; i++) {
            if (i == start) printf("(");
            printf("%d", cycles[i]);
        }
        if (i == 51) {
            printf("...)\n");
        } else {
            printf(")\n");
        }
        printf("   %d = number of digits in repeating cycle\n\n", len-start);
    }
    
    return 0;
}
