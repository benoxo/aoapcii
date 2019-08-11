#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pallet {
    int H, W;   // H�洢���ǽϳ���һ���ߣ�W�ǽ϶̵�
    bool operator < (const Pallet b) const {
        if (H != b.H) return H < b.H;
        return W < b.W;
    }
    bool operator == (const Pallet b) {
        return H == b.H && W == b.W;
    }
} P[6];

/*
  û��д��ֻ������ĳ����жϱȽϸ��ӣ�������ʹ�������Ἣ�ױ�д
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

        // ������Ҫ˵���������������֮��Ķ�Ӧ��ϵ��ֻʣ����һ��
        if (P[0] == P[1] && P[2] == P[3] && P[4] == P[5])
        if (P[0].W == P[2].W && P[2].H == P[4].H && P[4].W == P[0].H)
        flag = true;

        if (flag) printf("POSSIBLE\n");
        else      printf("IMPOSSIBLE\n");
    }
    return 0;
}
