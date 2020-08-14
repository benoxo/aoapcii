#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout); 
	#endif
	
	int N, Q, x, Kase;
	vector<int> marbles;
	Kase = 1;
	while (scanf("%d%d", &N, &Q) == 2 && N > 0) {
		marbles.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> marbles[i];
		}
		sort(marbles.begin(), marbles.end());
		
		printf("CASE# %d:\n", Kase);
		while (Q--) {
			scanf("%d", &x);
			auto p = lower_bound(marbles.begin(), marbles.end(), x);
			if (*p == x) {
				printf("%d found at %d\n", x, p - marbles.begin() + 1);
			} else {
				printf("%d not found\n", x);
			}
		}
		Kase++;
	}
	
	return 0;
} 
