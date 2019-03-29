#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char maxv[300][100];
int main() {

    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    double mant = 0;
    
    while (scanf("%s", s) == 1 && strlen(s) > 3) {
        int exp = atoi(s+18);
        int nm = 0, ne = 0;
        s[17] = '\0'; 
        double mans = atof(s);
        double m = mans;
        while (m >= 1 || exp > 0) {
            ne++;
            if (m < 1) {
                exp--;
                m *= 10;
            }
            m /= 2;
        }
        m = mans;
        double t = 1.0/2;
        while (m > 0) {
            nm++;
            m -= t;
            t = t/2;
        }
        printf("%d %d\n", nm-1, (int)log2(exp+1));
    }
    return 0;    
}
