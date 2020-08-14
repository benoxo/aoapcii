#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int T, N, data;
	vector<int> seq, zero_seq;
	set< vector<int> > seqs;
	cin >> T;
	while (T--) {
		cin >> N;
		seq.clear();
		for (int i = 0; i < N; i++) {
			cin >> data;
			seq.push_back(data);
		}
		zero_seq.resize(N);
		seqs.clear();
		
		int first, nzeros;
		for (int i = 0; i < 1000; i++) {
			first = seq.front();
			nzeros = 0;
			for (int index = 0; index < seq.size()-1; index++) {
				seq[index] = abs(seq[index] - seq[index+1]);
			}
			seq[seq.size()-1] = abs(seq.back() - first);
			
			if (seq == zero_seq) {
				cout << "ZERO" << endl;
				break;
			} else if (seqs.count(seq)) {
				cout << "LOOP" << endl;
				break;
			}
			
			seqs.insert(seq);
		}
	} 
	
	return 0;
} 
