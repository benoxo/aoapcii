#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int K, longest, NRow, NColumn;
	string filename;
	vector<string> filelist;
	while (cin >> K) {
		longest = 0;
		filelist.clear();
		for (int i = 0; i < K; i++) {
			cin >> filename;
			filelist.push_back(filename);
			longest = max(longest, (int)filename.size());
		}
		
		NColumn = 62 / (longest+2);
		NRow = K / NColumn;
		if (K % NColumn) NRow++;
		
		sort(filelist.begin(), filelist.end());
		
		for (int i = 0; i < 60; i++) {
			cout << "-";
		}
		cout << endl;
		for (int r = 0; r < NRow; r++) {
			for (int c = 0; c < NColumn; c++) {
				int index = c*NRow + r;
				int next = (c+1)*NRow + r;
				if (index >= K) break;
				filename = filelist[index];
				cout << filename;
				
				int size = filename.size();
				int extra = longest;
				if (next < K ) extra += 2; 
				
				while (size++ < extra) {
					cout << " ";
				}
				
			}
			cout << endl;
		}
	}
	
	return 0;
}

