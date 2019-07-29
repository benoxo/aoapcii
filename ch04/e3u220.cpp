#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef struct Pos {
	int x, y;
	Pos(int cx, int cy) {
		this->x = cx;
		this->y = cy;
	} 
}position;
int N, board[8][8], nPossible;
char op;
char curPlayer;

// change means if there's any need to actually do the moving step
// and change for true will change the other chesses according to the rule
bool CheckValid(int i, int j, bool change) {
	char oppo;  // the other side
	int row, col;
	bool valid = false;
	oppo = (curPlayer == 'W'? 'B':'W');
	
	if (board[i][j] != '-') return false;
	
	// up
	row = i-1, col = j;
	while (row >= 0 && board[row][col] == oppo) row--;
	if (row >= 0 && row < i-1 && board[row][col] == curPlayer) {
		if (change) for (; row < i; row++) board[row][col] = curPlayer;
		if (change) valid = true;
		else return true;
	}
	
	// down
	row = i+1, col = j;
	while (row < 8 && board[row][col] == oppo) row++;
	if (row < 8 && row > i+1 && board[row][col] == curPlayer) {
		if (change) for (; row > i; row--) board[row][col] = curPlayer;
		if (change) valid = true;
		else return true;
	}
	
	// left
	row = i, col = j-1;
	while (col >= 0 && board[row][col] == oppo) col--;
	if (col >= 0 && col < j-1 && board[row][col] == curPlayer) {
		if (change) for (; col < j; col++) board[row][col] = curPlayer;
		if (change) valid = true;
		else return true;
	}
	
	// right
	row = i, col = j+1;
	while (col >= 0 && board[row][col] == oppo) col++;
	if (col < 8 && col > j+1 && board[row][col] == curPlayer)  {
		if (change) for (; col > j; col--) board[row][col] = curPlayer;
		if (change) valid = true;
		else return true;
	}
	
	// up-left
	row = i-1, col = j-1;
	while (row >= 0 && col >= 0 && board[row][col] == oppo) { row--; col--;}
	if (row >= 0 && row < i-1 && col >= 0 && col < j-1 && board[row][col] == curPlayer)  {
		if (change) for (; row < i, col < j; row++, col++) board[row][col] = curPlayer;
		if (change) valid = true;
		else return true;
	}
	
	// up-right
	row = i-1, col = j+1;
	while (row >= 0 && col < 8 && board[row][col] == oppo) { row--; col++;}
	if (row >= 0 && row < i-1 && col > j+1 && col < 8 && board[row][col] == curPlayer) {
		if (change) for (; row < i, col > j; row++, col--) board[row][col] = curPlayer;
		if (change) valid = true;
		else return true;
	}
	
	// down-left
	row = i+1, col = j-1;
	while (row < 8 && col >= 0 && board[row][col] == oppo) { row++; col--;}
	if (row < 8 && row > i+1 && col < j-1 && col >= 0 && board[row][col] == curPlayer) {
		if (change) for (; row > i, col < j; row--, col++) board[row][col] = curPlayer;
		if (change) valid = true;
		else return true;
	}
	
	// down-right
	row = i+1, col = j+1;
	while (row < 8 && col < 8 && board[row][col] == oppo) { row++; col++;}
	if (row < 8 && row > i+1 && col < 8 && col > j+1 && board[row][col] == curPlayer) {
		if (change) for (; row > i, col > j; row--, col--) board[row][col] = curPlayer;
		if (change) valid = true;
		else return true;
	}
	if (change) board[i][j] = curPlayer;
	return valid;
} 

void ListPossible() {
	vector<position> vpossible;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (CheckValid(i, j, false)) {
				vpossible.push_back(Pos(i+1, j+1));
			}
		}
	}
	
	for (int i = 0; i < vpossible.size(); i++) {
		if (i > 0) printf(" ");
		printf("(%d,%d)", vpossible[i].x, vpossible[i].y);
	}
	if (vpossible.size() == 0) printf("No legal move.");
	printf("\n");
}

void Move() {
	char a, b;
	int x, y, nw, nb;
	char oppo; // the other side 
	scanf("%c%c", &a, &b);
	x = a - '1';
	y = b - '1';
	// if the current player has no position to locate the chess
	// then change the turn
	if (!CheckValid(x, y, false)) {
		curPlayer = (curPlayer == 'W' ? 'B': 'W');
	}
	oppo = (curPlayer == 'W'? 'B':'W');
	// actual move
	CheckValid(x, y, true);
	
	// calculate the number
	nw = nb = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == 'W') nw++;
			if (board[i][j] == 'B') nb++;
		}
	}
	
	printf("Black - %2d White - %2d\n", nb, nw);
	curPlayer = oppo;
}

void QuitPrint() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

int main() {
	#ifdef LOCAL
	freopen("220.in", "r", stdin);
	freopen("220.out", "w", stdout);
	#endif
	scanf("%d\n", &N);
	for (int n = 0; n < N; n++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%c", &board[i][j]); 
			}
			getchar();
		}
		
		scanf("%c", &curPlayer);
		while (scanf("\n%c", &op) == 1) {
			switch(op) {
			case 'L': ListPossible(); break;
			case 'M': Move(); break;
			case 'Q': QuitPrint(); break;
			} 
			if (op == 'Q') break;
		} 
		getchar();
		if (n < N-1) printf("\n");
		
	}
	return 0;
} 
