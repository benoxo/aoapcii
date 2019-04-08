#include <cstdio>
#include <cstring>

char codes[8][1<<8];

char read_char() {
    char c;
    while (true) {
        c = getchar();
        if (c != '\n' && c != '\r') return c;
    }
}

bool read_codes() {
    char c;
    codes[1][0] = read_char();
    for (int len = 2; len < 8; len++) {
        for (int i = 0; i < (1<<len)-1; i++) {
            c = getchar();
            if (c == EOF) return false;
            if (c == '\n' || c == '\r') return true;
            codes[len][i] = c;
        }
    }
    return true;
}

int read_data(int len) {
    int data = 0;
    while (len--) {
        data = data*2 + read_char() - '0';
    }
    return data;
}

int main213() {
    #ifdef LOCAL
    freopen("213.in", "r", stdin);
    freopen("213.out", "w", stdout);
    #endif

    int len, data;
    while (read_codes()) {
        while (true) {
            len = read_data(3);
            if (len == 0) break;
            while (true) {
                read_data(len, data);
                if (data == (1 << len)-1) break;
                putchar(codes[bit][data]);
            }
        }

        printf("\n");
    }

    return 0;
}
