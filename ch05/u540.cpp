#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <string>
using namespace std; 

const int MAXQ = 1010;

map<int, int> TeamOfMem;
queue<int> QofQ;
queue<int> QVec[MAXQ];

void InputMemInfo(int K) {
	for (int i = 0; i < K; i++) {
		int NMem, mem;
		cin >> NMem;
		for (int j = 0; j < NMem; j++) {
			cin >> mem;
			TeamOfMem[mem] = i;
		}
	}
} 

void Enqueue() {
	int mem, team;
	cin >> mem;
	team = TeamOfMem[mem];
	
	if (QVec[team].empty()) {
		QofQ.push(team);
	}
	QVec[team].push(mem);
}

int Dequeue() {
	int mem, team;
	team = QofQ.front();
	
	mem = QVec[team].front();
	QVec[team].pop();
	if (QVec[team].empty()) {
		QofQ.pop();
	}
	return mem;
}

void Simulate() {
	string op;
	while (cin >> op) {
		int mem;
		switch(op[0]) {
			case 'E': Enqueue(); break;
			case 'D': mem = Dequeue(); cout << mem << endl; break;
			case 'S': return;
		}
	}
}

void ClearContainer(int K) {
	TeamOfMem.clear();
	QofQ = queue<int>();
	for (int i = 0; i < K; i++) {
		QVec[i] = queue<int>();
	}
}

int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int K, L;
	L = 1;
	while (cin >> K && K) {
		ClearContainer(K);
		cout << "Scenario #" << L++ << endl;
		InputMemInfo(K);
		Simulate();
		cout << endl;
	}	
	return 0;
} 
