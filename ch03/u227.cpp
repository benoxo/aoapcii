#include <stdio.h>
#include <string.h>
#include <ctype.h>

char square[5][5];
char seq[100];
int x, y, kase;
bool wrong, inputover;

void M_Up();
void M_Down();
void M_Left();
void M_Right();
int main() {
    
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    kase = 1;
    while (true) {
        int pos = 0;
        char c;
        while (scanf("%c", &c) == 1 && pos < 25) {
            if (c == 'Z') {
                inputover = true;
                break;
            }
            if (isalpha(c) || c==' ') {
                square[pos/5][pos%5] = c;
                
                if (c == ' ') {
                    x = pos/5;
                    y = pos%5;
                }
                ++pos;
            }
        }
        if (inputover) break;
        
        int len = 0;
        while (scanf("%s", seq+len)) {
            len = strlen(seq);
            if (seq[len-1] == '0') break;
        }
        getchar();
        
        wrong = false;
        for (int i = 0; i < len-1; i++) {
            switch(seq[i]) {
            case 'A': M_Up(); break;
            case 'B': M_Down(); break;
            case 'L': M_Left(); break;
            case 'R': M_Right(); break;
            default: wrong = true;
            }
            if (wrong) {
                break;
            }
        }
        
        if (kase > 1) printf("\n"); 
        printf("Puzzle #%d:\n", kase++);
        if (wrong) {
            printf("This puzzle has no final configuration.\n");
        } else {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (j != 0) printf(" ");
                    printf("%c", square[i][j]);
                }
                printf("\n");
            }
        }
    }
    
    return 0;
}


void M_Up() {
    if (x == 0) {
        wrong = true;
        return;
    }
    square[x][y] = square[x-1][y];
    square[x-1][y] = ' ';
    --x;
}

void M_Down() {
    if (x == 4) {
        wrong = true;
        return;
    }
    square[x][y] = square[x+1][y];
    square[x+1][y] = ' ';
    ++x;
}

void M_Left() {
    if (y == 0) {
        wrong = true;
        return;
    }
    square[x][y] = square[x][y-1];
    square[x][y-1] = ' ';
    --y;
}

void M_Right() {
    if (y == 4) {
        wrong = true;
        return;
    }
    square[x][y] = square[x][y+1];
    square[x][y+1] = ' ';
    ++y;
}
