#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> 
#include <set>
using namespace std;
typedef long long LL;

const int coeff[] = {2, 3, 5};

int main() {
	priority_queue<LL, vector<LL>, greater<LL> > pq;
	set<LL> s;
	int k = 0;
	LL item;
	pq.push(1);
	s.insert(1);
	
	while (k < 1500) {
		item = pq.top();
		k++;
		pq.pop();
		for (int i = 0; i < 3; i++) {
			int c = coeff[i]; 
			if (!s.count(c*item)) {
				s.insert(c*item);
				pq.push(c*item);
			}
		}
	} 
	
	cout << "The 1500'th ugly number is " << item << "." << endl;
	
	return 0;
} 
