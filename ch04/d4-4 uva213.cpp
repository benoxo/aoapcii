#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

char codes[8][1<<8];
int f = 1;

void read_char(char &c) {
    while (scanf("%c", &c) != EOF && (c == '\n' || c == '\r'));
}

void read_codes() {
    char c;
    read_char(codes[1][0]);
    int i = 2;
    for (; i < 8; i++) {
        for (int j = 0; j < (1<<i)-1; j++) {
            c = getchar();
            if (c == EOF) { f = 0; return;}
            if (c == '\n' || c == '\r') return;
            codes[i][j] = c;
        }
    }
}

void read_data(int len, int &data) {
    char k = 0;
    data = 0;
    for (int i = 0; i < len; i++) {
        read_char(k);
        k -= '0';
        data = data*2+k;
    }
}

void read_meta(int bit, int &len, int &meax) {
    char k;
    len = 0;
    meax = 0;
    for (int i = 0; i < bit; i++) {
        read_char(k);
        k -= '0';
        len=len*2+k;
    }
    for (int i = 0; i < len; i++) {
        meax = meax*2+1;
    }
}

int main213() {
    #ifdef LOCAL
    freopen("213.in", "r", stdin);
    freopen("213.out", "w", stdout);
    #endif

    int data, bit, meax;
    while (true) {
        read_codes();
        if (!f) break;
        while (true) {
            read_meta(3, bit, meax);
            if (bit == 0) break;
            do {
                read_data(bit, data);
                if (data == meax) break;
                printf("%c", codes[bit][data]);
            } while (true);
        }

        printf("\n");
    }

    return 0;
}
