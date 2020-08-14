#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define MAXSIZE 30
using namespace std;

vector<int> S[MAXSIZE];
vector<int> pos_vec; // which stack the block in

void InitStack() {
	for (int i = 0; i < MAXSIZE; i++) {
		S[i].push_back(i);
		pos_vec.push_back(i);
	}
}

void ResetPile(int opd) {
	int S_index = pos_vec[opd];
	while (true) {
		int block = S[S_index].back();
		if (block == opd) break;
		
		S[block].push_back(block);
		pos_vec[block] = block;
		S[S_index].pop_back();
	}
}

void Move(int opd1, int opd2) {
	int opd1_pos = pos_vec[opd1];
	int opd2_pos = pos_vec[opd2];
	
	int opd1_index;
	for (opd1_index = 0; opd1_index < S[opd1_pos].size() && S[opd1_pos][opd1_index] != opd1; opd1_index++)
	{}
	
	int idx_after = opd1_index; 
	for (; idx_after < S[opd1_pos].size(); idx_after++) {
		int block = S[opd1_pos][idx_after];
		S[opd2_pos].push_back(block);
		pos_vec[block] = opd2_pos;
	}
	
	S[opd1_pos].resize(opd1_index);
} 

void PrintStackS(int Size) {
	for (int i = 0; i < Size; i++) {
		cout << i << ":";
		for (int j = 0; j < S[i].size(); j++ ) {
			cout << " " << S[i][j];
		}
		cout << endl;
	}
}

int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout); 
	#endif
	
	int N, opd1, opd2;
	string opr1, opr2;
	cin >> N;
	
	InitStack();
	
	while (true) {
		cin >> opr1;
		if (opr1 == "quit") break;
		
		cin >> opd1 >> opr2 >> opd2;
		if ( pos_vec[opd1] == pos_vec[opd2] ) continue;
		
		if (opr1 == "move") {
			ResetPile( opd1 );
		}
		if (opr2 == "onto") {
			ResetPile( opd2 );
		}
		Move(opd1, opd2);
		
	}
	
	PrintStackS(N);
	
	
	return 0;
} 
