#include <stdio.h>
#include <string.h>

int data[15];
int w, h;
bool cube;
int main() {

    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    int idx = 0, size = 0;
    cube = false;
    memset(data, 0, sizeof(data));
    while (scanf("%d %d", &w, &h) == 2) {
        for (int i = 0; i < size; i++) {
            if (data[i] == w) {
                data[i]++;
            } else {
                data[size++] = w;
            }
            if (data[i] == h) {
                data[i]++;
            } else {
                data[size++] = h;
            }
        }
        if (++idx < 6) continue;
        if (size > 3) cube = false;
        else {
            for (int i = 0; i < size; i++) {
                if (data[i]%4) {
                    cube = false;
                    break;
                }
            }
        }
        
        if (cube) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
        
        idx = 0; size = 0; cube = false;
    }
    return 0;
}

