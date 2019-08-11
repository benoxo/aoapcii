#include <cstdio>
#include <cstring>

int main489() {
    #ifdef LOCAL
    freopen("489.in", "r", stdin);
    freopen("489.out", "w", stdout);
    #endif // LOCAL

    char a[250], b[250];
    bool ca[26];    // true if need guess
    int cb[26];     // true if have choosed the char
    int left;               // num of chars unguessed

    int round;
    while (scanf("%d", &round) != EOF && round != -1) {
        scanf("%s\n", a);
        scanf("%s\n", b);

        memset(ca, false, sizeof(ca));
        memset(cb, false, sizeof(ca));
        left = 0;
        for (char* t = a; *t != '\0'; t++) {
            int c_idx = *t-'a';
            if (!ca[c_idx]) left++;     // the num of unqiue chars in a
            ca[c_idx] = true;
        }

        int chance = 7;
        for (char* t = b; *t != '\0'; t++) {
            if(left < 1) break;         // if there's no left char to guess ,just break
            int c_idx = *t-'a';
            // if haven't guessed and haven't choosed the char before, lose a chance
            if (!ca[c_idx] && !cb[c_idx]) chance--;
            // if guess right, minus one left char
            if (ca[c_idx]) left--;
            // record the char guessed
            cb[c_idx] = true;
            ca[c_idx] = false;
        }


        printf("Round %d\n", round);
        if (chance < 1) {
            printf("You lose.\n");
        } else if (!left) {
            printf("You win.\n");
        } else {
            printf("You chickened out.\n");
        }
    }

    return 0;
}
