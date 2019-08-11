#include <cstdio>
#include <cstdlib>
#include <cmath>

const int MAX = 10;
int n_redpiece, px_black, py_black;
int p_reds[MAX][3];
int removed = -1;

bool MoveGeneral(int &px, int &py, int step) {
	switch(step) {
	case 0: px = px_black-1; py = py_black; break;
	case 1: px = px_black+1; py = py_black; break;
	case 2: px = px_black; py = py_black-1; break;
	case 3: px = px_black; py = py_black+1; break;
	}
	
	if (px > 0 && px < 4 && py > 3 && py < 7) {
		// for (int i = 0; i < )
		return true;
	} else {
		return false;
	}
}

bool CheckGeneral(int idx, int px, int py) {
	if (py == p_reds[idx][2]) {
		// if the two generals are in the same cols
		// for every piece of reds, verify if it is located between the two generals
		for (int j = 0; j < n_redpiece; j++) {
			if (j == idx || p_reds[j][2] != py) continue;
			if (p_reds[j][1] > px && p_reds[j][1] < p_reds[idx][1]) {
				return false;
			}
		}
	} else {
		// if the two generals are not in the same cols 
		return false;
	}
	// if there is no piece 
	return true;
}


bool CheckChariot(int idx, int px, int py) {
	int cx = p_reds[idx][1];
	int cy = p_reds[idx][2];
	if (cx == px) {
		// check if the piece has been removed
		if (py == cy) return false;
		// check if there is any piece located betweent the two pieces
		int miny, maxy;
		if (cy < py) {
			miny = cy; maxy = py;
		} else {
			miny = py; maxy = cy;
		}
		for (int j = 0; j < n_redpiece; j++) {
			if (px == p_reds[j][1] && p_reds[j][2] > miny && p_reds[j][2] < maxy) {
				return false;
			}
		}
		return true;
	} else if (cy == py) {
		// check if there is any piece located betweent the two pieces
		int minx, maxx;
		if (cx < px) {
			minx = cx; maxx = px;
		} else {
			minx = px; maxx = cx;
		}
		for (int j = 0; j < n_redpiece; j++) {
			if (py == p_reds[j][2] && p_reds[j][1] > minx && p_reds[j][1] < maxx) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool CheckHourse(int idx, int px, int py) {
	// check if the pos of black general in the next field aviliable of hourse
	int hx = p_reds[idx][1];
	int hy = p_reds[idx][2];
	
	if (abs(hx - px) == 2 && abs(hy - py) == 1) {
		// check if ¡°hobbling the horse¡¯s leg"
		int tx = (px + hx)/2;
		for (int i = 0; i < n_redpiece; i++) {
			if (tx == p_reds[i][1] && p_reds[i][2] == hy) return false;
		}
		return true;
	} else if (abs(hx - px) == 1 && abs(hy - py) == 2) {
		int ty = (py + hy)/2;
		for (int i = 0; i < n_redpiece; i++) {
			if (ty == p_reds[i][2] && p_reds[i][1] == hx) return false;
		}
		return true;
	} 
	return false;
	
}


bool CheckCannon(int idx, int px, int py) {
	int cx = p_reds[idx][1];
	int cy = p_reds[idx][2];
	if (cx == px) {
		// check if the piece has been removed
		if (py == cy) return false;
		// check if there is any piece located betweent the two pieces
		int miny, maxy, mids = 0;
		if (cy < py) {
			miny = cy; maxy = py;
		} else {
			miny = py; maxy = cy;
		}
		for (int j = 0; j < n_redpiece; j++) {
			if (px == p_reds[j][1] && p_reds[j][2] > miny && p_reds[j][2] < maxy) {
				mids++;
			}
		}
		if (mids == 1) return true;
		else return false;
	} else if (cy == py) {
		// check if there is any piece located betweent the two pieces
		int minx, maxx, mids = 0;
		if (cx < px) {
			minx = cx; maxx = px;
		} else {
			minx = px; maxx = cx;
		}
		for (int j = 0; j < n_redpiece; j++) {
			if (py == p_reds[j][2] && p_reds[j][1] > minx && p_reds[j][1] < maxx) {
				mids++;
			}
		} 
		if (mids == 1) return true;
		else return false;
	}
	return false;
}


bool Checkmate(int px, int py) {
	bool cmate = true;
	for (int i = 0; i < n_redpiece; i++) {
		switch(p_reds[i][0]) {
		case 'G': cmate = CheckGeneral(i, px, py); break;
		case 'R': cmate = CheckChariot(i, px, py); break;
		case 'H': cmate = CheckHourse(i, px, py); break;
		case 'C': cmate = CheckCannon(i, px, py); break; 
		}
		if (cmate) break;
	} 
	return cmate;
}

bool CheckBlackWin(int px, int py) {
	for (int i = 0; i < n_redpiece; i++) {
		if (p_reds[i][0] == 'G') {
			return CheckChariot(i, px, py);
		}
	} 
}

int main() {
	#ifdef LOCAL
	freopen("1589.in", "r", stdin);
	freopen("1589.out", "w", stdout);
	#endif
	
	while (true) {
		scanf("%d %d %d\n", &n_redpiece, &px_black, &py_black);
		if (n_redpiece == 0) break;
		
		for (int i = 0; i < n_redpiece; i++) {
			scanf("%c %d %d\n", p_reds[i], p_reds[i]+1, p_reds[i]+2); 
		}
		
		int next_px, next_py;
		bool cmate = true;
		
		if ( CheckBlackWin(px_black, py_black) ) {
			cmate = false;
		}
		
		for (int i = 0; i < 4; i++) {
			if (!cmate) break;
			if ( !MoveGeneral(next_px, next_py, i) ) continue;
			if ( !Checkmate(next_px, next_py) ) cmate = false;
		}
		
		if (cmate) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		
	}
	
	
	return 0;
}
