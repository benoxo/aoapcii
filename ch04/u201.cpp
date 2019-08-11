#include <cstdio>
#include <cstring>
#include <cstdlib>

int n, m, hboard[10][10], vboard[10][10];

int main() {
	#ifdef LOCAL
	freopen("201.in", "r", stdin);
	freopen("201.out", "w", stdout); 
	#endif
	
	char orien;
	int px, py, np;
	np = 1;
	
	while (scanf("%d%d\n", &n, &m) == 2) {
		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				hboard[i][j] = vboard[i][j] = 0;
			}
		}
		
		for (int i = 0; i < m; i++) {
			scanf("%c %d %d\n", &orien, &px, &py);
			if (orien == 'H') hboard[px-1][py-1] = 1;
			else vboard[px-1][py-1] = 1;
		}
		
		if (np > 1) {
			printf("\n**********************************\n\n");
		}
		printf("Problem #%d\n\n", np);
		int printed = 0;
		// search for the square which size is size
		for (int size = 1; size < n; size++) {
			int count = 0;
			// cx cy means the left top corner of the square
			for (int cx = 0; cx < n-size; cx++) {
				for (int cy = 0; cy < n-size; cy++) {
					
					int connect = true;
					
					// horizontal line:
					for (int i = cy; i < size+cy; i++) {
						if (!hboard[cx][i] || !hboard[cx+size][i]) {
							connect = false;
							break; 
						}
					}
					
					// vertical line
					for (int i = cx; connect && i < size+cx; i++) {
						if (!vboard[cy][i] || !vboard[cy+size][i]) {
							connect = false;
							break;
						}
					}
					
					if (connect) count++;
				}
			}
			
			
			if (count > 0) {
				printf("%d square (s) of size %d\n", count, size);
				printed++;
			}
		}
		if (!printed) {
			printf("No completed squares can be found.\n");
		}
		np++;
	}
	return 0;
}
