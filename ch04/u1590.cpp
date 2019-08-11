#include <cstdio>
#include <cstdlib>
#include <string>

int main() {
	#ifdef LOCAL
	freopen("1590.in", "r", stdin);
	freopen("1590.out", "w", stdout);
	#endif
	
	int N, ips[1010][4];
	while (scanf("%d", &N) == 1) {
	
		for (int i = 0; i < N; i++) {
			scanf("%d.%d.%d.%d", ips[i], ips[i]+1, ips[i]+2, ips[i]+3);
		}
		
		// check the start diff part
		int start = 4, f = 0;
		for (int s = 0; s < 4; s++) {
			for (int i = 0; i < N-1; i++) {
				if (ips[i][s] != ips[i+1][s]) {
					f = 1;
					start = s;
					break;
				}
			}
			if (f) break;
		}

		// change to binary representation
		int bis[1010][8];
		int d;
		for (int i = 0; i < N; i++) {
			d = 128;
			int p = ips[i][start];
			int idx = 0;
			while (d) {
				bis[i][idx] = p/d;
				if (p/d) p -= d;
				idx++;
				d /= 2;
			}
		}
		
		int st, msk = 0, addr = 0;
		// determine the diff bit
		f = 0;
		for (int s = 0; s < 8; s++) {
			for (int i = 0; i < N-1; i++) {
				if (bis[i][s] != bis[i+1][s]) {
					st = s;
					f = 1;
					break;
				}
			}
			if (f) break;
		}
		
		// addr means the ip address only on the diff part
		for (int i = 0; i < 8; i++) {
			if (i < st) addr = addr * 2 + bis[0][i];
			else addr = addr * 2;
		}
		
		// msk means the mask only on the diff part
		for (int i = 0; i < 8; i++) {
			if (i < st) msk = msk * 2 + 1;
			else msk = msk * 2;
		}
		
		for (int i = 0; i < 4; i++) {
			if (i < start) {
				printf("%d", ips[0][i]);
			} else if (i > start) {
				printf("0");
			} else {
				printf("%d", addr);
			}
			if (i < 4-1) printf("."); 
		}
		
		printf("\n");
		
		for (int i = 0; i < 4; i++) {
			if (i < start) {
				printf("255");
			} else if (i > start) {
				printf("0");
			} else {
				printf("%d", msk);
			}
			if (i < 4-1) printf("."); 
		}
		printf("\n");
	}
	return 0;
} 
