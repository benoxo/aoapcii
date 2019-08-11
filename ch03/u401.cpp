#include <stdio.h>
#include <string.h>

const char mirror[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* outs[] = {" -- is not a palindrome.", " -- is a regular palindrome.", 
                " -- is a mirrored string.", " -- is a mirrored palindrome."};
                
int r(int c) {
    if (c >= 'A') return mirror[c - 'A'];
    else return mirror[c - '0' + 25];
}

int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    char in[30];
    bool p, m;
    while (scanf("%s", in) == 1) {
        int len = strlen(in);
        p = true, m = true;
        for (int i = 0; i < (len+1)/2; i++) {   // 这里的判断是(len+1)/2而不是len/2是为了判断镜像 
            if (in[i] != in[len-1-i]) p = false;
            if (r(in[i]) != in[len-1-i]) m = false;
        }
        printf("%s%s\n\n", in, outs[m*2+p]);
    }
    
    return 0;
} 
