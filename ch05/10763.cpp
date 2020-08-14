#include <cstdio>
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif

	int N;
	map<pair<int, int>, int> candidates;
	while (cin >> N && N) {
		bool ok = true;
		candidates.clear();
		while (N--) {
			int a, b;
			cin >> a >> b;
			pair<int, int> c1(a, b);
			if (candidates.count(c1)) {
				candidates[c1]++;
			} else {
				candidates[c1] = 1;
			}
		}

		auto it = candidates.begin();
		while (it != candidates.end()) {
			pair<int, int> c1 = it->first;
			pair<int, int> c2(c1.second, c1.first);
			if (candidates[c1] != candidates[c2]) {
				ok = false;
				break;
			}
			it++;
		}
		if (ok) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

