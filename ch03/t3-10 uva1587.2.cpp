#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pallet {
    int H, W;   // H存储的是较长的一条边，W是较短的
    bool operator < (const Pallet b) const {
        if (H != b.H) return H < b.H;
        return W < b.W;
    }
    bool operator == (const Pallet b) {
        return H == b.H && W == b.W;
    }
} P[6];

/*
  没有写出只用数组的程序（判断比较复杂），反而使用排序后会极易编写
  */
int main() {
    #ifdef LOCAL
    freopen("3-10.in", "r", stdin);
    #endif

    int flag, h, w;

    while (scanf("%d %d", &h, &w) == 2) {
        flag = false;

        P[0].H = max(h, w);
        P[0].W = min(h, w);
        for (int i= 0; i < 5; i++) {
            scanf("%d %d", &h, &w);
            P[i+1].H = max(h, w);
            P[i+1].W = min(h, w);
        }

        sort(P, P+6);

        // 这里需要说明的是排序后边与边之间的对应关系就只剩下面一种
        if (P[0] == P[1] && P[2] == P[3] && P[4] == P[5])
        if (P[0].W == P[2].W && P[2].H == P[4].H && P[4].W == P[0].H)
        flag = true;

        if (flag) printf("POSSIBLE\n");
        else      printf("IMPOSSIBLE\n");
    }
    return 0;
}
