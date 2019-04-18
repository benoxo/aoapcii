#include <cstdio>
#include <cstring>

const int SEP = 100;
int d[SEP][SEP], d2[SEP][SEP], ans[SEP][SEP], r, c, n, r1, c1, r2, c2, M, m, kase, tars[SEP];
char op1, op2;

void del(char cmd, int m) {
    memcpy(d2, d, sizeof(d));
    if (cmd == 'R') {
        int dr = 1;
        for (int i = 1; i <= r; i++) {
            if (tars[i]) continue;
            for (int j = 1; j <= c; j++) {
                d[dr][j] = d2[i][j];
            }
            dr++;
        }
        r=dr-1;
    } else {
        int dc = 1;
        for (int j = 1; j <= c; j++) {
            if (tars[j]) continue;
            for (int i = 1; i <= r; i++) {
                d[i][dc] = d2[i][j];
            }
            dc++;
        }
        c=dc-1;
    }
}

void ins(char cmd, int m) {
    memcpy(d2, d, sizeof(d));
    if (cmd == 'R') {
        int dr = 1;
        for (int i = 1; i <= r; i++, dr++) {
            if (tars[i]) {
                for (int j = 1; j <= c; j++) {
                    d[dr][j] = 0;
                }
                dr++;
            }

            for (int j = 1; j <= c; j++) {
                d[dr][j] = d2[i][j];
            }

        }
        r=dr-1;
    } else {
        int dc = 1;
        for (int j = 1; j <= c; j++, dc++) {
            if (tars[j]) {
                for (int i = 1; i <= r; i++) {
                    d[i][dc] = 0;
                }
                dc++;
            }

            for (int i = 1; i <= r; i++) {
                d[i][dc] = d2[i][j];
            }

        }
        c=dc-1;
    }
}

void printd() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            printf("%6d ", d[i][j]);
        }
        printf("\n");
    }
}

int main() {
    #ifdef LOCAL
    freopen("512.in", "r", stdin);
    freopen("512.out", "w", stdout);
    #endif

    kase = 1;
    while (scanf("%d%d%d", &r, &c, &n) == 3 && r) {
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                d[i][j] = i*SEP+j;
            }
        }

        for (int i = 0; i < n; i++) {
            getchar();
            scanf("%c", &op1);
            if (op1 == 'E') {
                getchar();
                scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
                int t = d[r1][c1];
                d[r1][c1] = d[r2][c2];
                d[r2][c2] = t;
            } else {
                memset(tars, 0, sizeof(tars));
                scanf("%c", &op2);
                scanf("%d", &M);
                for (int i = 0; i < M; i++) {
                    scanf("%d", &m);
                    tars[m] = 1;
                }
                if (op1 == 'D') del(op2, M);
                else ins(op2, M);
            }
//            else if (op1 == 'I') {
//                scanf("%c", &op2);
//                scanf("%d", &M);
//                for (int i = 0; i < M; i++) {
//                    scanf("%d", &m);
//                    ins(op2, m);
//                }
//            }

            printd();
        }

        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                ans[ d[i][j]/SEP ][ d[i][j]%SEP ] = i*SEP+j;
            }
        }

        if (kase > 1) printf("\n");
        printf("Spreadsheet #%d\n", kase);
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &r1, &c1);
            printf("Cell data in (%d,%d) ", r1, c1);
            if (ans[r1][c1] > 0) {
                printf("moved to (%d,%d)\n", ans[r1][c1]/SEP, ans[r1][c1]%SEP);
            } else {
                printf("GONE\n");
            }
        }
        kase++;
    }
    return 0;
}
