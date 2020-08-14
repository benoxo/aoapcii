#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int maxn = 10010;
const int maxc = 12;
map<string, int> idmap;
int table[maxn][maxc];
int n, m;

int ID(string str) {
	if (!idmap.count(str)) {
		int id = idmap.size();
		idmap[str] = id;
	}
	return idmap[str];
}

void GetDataVec(string s, vector<string>& datavec) {
	int pos = 0;
	for (int i = 0; i <= s.size(); i++) {
		if (i == s.size() || s[i] == ',') {
			datavec.push_back(s.substr(pos, i-pos));
			pos = i+1;
		}
	}
}

void VerifyTable() {
	for (int c1 = 0; c1 < m; c1++) {
		for (int c2 = c1+1; c2 < m; c2++) {
			map<pair<int, int>, int> pairmap;
			for (int r = 0; r < n; r++) {
				int d1 = table[r][c1];
				int d2 = table[r][c2];
				pair<int, int> p = make_pair(d1, d2);
				if (pairmap.count(p)) {
					cout << "NO" << endl;
					cout << pairmap[p]+1 << " " << r+1 << endl;
					cout << c1+1 << " " << c2+1 << endl;
					return;
				} else {
					pairmap[p] = r;
				}
			}
		}
	}
	cout << "YES" << endl;
}

int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif

	string s;
	while (cin >> n >> m) {
		getchar();
		idmap.clear();
		for (int r = 0; r < n; r++) {
			getline(cin, s);
			vector<string> row;
			GetDataVec(s, row);
			for (int c = 0; c < m; c++) {
				int id = ID(row[c]);
				table[r][c] = id;
			}
		}
		VerifyTable();
	}

	return 0;
}

