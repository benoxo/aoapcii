#include <cstdio>
#include <cstring>

int que[50];    // 1 means there is a people
int N;          // total amount of persons

/// go throgh the circle
/// @param pos the start position
/// @param dis the distance to go
/// @param dir the direction: 1 means clockwise, -1 means counter-clockwise
/// @return the position of the people selected
int step(int pos, int dis, int dir) {
    int p, v;      // p means the current position, v means num of peoples go passby
    for (p = pos-1, v = 0; v < dis; ) {
        if (que[p]) v++;    //
        if (v < dis) {
            p = (p+N-dir) % N;
        }
    }
    return p+1;
}

int main() {
    #ifdef LOCAL
    freopen("133.in", "r", stdin);
    freopen("133.out", "w", stdout);
    #endif // LOCAL

    int m, k;
    int p1, p2;
    while (scanf("%d %d %d", &N, &m, &k) != EOF && N != 0) {
        memset(que, 1, sizeof(que));
        p1 = 1;
        p2 = N;
        for (int i = 0; i < N;) {
            p1 = step(p1, m, -1);
            p2 = step(p2, k, 1);
            if (p1 != p2) {
                que[p1-1] = que[p2-1] = 0;
                printf("%3d%3d", p1, p2);
                i+=2;
            } else {
                que[p1-1] = 0;
                printf("%3d", p1);
                i+=1;
            }
            if (i < N) printf(",");
        }
        printf("\n");
    }



    return 0;
}
