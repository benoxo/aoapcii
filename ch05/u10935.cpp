#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int N;
	queue<int> q;
	while (cin >> N && N) {
		for (int i = 0; i < N; i++) {
			q.push(i+1);
		}
		
		cout << "Discarded cards:";
		while (q.size() > 1) {
			cout << " " << q.front();
			q.pop();
			q.push(q.front());
			q.pop();
			if (q.size() > 1) cout << ",";
		}
		cout << endl;
		
		cout << "Remaining card: " << q.front() << endl;
		q.pop();
	}
	
	return 0;
} 
