#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main1339() {
    #ifdef LOCAL
    freopen("1339.in", "r", stdin);
    #endif // LOCAL

    char a[110], b[110]; // record the two strings
    int ca[26] = {0};
    int cb[26] = {0};  // count of the characters in the strings
    bool can_map;   // if the one string could map into another

    while (scanf("%s\n", a) != EOF) {
        scanf("%s\n", b);

        memset(ca, 0, sizeof(ca));
        memset(cb, 0, sizeof(cb));
        for (char* t = a; *t != '\0'; t++) {
            ca[*t-'A']++;
        }
        for (char* t = b; *t != '\0'; t++) {
            cb[*t-'A']++;
        }

        sort(ca, ca+26);
        sort(cb, cb+26);

        can_map = true;
        for (int i = 0; i < 26; i++) {
            if (ca[i] != cb[i]) {
                can_map = false;
            }
        }
        if (can_map) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
