#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct {
    int H, W;
} Pallet[6], Q[3];

int main1587() {
    #ifdef LOCAL
    freopen("3-10.in", "r", stdin);
    #endif

    int pair[6];
    int flag, h, w, s;

    while (scanf("%d %d", &h, &w) == 2) {
        flag = true;
        memset(pair, 0, sizeof(pair));
        s = 0;

        Pallet[0].H = max(h, w);
        Pallet[0].W = min(h, w);
        for (int i= 0; i < 5; i++) {
            scanf("%d %d", &h, &w);
            Pallet[i+1].H = max(h, w);
            Pallet[i+1].W = min(h, w);
        }

        for (int i = 0; i < 6; i++) {
            if (pair[i] != 0) continue;
            for (int j = i+1; j < 6; j++) {
                if (pair[j] != 0) continue;
                if (Pallet[i].H == Pallet[j].H && Pallet[i].W == Pallet[j].W) {
                    pair[i] = pair[j] = 1;
                    Q[s++] = Pallet[i];
                }
            }
        }

        for (int i = 0; i < 6; i++) {
            if (pair[i] == 0) {
                flag = false;
            }
        }

        if (flag) {
            if (Q[0].H == Q[1].H && Q[1].W == Q[2].H && Q[2].W == Q[0].W);
            else if (Q[0].H == Q[1].W && Q[1].H == Q[2].H && Q[2].W == Q[0].W);
            else if (Q[0].H == Q[1].H && Q[1].W == Q[2].W && Q[2].H == Q[0].W);
            else if (Q[0].W == Q[1].H && Q[1].W == Q[2].W && Q[2].H == Q[0].H);
            else if (Q[0].W == Q[1].W && Q[1].H == Q[2].H && Q[2].W == Q[0].H);
            else if (Q[0].W == Q[1].W && Q[1].H == Q[2].W && Q[2].H == Q[0].H);
            else
            flag = false;
        }

        if (flag) printf("POSSIBLE\n");
        else      printf("IMPOSSIBLE\n");
    }

    return 0;
}
