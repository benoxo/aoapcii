#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <cctype> 
#include <vector> 
#include <stack>
#include <set>

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

using namespace std;

typedef set<int> Set;
stack<int> s;
map<Set, int> IDCache;
vector<Set> set_vec;

int ID(Set x) {
	if (IDCache.count(x)) return IDCache[x];
	int id = set_vec.size();
	set_vec.push_back(x);
	return IDCache[x] = id;
} 

void PrintTopStackSize() {
	Set topSet = set_vec[s.top()];
	cout << topSet.size() << endl;
}

int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int N, M;
	string op;
	cin >> N;
	while (N--) {
		cin >> M;
		while (M--) {
			cin >> op;
			if (op[0] == 'P') {
				s.push( ID(Set()) );
			} else if (op[0] == 'D') {
				s.push( s.top() );
			} else {
				Set setA = set_vec[ s.top() ]; s.pop();
				Set setB = set_vec[ s.top() ]; s.pop();
				Set setX;
				if (op[0] == 'A') {
					setX = setB;
					setX.insert( ID(setA) );
				} else if (op[0] == 'U') {
					set_union( ALL(setA), ALL(setB), INS(setX) );
				} else if (op[0] == 'I') {
					set_intersection( ALL(setA), ALL(setB), INS(setX) );
				}
				
				s.push( ID(setX) );
			}
			PrintTopStackSize();
		}
		cout << "***" << endl;
	}
	
	return 0;
} 
