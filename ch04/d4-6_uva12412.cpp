#include <cstdio>
#include <cstring>

void print_menu() {
    printf("Welcome to Student Performance Management System (SPMS).\n\n\
1 - Add\n\
2 - Remove\n\
3 - Query\n\
4 - Show ranking\n\
5 - Show Statistics\n\
0 - Exit\n");
}

void Add() {

}

void Remove() {

}

void Query() {

}

void ShowRank() {

}

void ShowStatistic() {

}

int main() {
    #ifdef LOCAL
    //freopen("12412.in", "r", stdin);
    //freopen("12412.out", "w", stdout);
    #endif

    for (;;) {
        int choice;
        print_menu();
        scanf("%d", &choice);
        switch(choice) {
        case 0: break;
        case 1: Add(); break;
        case 2: Remove(); break;
        case 3: Query(); break;
        case 4: ShowRank(); break;
        case 5: ShowStatistic(); break;
        default: break;
        }

        if (!choice) break;
    }
    return 0;
}

